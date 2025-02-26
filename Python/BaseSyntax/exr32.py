#Write a script that it can find the biggest number of a number's list entered by keyboard

lenght=int(input("How many numbers do you want compare? "))
max=None
for i in range(lenght):
    number=int(input(f"Enter {i+1}° number:"))
    if (max is None) or (number>max):
        max=number
print(f"The biggest number is {max}")