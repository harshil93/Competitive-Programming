import random
def isprime(x):
	x = abs(int(x))
	if x < 2:
		return "Less 2", False
	elif x == 2:
		return True
	elif x % 2 == 0:
		return False
	else:
		for n in range(3, int(x**0.5)+2, 2):
			if x % n == 0:
				return False
		return True

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


input_string = raw_input()
t = int(input_string)
input_array=[]
for x in xrange(0,t ):
	input_array.append(int(raw_input()))

for x in xrange(0,t):
	n = input_array[x];
	d = n
	# print str(n) + "@"
	if n==2:
		print 2
		continue
	while True:
		if isprimer(d,20):
			print d
			break
		else:
			d=d-1
		