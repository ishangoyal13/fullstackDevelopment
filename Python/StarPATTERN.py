def triangle(n):

     

    # number of spaces

    k = n - 1
 

    # outer loop to handle number of rows

    for i in range(0, n):
        for j in range(0, k):
            print(end=" ")
        k = k - 1
        for j in range(0, i+1):
            print("* ", end="")
        print("\r")

n = 5
triangle(n)
