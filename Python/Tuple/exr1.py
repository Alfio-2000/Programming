# Write a script that it can create a tuple with numbers entered by keyboard

print("Hello, I can create a tuple with your numbers entered by keyboard.")

while True:
    numbers=int(input("How many numbers do you want enter? "))
    if numbers>0: 
        break
    else: 
        print("\nWrong value! Try again: ", end=" ")

try_list=[] # I'm creating an empty tuple 

for i in range(numbers):
    element=int(input(f"Enter {i+1}th number: "))
    try_list.append(element)

base_tuple=tuple(try_list) #(1)
print(base_tuple) 
print("\nNumbers with even index:", end=" ")
for i in range(len(base_tuple)): #I'm printing the numbers with even index
    if i%2==0: 
        print(base_tuple[i], end=" ")
print("\nNumbers with odd index:", end=" ")
for i in range(len(base_tuple)): #I'm printing the numbers with even index
    if i%2!=0: 
        print(base_tuple[i], end=" ")

print("\n\nI can create others two tuple starting from the first ")
middleNumber=int(input("Which the first tuple's numbers do you want use? "))
tuple1=base_tuple[:middleNumber]
tuple2=base_tuple[-middleNumber:]
print(f"The new two tuples are: {tuple1} and {tuple2}")
list1=list(tuple1)# I need to use this list because I have to modify the tuple and I can't do it on tuple
new_list1=[]
for i in range(len(list1)):
    element=list1[i]*3
    new_list1.append(element)

new_tuple1=tuple(new_list1)
print(f"I multiplied by 3 the element of {tuple1}. So, the final tuple is: {new_tuple1+tuple2}")





#(1): This statement does a casting. The script's logic is this: Tuple are impossibile to change. 
# I need to use a list and I need to make a casting: in this way I can replace list with tuple. 

