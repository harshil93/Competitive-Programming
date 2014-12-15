import bisect
import sys

t = int(raw_input());
fact = [];
fact.append(0);
val = 1;

def factorial(n):
    if n==0:
        return 1;
    val = 1;
    for x in xrange(1,n+1):
        val = val*x;
    return val;

for x in xrange(1,65):
    r = x/2;
    t_= factorial(x)/(factorial(r)*factorial(x - r));
    fact.append(t_);
    print x 
    print "@"
    print t_

def find_gt(a, x):
    i = bisect.bisect_right(a, x)
    if a[i-1] == x:
    	return i-1;
    if i != len(a):
        return i
    raise ValueError

while t>0:
	n = int(raw_input());
	ans = find_gt(fact,n);
	print ans;
	t = t - 1;
		

