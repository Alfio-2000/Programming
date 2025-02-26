#Write a script in which user can enter a numbers in a list and it's possible to find the max of them. 

print("Hello! I can create a list, but you must to enter some numbers.")

length=int(input("How many numbers do you want enter? Enter a >0 number: "))

while length<=0: #It checks if user's list's length is correct or not
    length=int(input("Wrong selection. Try again: "))

list=[]

for i in range(length):
    number=int(input(f"Enter {i+1}° number: "))
    list.append(number)

print(f"\nYour list is: {list}\n")

max=list[0]
min=list[0]

for i in range(length):
    if list[i]>=max:
        max=list[i]
    elif list[i]<min:
        min=list[i]
print(f"The max of list's numbers is {max}\nThe min of list's numbers is {min}")