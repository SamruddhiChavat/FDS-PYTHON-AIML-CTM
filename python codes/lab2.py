'''a=int(input("Enter num 1"))
b=int(input("Enter num 2"))
c=int(input("ENter num 3"))

if a>b and a>c:
    print(a, "is greatest")
elif b>a and b>c:
    print(b,"is greatest")
else:
    print(c,"is greatest")'''

    

 
def large(a,b,c):
    if (a>c) and (a>b):
        return a
    if (b>c) and (b>c):
        return b
    else :
      return c
    
a=int(input("num1:"))
b=int(input("num2:"))
c=int(input("num3:"))
print("largest num is:",large(a,b,c))

 
 