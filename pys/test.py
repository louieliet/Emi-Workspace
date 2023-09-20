import sympy

def fermat_prime(n):
    return 2**(2**n) + 1

# Primeros 7 primos de Fermat
fermat_primes = [fermat_prime(n) for n in range(8)]

# Función para verificar si un número es primo
def is_prime(n):
    return sympy.isprime(n)

# Verificar y mostrar los números primos de Fermat en el intervalo [0, 27]
print("Números primos de Fermat en el intervalo [0, 27]:")
for n in range(28):
    if is_prime(fermat_prime(n)):
        print(f"F({n}) = {fermat_prime(n)}")

# Función para calcular los primeros 7 primos de Mersenne
def mersenne_prime(n):
    return 2**n - 1

# Primeros 7 primos de Mersenne
mersenne_primes = [mersenne_prime(n) for n in range(7)]

# Comparar los primeros 7 primos de Fermat con los primeros 7 primos de Mersenne

for i in range(7):
    if fermat_primes[i] == mersenne_primes[i]:
        print(f"F({i}) = {fermat_primes[i]} es igual a M({i}) = {mersenne_primes[i]}")
    else:
        print(f"F({i}) = {fermat_primes[i]} es diferente de M({i}) = {mersenne_primes[i]}")