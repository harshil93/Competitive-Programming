import random

def isprimer(n,PROB):
	'''returns if the number is prime. Failure rate: 1/4**PROB '''
	if n==2: return True
	s=0
	d=n-1
	while 1&d==0:
		s+=1
		d>>=1
	for i in range(PROB):
		a=random.randint(2,n-1)
		composit=True
		if pow(a,d,n)==1:
			composit=False
		if composit:
			for r in xrange(0,s):
				if pow(a,d*2**r,n)==n-1:
					composit=False
					break
		if composit: return False
	return True

n = int(raw_input())
input_arr_a=[]

for x in xrange(0,n):
	input_arr_a.append((raw_input()).split(" "))

for x in xrange(0,n):
	a = int(input_arr_a[x][0])
	b = int(input_arr_a[x][1])
	if a==1:
		a=a+1
		print 2
		a=a+1
	if a==2:
		print 2
		a=a+1

	for y in range(a,b+1,2):
		if(isprimer(y,10)):
			print y
	print 
