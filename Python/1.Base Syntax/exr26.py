# Ask to user to enter 2 enterer numbers: high and length and you must generate a rectangle with '*' symbol.

high=int(input("Enter the high: ")) #So, this is the number of lines
length=int(input("Enter the length: ")) #So, this is the number of lines' elements

for i in range(high):
    print(length*'*')


