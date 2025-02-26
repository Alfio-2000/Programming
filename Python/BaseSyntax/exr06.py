# Write a script that it can say if an user is an adult or an underage

age= int(input("Enter your age: "))

ADULT_AGE= 18 # In Italy this one is the adult age. Change it if you come from another country

if age>=ADULT_AGE: 
    print("You are an adult. You can drink alchol.")

else: 
    print("You are an underage. You can't dring alchol.")
