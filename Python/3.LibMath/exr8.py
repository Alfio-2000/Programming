#Calculate the quadratic equation's solutions

import math

print("Hi, i can calculate the solutions of thi equation: ax^2 + bx + c=0\n")

#Ask at user to enter equation's parameters
while True:
    string=input("Enter 1° parameter: ")
    a=float(string)
    if a==0:
        print("1° parameter can't be 0! Watch delta's relation!\n")
    else:
        break

string=input("Enter 2° parameter: ")
b=float(string)

string=input("Enter 3° parameter: ")
c=float(string)

#Now, i calcolate equation's delta
delta=(b*b)-(4*a*c)

if delta<0: #1
    print("There aren't real solutions.\n")

elif delta==0:
    print("There are two coincident solutions:\n")
    first_x=(-b-math.sqrt(delta))/(2*a)
    print(f"x1=x2={first_x:.2f}\n")

else:
    first_x=(-b-math.sqrt(delta))/(2*a)
    second_x=(-b+math.sqrt(delta))/(2*a)
    print(f"\nThe solutions are: x1={first_x:.2f} and x2={second_x:.2f}\n")

#1: I splitted cases in according to AM.
