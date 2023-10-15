N = 100
A = [0]*101
for k in range(1,N):
    for n in range(1,k+1):
        A[n]+= n/((k+1)*(k+2)*(N-k))

idx = 0
maax = 0
for n in range(1,N):
   if (maax < A[n]):
       idx = n
       maax = A[n]

import random

a = []
for i in range(1,N+1):
    a.append(i)

p = [0]*101

iter = 10000
for _ in range(iter):
    random.shuffle(a)
    for n in range(1,N):
        m = a[0]
        for i in range(1,n):
            m = max(m, a[i])
        j = n
        while (j<N and a[j]< m):
            j+=1
        if (j != N and a[j]==N):
            p[n] += 1

i = 1
for n in range(1,N):
    p[n] = p[n]/iter
    if (p[i] < p[n]):
        i = n

print(i)
print(p[i])

            
        
