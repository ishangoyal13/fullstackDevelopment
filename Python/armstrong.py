# program to print all the armstrong numbers between two given numbers.

def is_armstrong(num: int) -> bool:
    total = 0
    temp_num = num

    while temp_num > 0:
        total += (temp_num % 10) ** len(str(num))
        temp_num //= 10
    
    return total == num

def armstrong_nums_in_range(num1: int, num2: int) -> [int]:
    armstrong_list = []

    for num in range(num1, num2):
        if is_armstrong(num):
            armstrong_list.append(num)

    return armstrong_list

print(armstrong_nums_in_range(152, 1000))
