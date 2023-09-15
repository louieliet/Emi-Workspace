P = [1, 0, 3, 2, 0, 8]  
lengthP = len(P)


last_num = -1


for indice in range(lengthP):
    if P[indice] != 0:
        last_num += 1
        P[indice], P[last_num] = P[last_num], P[indice]

print(P)
