#pylint: disable=all

# Write a function that it gets a number's list and it must return the sum of all list's elements

def building_list():
    """Asks the user for a number of elements and builds a list."""
    list_name=[]
    n = int(input("How many numbers do you want enter? "))  # Numbers of elements of a list
    for i in range(1, n + 1):
        element = int(input(f"Enter the {i}° number: "))
        list_name.append(element)
    return list_name

def sum_elements(list_name):
    """Sums all of the elements of a list."""
    counter = 0
    for element in list_name:
        counter += element
    return counter

name = input("Enter the name of your list: ").title()
name=building_list()
totalSum = sum_elements(name)
print(f"The sum of elements' of your list is: {totalSum}")
