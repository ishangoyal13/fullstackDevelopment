#Anagram strings are those who have the same letters arranged in a different order.

str1 = input("Enter the first string")
str2 = input("Enter the second string")

if(sorted(str1.lower()) == sorted(str2.lower())):
   print("The input strings are anagram")
else:
    print("The input strings are not anagram")
       
