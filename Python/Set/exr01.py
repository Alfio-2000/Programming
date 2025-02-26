# Enter n numbers by keyboard. Your script needs to be able to find every prime numbers and it needs to put them in a set that it called
# "prime_numbers"

print("Hello, I can find every prime numbers in the first n numbers that you can enter.")

while True:
    n=int(input("\nHow many numbers do you want enter? Please, enter an integer positive number: "))
    if n>0:
        break
    else:
        print("Wrong value.Try again:",end=" ")

numbers={number for number in range(1,n+1)}
prime_numbers=set()

for number in numbers:
    if number>1: #Prime numbers start from 2
        for i in range(2,number):
            if number%i==0: 
                break
        else: # (1)
            prime_numbers.add(number) # (2)

print(f"The set 'prime numbers' is: {prime_numbers}.")

#(1) I can use else with for when the loop completes without hitting a break. 
# In our case, we are interested in the absolute value of a number: if it returns 0, we exit the loop because the break is executed.

#(2) The sets in Python don't keep the order. So, when I upload it with 'number' I can't be sure if this sort is maintained
# So, if I enter n=50,60 or 100 I could find a disorganized order.   


