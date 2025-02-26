# You have 2 tuples: colors= ("red","verde", "blue") & forms= ("circle", "square").
# Write script that it can print all combinations of the 2 tuples 

colors=("red","verde", "blue")
forms= ("circle", "square")
counter_combinations=1 
for form in forms:
    for color in colors: 
        print(f"{counter_combinations}° combination: {form}-{color}")
        counter_combinations+=1