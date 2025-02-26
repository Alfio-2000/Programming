#Write a script that it asks to create n different lists  and that it can calculate total sum & multiplication of lists' numbers

print("Hello, i can create a different lists") 

numberLists=int((input("How many lists do you want write? Enter a >0 number: ")))
while numberLists<=0: #This is necessary to check the right numberlists' value
    numberLists=int((input("Wrong value! Try again: ")))

lists=[]

for n in range(numberLists):
    numberElements=int(input(f"\nHow many elements do you want enter in the {n+1}° list? "))     
    current_list=[]
    for i in range(numberElements):
        element=int(input(f"Enter the {i+1}° element: "))
        current_list.append(element)
    lists.append(current_list)

print(f"\nThese are your lists:\nList n°1: {lists[0]}\nList n°2: {lists[1]}")

#Now it starts the sum of elements
sum=0
multiplication=1 #This count can't be 0 
for x in range(len(lists)): 
    for y in range(len(lists[x])): 
        sum+=lists[x][y]
        multiplication*=lists[x][y] #I'm multiplying every lists' element
print(f"\nLists' element sum is: {sum}\nLists' element multiplication is: {multiplication}")