n = int(float(input()))

a = []
b = []

for i in range(0, n):
    elem = int(float(input()))
    a.append(elem)
for i in range(0, n):
    elem = int(float(input()))
    b.append(elem)
possible1 = []
possible2 = []
if a[1] == 1 and b[1] == 0:
    possible1.append('C')
    possible1[1].append('C')
    possible2.append('B')
    possible2.append('B')
elif a[1] == 0 and b[1] == 1:
    possible1.append('B')
    possible1.append('C')
    possible2.append('C')
    possible1.append('B')
elif a[1] == 1 and b[1] == 1:
    possible1.append('C')
    possible1.append('B')
    possible2.append('B')
    possible2.append('B')
possiblesum1 = (0, 0)
possiblesum2 = (0, 0)
for i in range(0,2):
    if possible[i] == 'C':
        possiblesum1[0]+=1
    elif possible1[i] == 'B':
        possiblesum1[1]+=1
    if possible2[i] == 'C':
        possiblesum2[0]+=1
    else:
        possiblesum2[1]+=1
for i in range(2, n):
    if possiblesum1.first == a[i] and possiblesum1.second == b[i]:
        possible1[i] = 'C'
        possiblesum1[0] += 1
            
    else:
        possible1[i] = 'B'
        possiblesum1[1] += 1
        
    if possiblesum2.first == a[i] and possiblesum2.second == b[i]:
        possible2[i] = 'C'
        possiblesum2[0] += 1
    else:
        possiblesum2[1] += 1
        possible2[i] = 'B'
bulls1 = 0
bulls2 = 0
cows1 = 0   
cows2 = 0
for i in range(0, n):
    if possible[i] == 'C':
        cows1+=1
    else:
        bulls1+=1
    if possible2[i] == 'C':
        cows2+=1
    else:
        bulls2+=1
if bulls1+cows1 == n:
    for char in possible1:
        print(char)
else:
    for char in possible2:
        print(char)
exit()


