n=int(input())
m=int(input())

while(n%m!=0):
    n=n%m
    temp=n
    n=m
    m=temp

print("GCD is:",m)
