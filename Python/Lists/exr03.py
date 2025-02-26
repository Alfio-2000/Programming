# Write a script that it can to remove odd numbers that they're in a list and print a list with removed elements. 
#pylint: disable=all
print("Hello, i can remove odd numbers that they're in a list") 

list=[]
list1=[]
while True:
    numbers=int(input("How many numbers do you want enter? "))
    if numbers>0:
        break
    else:
        print("Wrong number! Try again.")


for i in range(numbers):
    element=int(input(f"Enter {i+1}° element: "))
    list.append(element)
    if element%2!=0:
        list.remove(element)
        list1.append(element)

print(f"Your list, whithout odd numbers, is {list}\n")
print(f"Your list, whithout even numbers, is {list1}\n")

