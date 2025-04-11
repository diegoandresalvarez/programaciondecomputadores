; Código en lenguaje ensamblador generado con Claude para traduciendo
; el programa de lenguaje C para un procesador Intel Core i7-4779K
;
; Compile con:
; nasm -f elf64 02_tiempo_calculo.asm -o 02_tiempo_calculo_asm.o
; gcc -march=haswell -O3 02_tiempo_calculo_asm.o -o 02_tiempo_calculo_asm -no-pie

section .data
    fmt_result      db "ln(2) = %g", 10, 0
    fmt_time        db "El cálculo se realizó en %g segundos.", 10, 0

section .bss
    tic     resq 2      ; struct timeval para inicio (tv_sec, tv_usec)
    toc     resq 2      ; struct timeval para fin

section .text
    global main
    extern printf
    extern gettimeofday

main:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 64             ; Espacio para variables locales y alineamiento

    ; gettimeofday(&tic, NULL)
    lea     rdi, [rel tic]
    xor     rsi, rsi
    call    gettimeofday

    ; Inicialización de acumuladores vectoriales
    vxorpd  ymm0, ymm0, ymm0    ; ymm0 = 0.0 (acumulador final)

    ; Contadores e iteradores
    xor     rcx, rcx            ; i = 0
    mov     r9, 100000000       ; límite del bucle

    ; Carga de constantes vectoriales
    vmovapd ymm10, [rel const_1_vector]  ; [1.0, 1.0, 1.0, 1.0]
    vmovapd ymm11, [rel const_2_vector]  ; [2.0, 2.0, 2.0, 2.0]
    vmovapd ymm12, [rel idx_vector]      ; [0.0, 1.0, 2.0, 3.0]

    ; Prefetch para optimizar caché
    prefetcht0 [rel const_1_vector]
    prefetcht0 [rel const_2_vector]
    prefetcht0 [rel idx_vector]

; Loop principal procesando 4 elementos por iteración con AVX
loop_start:
    ; Convertir contador actual a vector
    vcvtsi2sd xmm1, xmm1, rcx
    vbroadcastsd ymm1, xmm1     ; ymm1 = [i, i, i, i]

    ; Crear índices vectoriales [i, i+1, i+2, i+3]
    vaddpd  ymm2, ymm1, ymm12   ; ymm2 = [i, i+1, i+2, i+3]

    ; Calcular 2*i para cada elemento
    vmulpd  ymm3, ymm2, ymm11   ; ymm3 = [2i, 2(i+1), 2(i+2), 2(i+3)]

    ; 2*i + 1 para cada elemento
    vaddpd  ymm4, ymm3, ymm10   ; ymm4 = [2i+1, 2(i+1)+1, 2(i+2)+1, 2(i+3)+1]

    ; 2*i + 2 para cada elemento
    vaddpd  ymm5, ymm3, ymm11   ; ymm5 = [2i+2, 2(i+1)+2, 2(i+2)+2, 2(i+3)+2]

    ; Calcular las divisiones 1/(2i+1) y 1/(2i+2)
    vdivpd  ymm6, ymm10, ymm4   ; ymm6 = [1/(2i+1), 1/(2(i+1)+1), ...]
    vdivpd  ymm7, ymm10, ymm5   ; ymm7 = [1/(2i+2), 1/(2(i+1)+2), ...]

    ; Restar para obtener 1/(2i+1) - 1/(2i+2)
    vsubpd  ymm8, ymm6, ymm7    ; ymm8 = [1/(2i+1) - 1/(2i+2), ...]

    ; Acumular resultado en acumulador final
    vaddpd  ymm0, ymm0, ymm8

    ; Avance e iteración
    add     rcx, 4              ; Avanzamos de 4 en 4
    cmp     rcx, r9
    jl      loop_start

    ; Sumamos horizontalmente las 4 partes del acumulador vectorial
    vextractf128 xmm1, ymm0, 1  ; Extraer los dos valores superiores
    vaddpd  xmm0, xmm0, xmm1    ; Sumar alto+bajo
    vhaddpd xmm0, xmm0, xmm0    ; Suma horizontal final

    ; Guardar resultado para uso posterior
    vmovsd  [rsp+16], xmm0

    ; gettimeofday(&toc, NULL)
    lea     rdi, [rel toc]
    xor     rsi, rsi
    call    gettimeofday

    ; Cálculo de tiempo transcurrido
    mov     rax, [rel toc]
    sub     rax, [rel tic]
    vcvtsi2sd xmm0, xmm0, rax

    mov     rax, [rel toc+8]
    sub     rax, [rel tic+8]
    vcvtsi2sd xmm1, xmm1, rax

    vdivsd  xmm1, xmm1, [rel million]
    vaddsd  xmm0, xmm0, xmm1
    vmovsd  [rsp+8], xmm0

    ; Imprimir resultados
    lea     rdi, [rel fmt_result]
    vmovsd  xmm0, [rsp+16]
    mov     al, 1
    call    printf

    lea     rdi, [rel fmt_time]
    vmovsd  xmm0, [rsp+8]
    mov     al, 1
    call    printf

    ; Liberar estado AVX
    vzeroall

    ; Retornar
    xor     eax, eax
    leave
    ret

section .rodata
    align 32  ; Alineación para acceso óptimo de AVX
    const_1_vector:  dq 1.0, 1.0, 1.0, 1.0
    const_2_vector:  dq 2.0, 2.0, 2.0, 2.0
    idx_vector:      dq 0.0, 1.0, 2.0, 3.0
    million:         dq 1000000.0
