#Write a script that it asks to user to enter in a shopping list what the users wants buy at the store
# So, the script must ask: "What do u want enter?" When user enters "nothing" the script will must to end
# AT THIS MOMENT I DON'T KNOW NOTHING ABOUT LISTS, SO I STUDIED SOMENTHING ABOUT THEM WITH CHATGPT TO FIND A SOLUTION FOR THIS EXR

shopping_list=[]
end_list="nothing"
print("Hi, i can help you with your shopping list. Tell me what i must enter in it.")
print(f"When you want stop, please, u must enter '{end_list}'")
while True: #This syntax depicts an infinity cycle (1)
    thing=input("What do u want enter: ")
    if thing==end_list or thing==end_list.capitalize():
        break
    shopping_list.append(thing) #In this way i can enter elements in a list

print(f"Well done! This is your shopping list {shopping_list}")
    
        
    

# (1): The condiction in While is always soddisfy becasue True==True always

