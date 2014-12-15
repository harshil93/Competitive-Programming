t = int(raw_input())

def calc(n):
	res=0
	for x in xrange(0,32):
		if (n & (1<<x))!=0:
			res += pow(10,x)
	return res
			
while t>0:
	k = int(raw_input())
	y = calc(k)
	print pow(2,2*y,1000000007)
	t=t-1