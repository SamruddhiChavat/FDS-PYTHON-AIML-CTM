#write a python program that accepts the length of 3 sides of a triangle,the program should indicate whether or not the triangle is right angled using function with exception handling
'''import math

def rightangle(diag,base,height):
    if(pow(diag,2)==pow(base,2)+pow(height,2)):
        print("The given triangle is right angled")
    else:
        print("It is not a right angled triangle")

diag=int(input("Enter the length of diagonal"))
base=int(input("Enter the length of base"))
height=int(input("Enter the length of height"))

print("Diagonal length: ",diag)
print("Base length: ",base)
print("Height length: ",height)


try:
    if(diag==0 or base==0 or height ==0 ):
        raise Exception
except :
    print("Invalid input")
else :  
    rightangle(diag,base,height)

'''
def tri(a,b,c):
 if(a*a+b*b==c*c):
    print("right angle")
 else:
   print("no r angle")

a=int (input("enter side a:"))
b=int (input("enter side b:"))
c=int (input("enter side c:"))

try:
  if (a==0 or b==0 or c==0):
    raise Exception
except:
  print("error")
else:
  tri(a,b,c)
  