#Write a script that it can create a dictionary from 2 lists. 


keys=["name","surname","age"]
keys_values=["Alfio", "Lo Castro", 25]

person=dict(zip(keys,keys_values)) #(1)

print(f"Your dictionary is: {person}")

#(1): The zip() function is used to bind two elements from two different lists or tuples. In other words, this function is useful 
# for associating, for example, the first element of the first list with the first element of the second list and 
# placing both of them into a single structure.

