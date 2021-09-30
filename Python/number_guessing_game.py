import random

num = random.randint(1, 100)
hintsLeft = 5
hints = 1
initial_score = 20

player_name = input("Enter your name: ")

print("Welcome", player_name)
print("\nEnter your guess")

while hints < 6:
    guess = int(input())

    if guess == num:
        print("You guessed the correct number\nAttempts taken: ", hints)
        break

    else:
        hintsLeft -= 1
        if guess > num:
            print("The number is smaller")
            print("Chances left: ", hintsLeft)
        else:
            print("Number is greater")
            print("Chances left: ", hintsLeft)

        hints += 1

    if hints == 6:
        print("Game Over!!")
        print("The number was: ", num)
