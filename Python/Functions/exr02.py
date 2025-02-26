# pylint: disable=all
# Write a function that it can print a table nxm: You must create a matrix

def table(n, m):
    """Calculating a matrix"""
    for i in range(1,n+1):
        for j in range(1,m+1):
            print(i*j, end=" ")
        print()

print("Hello, I can create a table")
lines=int(input("Lines' number: "))
rows=int(input("Rows' number: "))

table(lines,rows)
