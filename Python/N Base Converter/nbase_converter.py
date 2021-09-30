def nbase_decimal_conv(number_input, n_base):
    '''Convert N base number to a decimal number
    Keyword:
    number_input -- Giving a certain number from any N base number
    n_base -- user input N base
    return:
    sum_num -- the sum of each digit of the power of N base
    '''
    sum_num = 0
    string_user = str(number_input)

    string_user = string_user[::-1]
    for i in range(len(string_user)):
        formula = int(string_user[i]) * n_base ** i
        sum_num += formula
    return sum_num


    