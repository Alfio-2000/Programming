#classificate and Calculate triangle's type surface.

import math

print("I can classificate triangle's type\n")

print("Enter the triangle's triangle:")

while True:#1
    a = float(input("Side a: "))
    b = float(input("Side b: "))
    c = float(input("Side c: "))
    if a<0 or b<0 or c<0:
        print("Error: sides can't be negative!")
    else:
        break

#Now begin the classification

if (a==b==c): #Equilater triangle
    print("\nThe triangle is equilater\n")
    surface=(math.sqrt(3)/4)*a*a
    if surface==0:
        print("The triangle is degenerate: the three vertices are aligned\n")
    else:
        print(f"The surface is: {surface:.2f}\n")

elif (a==b or b==c or a==c): #isosceles triangle
    print("\nThe triangle is isosceles\n")
    #Ask base and height to calculate surface
    b=float(input("Enter the triangle's base:"))
    h=float(input("Enter the triangle's height:"))
    surface=0.5*h*b
    if surface==0:
        print("The triangle is degenerate: the three vertices are aligned\n")
    else:
        print(f"The surface is: {surface:.2f}\n")

else:
    print("\nThe triangle is scalene\n")
    s=0.5*(a+b+c) #semi perimeter
    surface=math.sqrt(s*(s-a)*(s-b)*(s-c)) #Herone's formula
    if surface==0:
        print("The triangle is degenerate: the three vertices are aligned\n")
    else:
        print(f"The surface is: {surface:.2f}\n")

#1: This control is useful necessary to control the numbers sign: if it is negative the number will ask again.
