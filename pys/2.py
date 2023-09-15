P = [2,3,4,5,0,1]

wanted_sum = 6


indexnums = []

for i in range(len(P)):
    firstnum = P[i]
    for j in range(i + 1, len(P)):
        secondnum = P[j]

        if(firstnum + secondnum == wanted_sum):
            indexnums.append((firstnum,secondnum))


print(wanted_sum)
print(indexnums)
