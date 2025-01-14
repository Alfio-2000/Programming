# Write a script that it can control if a document has ".pdf" extension. 

EXTENSION= ".pdf"

file_name=input("Enter your file_name: ")

if file_name[-4:]==EXTENSION: 
    print("Your file is a PDF.")

else: 
    print("Your file is not a PDF.")