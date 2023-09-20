def create_set(expression, start, end) :
    s = set()
    for x in range(start, end + 1):
            s.add(expression(x))
    return s

expression1 = lambda x: int((3*x-2)/2) if x != 0 else None
expression2 = lambda x: int((7*x-2)/3) if x != 0 else None
expression3 = lambda x: int((x**2-9)/(x-3)) if x != 3 else None


setA = create_set(expression1, -8, 12)
setB = create_set(expression2, -7, 14)
setC = create_set(expression3, -7, 12)


U = set()

for i in range(-10, 16):
      U.add(i)

A = setA & U
B = setB & U
C = setC & U


# Calcula las partes individuales de la expresión
parte1 = ((C & B) ^ ((B - D) & C))
parte2 = ((C - A) | (A & B))
parte3 = (U ^ ((A - B) & C))

# Calcula la expresión completa
resultado = parte1 | parte2 - parte3

print("Resultado:", resultado)




