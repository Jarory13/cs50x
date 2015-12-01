#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

// Get user input, initialize coin tracking
printf("Hello, how much change is due? \n");
    float value =GetFloat();
    int count = 0;
    
//verify if value >0
while (value < 0)
  {   
    printf("I'm sorry please try a positive number \n");
    value =GetFloat();
  }

//change value to int
value = value*100;
value = roundf(value);
int rvalue = (int)value;

//track money change
while (rvalue > 0)
 {
    if (rvalue >= 25)
        {
        rvalue = rvalue - 25;
        count++;
        }
    else if (rvalue < 25 && rvalue >= 10)
        {
        rvalue = rvalue - 10;
        count++;
        } 
    else if (rvalue< 10 && rvalue >= 5)
        {
        rvalue = rvalue - 5; 
        count++;   
        }    
    else 
        {
        rvalue = rvalue -1;
        count++;
        }    
  }
 printf("%i\n", count);

}
