# Write a script that it replaces chessboard

LINES=8 # Lines' number (this is a define number)
COLUMNS=8 # Columns' number (this is a define number)

characters_columns="ABCDEFGH"

for column in range(COLUMNS):
    print(characters_columns[column]+"1")
    for line in range(LINES):
        print(f"{characters_columns[column]}{line+1}")