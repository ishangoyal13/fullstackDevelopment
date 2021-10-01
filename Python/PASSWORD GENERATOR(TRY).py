import random as r
from random import shuffle
lis1=map(str,['1','2','3',4,5,6,7,8,9])
lis2=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
lis3=[i.upper() for i in lis2]
lis4=[',','.','/','?','&','^','*','#','@','~','<',">",'|','\'']
lis5=[]
for i in lis1:
    lis5.append(i)
for j in lis2:
    lis5.append(j)
for k in lis3:
    lis5.append(k)
for l in lis4:
    lis5.append(l)
shuffle(lis5)
pas=[]
def len_():
    max_len=16
    min_len=8
    return r.randrange(8,17,1)
lis=[]
class user_info():
    def __init__(self,first_name,last_name,DOB,Email):
        self.first_name=first_name
        self.last_name=last_name
        self.DOB=DOB
        self.Email=Email
    def additional_info(self):
        address=input("Enter your Address-:")
        phone_no=input("Enter your phone number-:")
        lis.append(address)
        lis.append(phone_no)
first_name=input("YOUR FIRST NAME-:")
last_name=input("YOUR LAST NAME-:")
DOB=input("YOUR DOB-:")
Email=input("YOUR EMAIL-:")
info=user_info(first_name,last_name,DOB,Email)
print("Do you want add some additional inf0-:")
print("type y for yes\n n for no")
a=input()
if a=='y':
    info.additional_info()
else:
    print("ok")

def pass_():
    for i in range(len_()):
        pas.append(r.choice(lis5))
    print("NAME-:"+" "+info.first_name+" "+info.last_name)
    print("DOB-:"+" "+info.DOB)
    print("EMAIL-:"+" "+info.Email)
    if lis!=[]:
        print('\n'.join(lis))
    print("Your generated Password is-:"+"".join(pas))
pass_()




        

