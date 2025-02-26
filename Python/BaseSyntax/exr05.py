# Write a script that it can calculate the rectangle's area.
# This script need to ask the base and the high of thi rectangle by keyboard. 

base= int(input("Enter the rectangle's base: "))
high= int(input("Enter the rectangle's high: "))

area= float(base*high) #In this statement i need to do an explicit casting, beacuse the area is float (1)

print(f"The rectangle's area is: {area:.2f}")




# (1): This way is necessary for example to calculate triangle's area.
