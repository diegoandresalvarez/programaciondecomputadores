def factorial(n):
    # Recuerde que math.factorial() existe
    if n<0:
        return None
    if n==0 or n==1:
        return 1
    else:
        return n*factorial(n-1)
    
print('4! =', factorial(4))
