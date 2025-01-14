#Write a script that it can calculate number's factorial. 

number=int(input("Enter a number: "))
factorial=1 # In math doesn't exsist 0 such as factorial. So, we can start it from 1 
if number!=0:
    for i in range(1,number+1):  # In this way, we're starting from 1, instead 0
        factorial*=i
    print(f"The factorial ({number}!) is: {factorial}")
else:
    print("You entered 0 and 0!=1 by Math's definition.")