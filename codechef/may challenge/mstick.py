n = raw_input()
n = int(n)

b = raw_input()
b = b.split(" ")

q = int(raw_input())

query_arr=[]
for x in xrange(0,q):
	query_arr.append((raw_input().split(" ")))
print query_arr
