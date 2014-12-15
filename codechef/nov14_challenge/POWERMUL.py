


T = int(raw_input())

while T!=0:

	lt = raw_input().split()
	n = int(lt[0])
	m = int(lt[1])
	q = int(lt[2])
	fval = []
	ans = 1
	for x in xrange(0,n+1):
		ans = (ans * pow(x,x,m))%m
		fval.append(ans)

	while q!=0:
		r = int(raw_input())
		print (fval[n] * pow(fval[r],m-2,m) * pow(fval[n-r],m-2,m))%m
		q = q-1
	T = T - 1