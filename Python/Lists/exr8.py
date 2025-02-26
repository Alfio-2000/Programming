# Write a script that it can sum all even numbers
# Use the list comprehension

print("Hello, I can sum all list's elements")

while True: 
    numbers=int(input("\nHow many numbers do you want enter?Please, enter an integer positive number: "))
    if numbers>0: 
        break
    else:
        print("Wrong value: Try again!")

list=[element for element in range(1,numbers+1) if element%2==0]
print(list)

sum=0
for i in range(len(list)):
    sum+=list[i]
    
print(f"The sum of list's even number is {sum}")

