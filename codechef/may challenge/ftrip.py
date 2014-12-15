def nCk(n,k):
	if k==0:
		return 1
	return fact(n)/(fact(k)*fact(n-k))
def fact(n):
	if n==0:
		return 1
	temp =1
	for x in xrange(1,n+1):
		temp= temp*x
	return temp

t = raw_input()
t = int(t)
in_arr = []
num =0;
for x in range(0,t,1):
	in_arr.append(raw_input())
	in_arr[x]= in_arr[x].split(" ")

for x in xrange(0,t):
	num=0
	s= int(in_arr[x][0])
	n= int(in_arr[x][1])
	m= int(in_arr[x][2])
	k= int(in_arr[x][3])

	if n-1<k:
		ans = float(0)
	else:
		i=0
		while k+i<m and k+i<n:
			num = num + nCk(m-1,k+i) * nCk(s-m,n-k-i-1)
			i=i+1

		ans = float(num)/float(nCk(s-1,n-1))

	if ans>1:
		print "%.6f"%float(1)
	else:
		print "%.6f"%ans
