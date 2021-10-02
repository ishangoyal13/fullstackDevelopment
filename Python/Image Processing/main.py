from PIL import Image
import cv2
import numpy as np
import os

# Functions for manupulating the images

def cropImage(im, ima):
    print("To crop the image Please input the coordination")
    a = int(input("Left: "))
    b = int(input("Upper: "))
    c = int(input("Right: "))
    d = int(input("Lower: "))
    box = (a, b, c, d)
    print("Please wait....")
    region = im.crop(box)
    re = input("To show the image press 's'\nTo return press any key\n")
    if re == 's':
        region.show()
    else:
        return None    

def rotateImage(im, ima):
    while True:
        print("To rotate Left press 'L'")
        print("To rotate Right press 'R'")
        print("To rotate Up press 'U'")
        print("To rotate Down press 'D'\n")
        print("To go back press 'B'")
        a = input()
        a = a.lower()
        if a == 'l':
            im = im.rotate(-90)
        elif a == 'r':
            im = im.rotate(90)
        elif a == 'u':
            im = im.rotate(180)
        elif a == 'd':
            im = im.rotate(-180)    
        elif a == 'b':
            break    
        else:
            print("Please enter a valid option")
            continue    
        print("\nImage rotated successfully\nTo show and save the image press 's'\nOtherwise press any key\n")
        b = input()
        if b == 's':
            im.show()
            ss = f"rotate-{ima}"
            im.save(ss)
        else:
            return None    

def blackwhite(im, ima):
    print("\nPlease wait...")
    im = im.convert('1')
    print("To show and save the image press 's'\nTo return press any key")
    a = input()
    if a == 's':
        ss = f"blackwhite-{ima}"
        im.save(ss)
        im.show()
    else:
        return None

def cartoonization(im, ima):
    # reading image
    img = cv2.imread(ima)
    # edges
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    gray = cv2.medianBlur(gray, 5)
    edges = cv2.adaptiveThreshold(gray, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 9, 9)
    # Cartoonization
    color = cv2.bilateralFilter(img, 9, 250, 250)
    cartoon = cv2.bitwise_and(color, color, mask=edges)

    cv2.imshow("Image", img)
    cv2.imshow("edges", edges)
    cv2.imshow("Cartoon", cartoon)
    cv2.waitKey(0)
    # cv2.destroyAllWindows()            

if __name__ == "__main__":
    print("---------------------------------------------\n---------------------------------------------\n-------------CLI Image Editor----------------\n---------------------------------------------\n---------------------------------------------\n")
    while True: 
        # Listing all the images available on the directory
        files = [f for f in os.listdir('.') if os.path.isfile(f) if f.endswith("jpg") or f.endswith("png") or f.endswith("jpeg")]
        print("\nPlease select which image to be edited\n")
        for f in range(len(files)):
            print(f"{f}: {files[f]}")

        # Getting input from user which image to be edited    
        i = input()
        try:
            ima = files[int(i)]
        except IndexError as e:
            print("Please enter valid file")
            continue
        except Exception as e:
            print("Please enter the index number")
            continue

        # Opening  the choosen image by the user 
        im = Image.open(ima)
        
        while True:
            # What to do with the Image
            print(f"\nWhat do you want to do with your image- {ima}?\n")

            print("TO Cartoonize press 'cc'\nTo show the image press 's'\nTo rotate the image press 'r'\nTo crop the image press 'c'\nTo greyscale the image press 'g'\nTo go back press 'b'\nTo exit press 'q")
            a = input()
            a = a.lower()

            if a == 's':
                im.show()
            elif a == 'cc':
                cartoonization(im, ima)    
            elif a == 'c':
                try:  
                    cropImage(im, ima)
                except Exception as e:
                    print("\nSomething went wrong\n")    
            elif a == 'r':
                try:
                    rotateImage(im, ima)
                except Exception as e:
                    print("\nSomething went wrong\n")     
            elif a == 'g':
                try:
                    blackwhite(im, ima)
                except Exception as e:
                    print("\nSomething went wrong\n")    
            elif a == 'b':
                break       
            elif a == 'q':
                exit()

            else:
                print("Please enter a valid option\n")            
        
