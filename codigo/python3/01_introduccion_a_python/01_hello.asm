section .data
    hello:     db 'Hola a todos!!',10  ; 'Hola a todos!!' + el caracter \n
    helloLen:  equ $-hello             ; Longitud de la cadena 'Hola a todos!!'

section .text
    global _start

_start:
    mov eax,4            ; Llamado al sistema para escribir
    mov ebx,1            ; 1 quiere decir que se escribirá en la pantalla
    mov ecx,hello        ; Se especifica la cadena a escribir y su longitud
    mov edx,helloLen     ;
    int 80h              ; Se llama al kernel

    mov eax,1            ; Se llama al sistema para salir
    mov ebx,0            ; Se sale con código 0 (no error)
    int 80h
