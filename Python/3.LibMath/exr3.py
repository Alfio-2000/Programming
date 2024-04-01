#Calculate quadratic square of a number.

import math
print("I can calculate the quadratic square of a number.\n")

while True: #1
    number=float(input("Insert a number:"))
    if number<0:
        print("Error: negative number.\n")
    else:
        break

square=math.sqrt(number)
print(f"You obtained:{square:.2f}")

#1: This control is necessary to insert a right number. If this number<0 it isn't good under quad.square. So, while true means
    #this: when i insert, for example, -5, the compiler ask me to insert a numebr again and only when i put +5 i got success.
