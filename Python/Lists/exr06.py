# Write a script that it can create a list with the first n numbers' squares
# Use list comprehension to do this exercise

print("Hello, I can create a list with the first n numbers' squares. ")

LENGTH_NUMBER=20

while True:
    numbers=int(input("How many numbers do you want enter? Enter a positive integer number: "))
    if numbers<=0:
        print("Wrong value! Try again.") 
    if numbers>0:
        break
list=[element**2 for element in range(1,numbers+1)] #List comprehension syntax 
print(list)
list.clear()

print("\nNow, we create a new list")
list=[element**2 for element in range(1,numbers+1) if (element**2)%2==0] #Even numbers 
print(list)
