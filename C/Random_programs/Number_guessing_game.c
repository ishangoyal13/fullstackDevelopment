#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\n\n");
    printf("Hi! Welcome to THE GUESSING GAME!!\n");
    printf("In this game, you have to guess a number between 1 and 30\n");
    printf("You will get only 5 attempts to guess the number right\n\n");
    int num, guess, c = 1, i = 5, temp,k=1;
    srand(time(0));
    num = rand() % 30 + 1;
    // num=rand()%30 + 1; //generates a random number between 1 and 30
    // printf("The number is %d\n",num);
    // keep running the loop until the number has been guessed
    printf("Guess the number between 1 to 30\n\n");

    for(i=5;i>=1;i--){
        c++;
        scanf("%d",&guess);
        if(guess>30 || guess<1){
            printf("Please guess a number between 1 and 30\n\n");
        }
        else{
            if (guess > num)
            {
                printf("You should enter a lower number\n");
                printf("You have %d attempts remaining\n\n", (i - 1));
                temp=i-1;
            }
            else if (guess < num)
            {
                printf("You should enter a higher number\n");
                printf("You have %d attempts remaining\n\n", (i - 1));
                temp=i-1;
            }
            else
            {
                printf("CONGRATULATIONS!! You won the game!!\n");
                printf("You guessed it in %d attempts\n\n", (c-1));
                return 0;
            }
                
        }
        
    }
    if(temp<1){
        printf("Sorry!!\n");
        printf("You have not got any more chances to guess the number\n");
        printf("The number was: %d\n",num);
        printf("Better luck next time!\n");
    }
    
}
    
