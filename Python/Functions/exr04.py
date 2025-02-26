def building_list(): #I'm building a list of numbers
    list_name=[]
    n = int(input("How many numbers do you want enter? "))  # Numbers of elements of a list
    for i in range(1, n + 1):
        element = int(input(f"Enter the {i}° number: "))
        list_name.append(element)
    return list_name

def removing_negative_numbers(list_name):
    return [element for element in list_name if element>=0]

print("I can remove a negative numbers of a created list\n")
name=input("Enter the name of your list: ").title()
name=building_list()
print(f"Original list: {name}")
filtred_list=removing_negative_numbers(name)
print(f"Filtred list: {filtred_list}")
