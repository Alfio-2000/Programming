# Write a script that it can say if a number is positive and even

number=int(input("Enter a number: "))

if number%2==0 and number>=0: 
    print(f"The number {number} is even and positive")

else: 
    print(f"The number {number} is not even and positive")

