print("Tip Calculator - Sharoni Bose")
bill = float(input("What was the total bill amount? "))
tip = int(input("What percentage of tip would you like to give? "))
people = int(input("How many people to split the bill? "))
billWithTip = ((tip / 100) * bill) + bill
billPerPerson = billWithTip / people
finalAmount = round(billPerPerson, 2)
finalAmount = "{:.2f}".format(finalAmount)
print(f"Each person should pay: ₹{final_amount}")