#Comparison beetwen two different lists

print("Hello, i can find the same elements of two different lists.")

NUMBER_LISTS=2 #This is the number of list we want to compare

length1= int(input("Enter the first list's length: "))

list1=[]
list2=[]

print("\nYou're building the first list.")
for i in range(length1):
    element1=int(input(f"Enter {i+1}° element: "))
    list1.append(element1)

print(f"The first list is: {list1}")

print("\nYou're building the second list.")
length2= int(input("Enter the second list's length: "))
for j in range(length2):
    element2=int(input(f"Enter {j+1}° element: "))
    list2.append(element2)

print(f"The second list is: {list2}")

print("\nNow, you're trying to find the same elements of the lists.\n")
sameNumbers=0
list3=[]

for i in range(length1):
    for j in range(length2):
        if list1[i]==list2[j]:
            sameNumbers+=1
            list3.append(list1[i])

print(f"There are {sameNumbers} same elements beetween your lists and they are: {list3}")

