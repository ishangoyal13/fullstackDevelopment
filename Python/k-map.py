# Function for two variable k-map.

def inp2_k_map(mt, nip):
    for i in range(50): print("-", end='')
    print()
    #  Entering variables name.
    prnt = input("Enter Variables with single space(eg:A B) : ").split(" ")
    for i in range(len(mt)):
        mt[i] = '0b' + bin(mt[i])[2:].lstrip('0')
    op = ''
    ans = [[0, 0], [0, 0]]
    ansmx = [[0, 0], [0, 0]]
    flag = 0
    temp = []
    # Converting miima to binary equivalent code
    for i in range(2):
        for j in range(2):
            p = '0b' + (bin(i)[2:] + bin(j)[2:]).lstrip('0')
            if p in mt:
                ans[i][j] = 1
    for i in range(50): print("-", end='')
    print()
    print("The kmap plotted : ")
    if nip == 1:
        for each in ans: print(*each)
    elif nip == 2:
        for i in range(2):
            for j in range(2):
                if ans[i][j] == 1:
                    ansmx[i][j] = 0
                else:
                    ansmx[i][j] = 1
        for each in ansmx: print(*each)
    if ans == [[1, 1], [1, 1]]:
        flag = 1
        op = '1'

    if flag == 0:
        for i in range(2):
            if ans[i] == [1, 1]:
                if nip == 1:
                    op = 'A ' if i == 1 else "A' "
                elif nip == 2:
                    op = "(A') " if i == 1 else "(A) "
                temp.extend([(i, 0), (i, 1)])

    if flag == 0:
        if ans[0][0] == 1 and ans[1][0] == 1:
            if nip == 1:
                op = op + "B' "
            elif nip == 2:
                op = op + "(B) "
            temp.extend([(0, 0), (1, 0)])
        elif ans[0][1] == 1 and ans[1][1] == 1:
            if nip == 1:
                op = op + "B "
            elif nip == 2:
                op = op + "(B') "
            temp.extend([(0, 1), (1, 1)])
    if nip == 1:
        vr = ["A'B' ", "A'B ", "AB' ", "AB "]
    elif nip == 2:
        vr = ["(A+B) ", "(A+B') ", "(A'+B) ", "(A'+B') "]

    if flag == 0:
        for i in range(2):
            for j in range(2):
                if ans[i][j] == 1 and (i, j) not in temp:
                    op = op + vr[int('0b' + bin(i)[2:] + bin(j)[2:], 2)]
    op = op.rstrip(" ")
    if nip == 1:
        op = op.replace(" ", "+")
    op = op.replace("A", prnt[0])
    op = op.replace("B", prnt[1])
    for i in range(50): print("*", end='')
    print()
    print("The simplified equation is :", op)
    for i in range(50): print("*", end='')
    print()


