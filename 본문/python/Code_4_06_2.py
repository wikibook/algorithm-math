N = int(input())

a = [ None ] * (N + 1)
a[1], a[2] = 1, 1
for i in range(3, N + 1):
	a[i] = (a[i - 1] + a[i - 2]) % 1000000007

print(a[N] % 1000000007)