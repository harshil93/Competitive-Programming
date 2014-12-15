def sum4(n,m):
	if n==0:
		return 0
	return ((n*(2*n+1)*(n+1)*(3*n*n + 3*n + 1))/30)%m

def sum(a,b,m):
	z1 = sum4(b,m)
	z2 = sum4(a-1,m)
	return (z1 - z2 + m)%m

t = int(raw_input())

while t!=0:
	lt = (raw_input()).split(" ");
	n = int(lt[0])
	m = int(lt[1])
	i = 1;
	ans = 0;
	while i<=n:
		cQ = n/i;
		qM = n/cQ;
		ans = ans +  (cQ*sum(i,qM,m))%m;
		ans = ans%m;
		i = qM + 1;
	print ans
	t = t - 1;
	