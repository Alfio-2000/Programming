# Write a script that it asks to user to enter an enterer positive number by keyboard and it generates multiplicative tables until the number

number=int(input("Enter a number: "))

for i in range(1,number+1): # lines' number
    for j in range(1,number+1): # columns's number
        print(i*j, end=' ') # See exr30.py
    print()

