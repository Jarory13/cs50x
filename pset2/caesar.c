#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
  //verify key
  
  if(argc != 2)
    {
     printf("I'm sorry that is an invalid key \n");
     return 1;
    }
    
  //shift key to integer verify integer   
  int key = atoi(argv[1]);
  if(key<1)
    {
    printf("I'm sorry that is an invalid key \n");
    return 1;
    } 
    
  //get plaintext
  string plaint = GetString();
  char c = 'a';

  //encipher text
  for(int i=0, n=strlen(plaint); i<n; i++)
    {
      //encipher upper
      if(plaint[i] >='A' && plaint[i]<= 'Z')
        {
         c = (((plaint[i] + key-65) % 26) + 65);
        }
      //encipher lower  
      else if(plaint[i] >='a' && plaint[i] <='z')
        {
         c = (((plaint[i] + key-97) % 26) + 97);
        }
      //if not letter  
      else 
        {
        c = plaint[i];
        }
      printf("%c", c);
     }
 printf("\n");
 return 0;
}
