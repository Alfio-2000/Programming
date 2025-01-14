#Enter by keayboard an enteger positive number n and to create a numeric square in which every lines contains lines' number

number=int(input("Enter a number: "))
if number<=0: 
    print("You entered a wrong number!Please, put a number>0")
    
#Now i start to create the lines
for i in range(1,number+1):
    for j in range(1,number+1):
        print(i,j, end=" ") #end=" " is necessary to avoid to create tabs. In this way, every lines ends without \n
        