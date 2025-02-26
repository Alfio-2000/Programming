# Write a script that it can replace the multiplication tables

print("Hello, enter a number and I'll show you the multiplication tables of it")

LENGHT_MULTI_TABLE=10 #This is che size of multiplication tables
number=int(input("Enter a number: "))
for i in range(LENGHT_MULTI_TABLE+1): #I'm summing for 1, because the cycle starting to 0 until 9
    result=number*i
    print(f"{number}x{i}={result}")
