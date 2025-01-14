# Write a script that it can verify if a positive and integer number entered by an user is a perfect number. 
# Remember that a number is perfect if it's egual to dividers' sum. 

number= int(input("Enter a number: "))
dividers_sum=0
for i in range(1,number):
    if number%i==0:
        dividers_sum+=i
        print(f"{i} is a divider of {number}")
if dividers_sum==number:
    print(f"{number} is a perfect number.")
else:
    print(f"{number} isn't a perfect number.")
