# Write a script that it cheks if a year entered by user from keyboard is leap or not.

year=int(input("Enter a year: "))

if (year%400==0) or (year%4==0 and year%100!=0):
    print(f"{year} is a leap year.")
else:
    print(f"{year} isn't a leap year.")
