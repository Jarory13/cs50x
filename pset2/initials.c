#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  string name =" "; 
  //get name
  do
    {
    
    name =GetString();
    }
  while(name == NULL); 

//upcase and print first letter
      printf("%c", toupper(name[0]));

//upcase loop
  for(int i=0, n=strlen(name); i<n; i++)
    {
    
    //upcase and print every letter after space
      if(name[i] == 32)
       {
        printf("%c", toupper(name[i+1]));
       }

    }  
   //create new line 
   printf("\n");

}
