import mysql.connector
from difflib import get_close_matches

# Mysql connection config
con = mysql.connector.connect(
user = "ardit700_student",
password = "ardit700_student",
host = "108.167.140.122",
database = "ardit700_pm1database"
)

cursor = con.cursor()
query1 = cursor.execute("SELECT * FROM Dictionary")
expressions = cursor.fetchall()
results = []

for expression in expressions:
    results.append(expression[0])


def translate(w, results):      
    w = w.lower()  
    if w in results:
        query = cursor.execute("SELECT * FROM Dictionary WHERE Expression = '%s'" % w)
        data = cursor.fetchall()
        return data
    else:
        if len(get_close_matches(w, results)) > 0:
            yn = input("Do you mean %s? Enter Y if yes, or N if no: " % get_close_matches(w, results)[0])
            if yn == "Y" or yn == 'y':
                query = cursor.execute("SELECT * FROM Dictionary WHERE Expression = '%s'" % get_close_matches(w, results)[0])
                data = cursor.fetchall()
                return data
            elif yn == "N" or yn == 'n':
                return "The word doesn't exist. Please double check it."
            else:
                return "We didn't understand your entry."
        else:
            return "The word does not exist. Please try another word."
    

word = input('Enter a word: ')
output = translate(word, results)

if type(output) == list:
    for item in output:
        print('=>', item[1])
else:
    print(output)