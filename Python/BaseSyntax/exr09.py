# Write a script that it can count the vocals in a string

string=input("Enter a word: ").lower() # In this way we're writing all string's letters low 

count_vocals= string.count('a')+string.count('e')+string.count('i')+string.count('o')+string.count('u') # (1)

print(f"Your string '{string}' contains {count_vocals} vocals.")

# (1): Because in this exr we don't need to use the iterative cycles, we need to use the function string.count(character) that it 
# can count how many times the character beetween () there is in the string we write by keyboard. 





