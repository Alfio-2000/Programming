#Write a script that it can print the numbers start 1 to 50, but:
# 1) Print "Fizz" for those number that can be divided by 3
# 2) Print "Buzz" for those number that can be divided by 5
# 3) Print "FizzBuzz" for those number that can be divided by 3 and 5

numbers=int(input("How many number do u want enter? "))
STRING1="Fizz"
STRING2="Buzz"
STRING3="FizzBuzz"
for i in range(1,numbers):
    if (i%3==0) and (i%5==0):
        print(STRING3)
    elif i%3==0:
        print(STRING1)
    elif i%5==0:
        print(STRING2)
    else: 
        print(i)
        
