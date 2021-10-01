#include <stdio.h>

int main() {
  
  //Variable Declaration 
   int rows, i, j, space;
  
  //Getting values
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
  
  //Printing upside down triangle ⛛ 
   for (i = rows; i >= 1; --i) {
      for (space = 0; space < rows - i; ++space)
         printf("  ");
      for (j = i; j <= 2 * i - 1; ++j)
         printf("* ");
      for (j = 0; j < i - 1; ++j)
         printf("* ");
      printf("\n");
   }
   return 0;
}
