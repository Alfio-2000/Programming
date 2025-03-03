# Write some recursive functions

# Fibonacci's sequence
def Fibonacci(n):    
    if n==0: 
        return 0
    elif n==1:
        return 1
    else: 
        return Fibonacci(n-1) + Fibonacci(n-2) 
    

def sequence_Fibonacci(n):
    sequence=[] #It's useful to save every element of Fibonacci's sequence
    for i in range(n+1):
        sequence.append(Fibonacci(i)) #I'm recalling my function that it shows Fibonacci's sequence until n
   
    print(f"Fibonacci sequence of the {n} elements: {sequence}")


print("Hi, I can show to you the entire Fibonacci's sequence up to a number entered by keayboard.")
while True:
        number=int(input("\nEnter an integer and positive number: "))
        if number>0:
            break
        else:
            number=int(input("Invalid input! Try again: "))

print(sequence_Fibonacci(number)) #I'm calling the function Fibonacci()
