import random
import numpy as np

def attacked_queens(seq):
    a = np.array([0] * 81) 
    a = a.reshape(9, 9)  
    n = 0  

    for i in range(1, 9):
        if seq[i-1] != 0: 
            a[seq[i - 1]][i] = 1  

    for i in range(1, 9):
        if seq[i - 1] == 0:
            continue 
        for k in list(range(1, i)) + list(range(i + 1, 9)):  
            if a[seq[i - 1]][k] == 1:  
                n += 1
        t1 = t2 = seq[i - 1]
        for j in range(i - 1, 0, -1): 
            if t1 != 1:
                t1 -= 1
                if a[t1][j] == 1:
                    n += 1  

            if t2 != 8:
                t2 += 1
                if a[t2][j] == 1:
                    n += 1  

        t1 = t2 = seq[i - 1]
        for j in range(i + 1, 9): 
            if t1 != 1:
                t1 -= 1
                if a[t1][j] == 1:
                    n += 1  

            if t2 != 8:
                t2 += 1
                if a[t2][j] == 1:
                    n += 1 
    return int(n/2) 

def display_board(seq):
    board = np.array([0] * 81) 
    board = board.reshape(9, 9) 

    for i in range(1, 9):
        board[seq[i - 1]][i] = 1  
    for i in board[1:]:
        for j in i[1:]:
            print(j, ' ', end="")  
        print()  
    print('The number of queens under attack is ' + str(attacked_queens(seq)))

fp_queue = [{'unplaced_queens':8, 'pairs':28, 'seq':[0] * 8}] 
sol = []
flag = 0 
while fp_queue:
    first = fp_queue.pop(0)
    if first['pairs'] == 0 and first['unplaced_queens'] == 0: 
        sol = first['seq']
        flag = 1
        break
    nums = list(range(1, 9))  
    seq = first['seq']
    for j in range(8): 
        pos = seq.index(0)
        temp_seq = list(seq)
        temp = random.choice(nums) 
        temp_seq[pos] = temp 
        nums.remove(temp) 
        fp_queue.append({'unplaced_queens':temp_seq.count(0), 'pairs':attacked_queens(temp_seq),'seq':temp_seq})
    fp_queue = sorted(fp_queue, key=lambda x:(x['pairs'], x['unplaced_queens'])) 
if sol:
    print('solution sequence found:' + str(sol))
    display_board(sol)
else:
    print('Algorithm failed, no sol found')
