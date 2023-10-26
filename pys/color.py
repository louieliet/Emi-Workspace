import cv2
import numpy as np
import matplotlib.pyplot as plt

# Carga la imagen en escala de grises
img = cv2.imread('Torre.jpg')

R1 = img[:,:,0]
G1 = img[:,:,1]
B1 = img[:,:,2]

aux = img[:,:,1]

R1[:,:] = aux
B1[:,:] = aux
G1[:,:] = aux

result = cv2.merge([R1,B1,G1])

coordenadas = np.where(result>= 240)

for i in range(len(coordenadas[0])):
    fila = coordenadas[0][i]
    columna = coordenadas[1][i]
    valor = result[coordenadas[0][i]][coordenadas[1][i]]
    print(f"Coordenada ({fila}, {columna}) - Valor: {valor}")

plt.imshow(result)
plt.show()
