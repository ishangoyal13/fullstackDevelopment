height = float(input("Enter the height in m: "))
weight = float(input("Enter the weight in kg: "))
bmi = round(weight / (height ** 2))

if bmi < 18.5:
    print(f"Your bmi is {bmi}, you are slightly underweight.")
elif bmi < 25:
    print(f"Your bmi is {bmi}, you have a normal weight.")
elif bmi < 30:
    print(f"Your bmi is {bmi}, you are overweight.")
elif bmi < 35:
    print(f"Your bmi is {bmi}, you are slightly obese.")
else:
    print(f"Your bmi is {bmi}, you are slightly clinically obese.")
