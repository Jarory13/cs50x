#include <stdio.h>
#include <cs50.h>
int main(void)
{  
// get size of pyramid
printf("How big would you like your pyramid, sir?"); 
  int  size = GetInt();
// check pyramid size for range
while (size <0 || size > 23)
{
   printf("I'm sorry we can't make a pyramid that size. \n");
   size = GetInt(); 
} 

// tracks the number of rows
for (int n = 0; n < size; n ++)
{
// builds pyramid
        for (int space = size - (n+1); space > 0; space--)
    {
           printf(" ");
    }
     for (int hash = 0; hash < n+2; hash ++)
    {
        printf("#");
    }
    printf("\n"); 
}
}
