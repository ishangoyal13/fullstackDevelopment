import random


def diceFace(num):
    if num == 1:
        print("-----")
        print("|" + "   " + "|")
        print("|" + " 0" + " |")
        print("|" + "   " + "|")
        print("-----")
          
        

    if num == 2:
        print("-----")
        print("|0" + "  " + "|")
        print("|" + "   " + "|")
        print("|" + "  " + "0|")
        print("-----")

    if num == 3:
        print("-----")
        print("|0" + "  " + "|")
        print("|" + " 0 "   + "|")
        print("|" + "  " + "0|")
        print("-----")

    if num == 4:
        print("-----")
        print("|0" + "" + " 0|")
        print("|" + "   " + "|")
        print("|0" + "" + " 0|")
        print("-----")

    if num == 5:
        print("-----")
        print("|0" + "" + " 0|")
        print("|" + " 0 " + "|")
        print("|0" + "" + " 0|")
        print("-----")

    if num == 6:
        print("-----")
        print("|0" + "" + " 0|")
        print("|0" + " " + "0|")
        print("|0" + "" + " 0|")
        print("-----")


str = 'y'
while str == 'y':
    diceFaceNum = random.randint(1, 6)
    if diceFaceNum == 1:
        diceFace(1)
    elif diceFaceNum == 2:
        diceFace(2)
    elif diceFaceNum == 3:
        diceFace(3)
    elif diceFaceNum == 4:
        diceFace(4)
    elif diceFaceNum == 5:
        diceFace(5)
    elif diceFaceNum == 6:
        diceFace(6)
    print("Would you like to roll once again ?")
    str = input("Enter y for yes and n for a no\n")
