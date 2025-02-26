# Write a script that can simulate a login system: 
# 1. Ask to user to enter by keyboard an username and a password
# 2. Check if username is "admin" and password is "1234"
# 3. Print "Access allowed" if past conditions are true, instead, if they are false print "Access denied"

BASE_USERNAME="admin"
BASE_PASSWORD= 1234

username=input("Enter an username: ")
password=int(input("Enter a numeric password: "))

if username==BASE_USERNAME and password==BASE_PASSWORD: 
    print("Access allowed")
else: 
    print("Access denied")
