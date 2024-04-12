# Second exercise in Python: enter your name from the keyboard

x = input("Enter your name:")  # [1]
print(x)
print(type(x))  # in this way I'm printing the type of variable I'm using

# [1]: The input function allows us to enter something from the keyboard: however, the compiler thinks that
# we are entering STRINGS!! NOT NUMBERS. So, we should do a casting.
# To better understand this concept see exercise 3.
