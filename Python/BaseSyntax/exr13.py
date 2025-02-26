# Write a script that it can pull out from a string: 
# 1. The elements with even index
# 2. The elements with odd index
# 3. Print reverse order skipping one each time  

string=input("Enter a word: ")

# 1. Solution
print(f"Even index numbers are: {string[1::2]}") # In this way i start by second element to arrive tha last skipping two each time (1)

# 2. Solution
print(f"Even odd numbers are: {string[0::2]}") # In this way i start by first element to arrive tha last skipping two each time (2)

# 3. Solution
print(f"'{string}' in reverse order skipping 2 each time is: {string[::-2]}") 

# (1): Skipping 2 is necessary because i get odd index elements (1,3,5,7..)
# (2): Similar to past point
