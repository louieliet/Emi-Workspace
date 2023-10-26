import cv2
import numpy as np
import matplotlib.pyplot as plt


img = cv2.imread('Torre.jpg')

R1 = img[:,:, 0]
G1 = img[:,:, 1]
B1 = img[:,:,2]

x = img[0]
y = img[1]

primertercio = round(x/3)
segundotercio = round(x*2/3)



G1[:, round(x/3)] = 0
B1[:, round(x/3)] = 0

R1[:, (x/3):(x*2/3)] = 255
G1[:, (x/3):(x*2/3)] = 255
B1[:, (x/3):(x*2/3)] = 255

B1[:, (x*2/3):] = 0
G1[:, (x*2/3):] = 0

result = cv2.merge([R1,B1,G1])

plt.imshow(result)
plt.show()