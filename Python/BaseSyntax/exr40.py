#To use f-strings to obtain "The binary number of keyboard's number is: {binary number}"

number=int(input("Enter a number: "))
string=f"The binary number of {number} is {bin(number)}" #1
print(string)

#1: bin(number) convert a generic number in binary language. 