n = int(input())
a = []
for i in range(n):
	a.append(int(input()))
for i in range(n - 1):
	if cursum + a[i] > a[i+1]:
		print(cursum + a[i] + 1)
		exit(0)