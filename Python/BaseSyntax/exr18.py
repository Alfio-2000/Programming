# Write a script that it sums the even numbers starting from 1 until a number is entered by keyboard

number= int(input("Enter a number: "))
sum=0 # This is a counter

for i in range(number):
    if i%2==0: 
        sum+=i
print(f"The total sum of even numbers is: {sum}")