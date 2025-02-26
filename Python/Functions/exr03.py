
# Write a function that it retunr a list's tuples in the following way: (x,x**2) for x starts to 1 to arrive n
# So, they must be: [(1,1), (2,4), (3, 9)] 

def square_tuples(elements):
    couple=[(number,number**2) for number in range(1,elements+1)]
    print(couple)

while True:
    numbers_elements=int(input("How many numbers do you want enter? Enter positive and integer number: "))
    if numbers_elements>0:
        break
    else: 
        print("Error: Try again",end=" ")
   
square_tuples(numbers_elements)