# K_Map for 3 inputs.
def inp3_k_map(mt, nip):
    for i in range(50): print("-", end='')
    print()
    var_re = input("Enter variables with single space(eg:A B C) : ").split(" ")
    ansg = [[0, 0, 0, 0], [0, 0, 0, 0]]
    ansgmx = [[0, 0, 0, 0], [0, 0, 0, 0]]
    op = ''
    flag = 0
    qrd = []
    dul = []
    sngl = []
    if nip == 1:
        qrd_var_2_2 = ["B' ", "C ", "B ", "C' "]
        qrd_var_1_4 = ["A' ", "A "]
        dul_vert = ["B'C' ", "B'C ", "BC ", "BC' "]
        dul_horz = [["A'B' ", "A'C ", "A'B ", "A'C' "], ["AB' ", "AC ", "AB ", "AC'"]]
        sngl_val = [["A'B'C' ", "A'B'C ", "A'BC ", "A'BC' "], ["AB'C' ", "AB'C ", "ABC ", "ABC' "]]
    elif nip == 2:
        qrd_var_2_2 = ["(B) ", "(C') ", "(B') ", "(C) "]
        qrd_var_1_4 = ["(A) ", "(A') "]
        dul_vert = ["(B+C) ", "(B+C') ", "(B'+C') ", "(B'+C) "]
        dul_horz = [["(A+B) ", "(A+C') ", "(A+B') ", "(A+C) "], ["(A'+B) ", "(A'+C') ", "(A'+B') ", "(A'+C) "]]
        sngl_val = [["(A+B+C) ", "(A+B+C') ", "(A+B'+C') ", "(A+B'+C) "],
                    ["(A'+B+C) ", "(A'+B+C') ", "(A'+B'+C') ", "(A'+B'+C) "]]
    for i in range(2):
        for j in range(4):
            p = int('0b' + bin(i)[2:] + bin(j)[2:], 2)
            if (i == 1) and (j == 0 or j == 1):
                p = int('0b' + bin(i)[2:] + '0' + bin(j)[2:], 2)
            if p in mt:
                ansg[i][j] = 1

    for i in range(2):
        (ansg[i][2], ansg[i][3]) = (ansg[i][3], ansg[i][2])
    for i in range(50): print("-", end='')
    print()
    print("K-Map plotted : ")
    if nip == 1:
        for each in ansg: print(*each)
    elif nip == 2:
        for i in range(2):
            for j in range(4):
                if ansg[i][j] == 1:
                    ansgmx[i][j] = 0
                else:
                    ansgmx[i][j] = 1
        for each in ansgmx: print(*each)

    if ansg == [[1] * 4, [1] * 4]:
        op = op + '1'
        flag = 1
    if flag == 0:
        for j in range(-1, 3):
            if ansg[0][j] == 1 and ansg[-1][j] == 1 and ansg[0][j + 1] == 1 and ansg[-1][j + 1] == 1:
                qrd.append([(0, j), (-1, j)])
                if j < 2:
                    qrd.append([(0, j + 1), (-1, j + 1)])
                    qrd.append([(0, j), (0, j + 1)])
                    qrd.append([(-1, j), (-1, j + 1)])
                else:
                    qrd.append([(0, -1), (-1, -1)])
                    qrd.append([(0, j), (0, -1)])
                    qrd.append([(-1, j), (-1, -1)])
                op = op + qrd_var_2_2[j]
    if flag == 0:
        for i in range(-1, 1):
            if ansg[i] == [1, 1, 1, 1]:
                qrd.append([(i, -1), (i, 0)])
                qrd.append([(i, 0), (i, 1)])
                qrd.append([(i, 1), (i, 2)])
                qrd.append([(i, 2), (i, -1)])
                op = op + qrd_var_1_4[i]
    if flag == 0:
        for j in range(-1, 3):
            if ansg[0][j] == 1 and ansg[1][j] == 1:
                temp = 0
                if [(0, j), (-1, j)] in qrd:
                    temp = 1
                elif [(-1, j), (0, j)] in qrd:
                    temp = 1
                if temp == 0:
                    dul.append([(0, j), (-1, j)])
                    op = op + dul_vert[j]

    if flag == 0:
        for i in range(-1, 1):
            for j in range(-1, 3):
                if ansg[i][j] == 1 and ansg[i][j + 1] == 1:
                    temp = 0
                    if j == 2:
                        if [(i, j), (i, -1)] in qrd:
                            temp = 1
                        elif [(i, -1), (i, j)] in qrd:
                            temp = 1
                    else:
                        if [(i, j), (i, j + 1)] in qrd:
                            temp = 1
                        elif [(i, j + 1), (i, j)] in qrd:
                            temp = 1
                    if temp == 0:
                        if j == 2:
                            dul.append([(i, 2), (i, -1)])
                        else:
                            dul.append([(i, j), (i, j + 1)])
                        op = op + dul_horz[i][j]

    op = op.rstrip(" ")
    opl = op.split(" ")
    for i in range(len(opl)):
        opl[i] = opl[i] + " "

    for each in dul:
        d1cnt = 0
        d2cnt = 0
        (d1, d2) = (each[0], each[1])
        for each1 in dul:
            if d1 in each1:
                d1cnt += 1
            if d2 in each1:
                d2cnt += 1
        if d1cnt > 1 and d2cnt > 1:
            (d1i, d1j) = d1
            (d2i, d2j) = d2
            if d1i == d2i:
                p = dul_horz[d1i][d1j]
                opl.remove(p)
            else:
                p = dul_vert[d1j]
                opl.remove(p)
            dul.remove([d1, d2])
    op = "".join(opl)

    for _ in qrd:
        for each in _:
            sngl.append(each)
    for _ in dul:
        for each in _:
            sngl.append(each)

    if flag == 0:
        for i in range(-1, 1):
            for j in range(-1, 3):
                if ansg[i][j] == 1:
                    if (i, j) not in sngl:
                        op = op + sngl_val[i][j]

    op = op.rstrip(" ")
    if nip == 1:
        op = op.replace(' ', ' + ')

    op = op.replace("A", var_re[0])
    op = op.replace("B", var_re[1])
    op = op.replace("C", var_re[2])
    for i in range(50): print("*", end='')
    print()
    print("The simplified equation is :", op)
    for i in range(50): print("*", end='')
    print()


# main
ask = 'y'
while ask == 'y':
    for _ in range(50): print("-", end='')
    print()
    nfinp = int(input("Enter no of Inputs(2,3) : "))
    mimastr = input("Enter 'SOP' for SOP(Minterms) or 'POS' for POS(Maxterms) : ").lower()
    if mimastr == 'pos':
        mima = 2
    elif mimastr == 'sop':
        mima = 1
    if mima == 1:
        mt = list(map(int, input("Enter Minterms : ").split()))
    else:
        mt = list(map(int, input("Enter Maxterms : ").split()))
    if nfinp == 2:
        inp2_k_map(mt, mima)
    elif nfinp == 3:
        inp3_k_map(mt, mima)
    elif nfinp == 4:
        inp4_k_map(mt, mima)
    else:
        print("You committed some mistake, please check the inputs next time.")
    ask = input("Enter 'y' for another K-Map or 'n' to exit : ").lower()
    for i in range(25):
        print("--", end='')
    print()
