def swap_case(s):
    res=''
    for letter in s:
        if(letter.islower()):
            res=res+letter.upper()
        else:
            res=res+letter.lower()
    return res
    