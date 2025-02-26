# To create an archive of books. In particolary: user must to insert a book's name by keyboard
# The script must know the book and print to screen if this one is in archive. 
# In addition, if the book's name isn't in the list the script must ask to user if it want to insert it in library. 

library= {

    "Lord of the rings" :{"author": "J.R.R Tolkien", "free copies": 5}, 
    "Harry Potter": {"author": "J.K. Rowling", "free_copies": 3}, 
    "1984": {"author": "George Orwell", "free_copies": 2}         
}

title= input("Enter your book's name:")

if title in library: 
    print("Your book is in our archive:\n")
    print("Title is: ", title) 
    print("Author: ", library[title]["author"]) # With this statement we can recall the library's elements like vectors in C language
    print("Free copies: ", library[title]["free copies"])

else:
    print("Your book isn's in our archive.\n")
    print("Do you want to insert it in our archive? (yes/no)\n")
    choice= input("Enter your choice: ")
    if choice.lower()== 'yes' or choice.upper() == 'YES' or choice.capitalize()=='Yes': 
        # pass  This is useful to say to Python skip this statement
        new_author= input("Please, enter the author of your book: ")
        new_free_copies= int(input("\nPlease, enter how free copies you want enter in our archive: "))
        library[title]={"atuhor": new_author, "free copies": new_free_copies} # 1
        print(f"Our new archive is:\n{library}\n")
        print("Your book has been applied with success!.\nThanks for your feedback. See you soon! ") 
    else:  
        print("Your books hasn't been applied in our archive.\nThanks for your feedback. See you soon!")


# 1: In this way i can refresh my archive with new books. I did this exr when i didn't know list or dictionary (Midali is crazy sometimes)
