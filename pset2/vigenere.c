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
  string key = argv[1];
  int keylen = strlen(key);
  for(int a=0; a<keylen; a++)    
  if(isalpha(key[a]))
   {
   ;
   }
  else
  {
  printf("I'm sorry that is an invalid key \n");
  return 1;
  }  
    //get plaintext
    string plaint = GetString();
    int c = 0;
    //set variable to hold key index over over spaces
    int holder =0;
    //encipher text
    for(int i=0, n=strlen(plaint); i<n; i++)
      {
      int j = 0; 
      j = (holder+keylen) % keylen;
        //encipher upper
        if(plaint[i] >='A' && plaint[i]<= 'Z')
          {  
            if(isupper(key[j]))
              {
              c = (((plaint[i]-65 + key[j]-65) % 26) + 65);
              }
            else
              {
              c = (((plaint[i]-65 + key[j]-97) % 26) + 65);
              }
           holder++;   
          }
        //encipher lower  
        else if(plaint[i] >='a' && plaint[i] <='z')
          {
          if(isupper(key[j]))
              {
              c = (((plaint[i]-97 + key[j]-65) % 26) + 97);
              }
            else
              {
              c = (((plaint[i]-97 + key[j]-97) % 26) + 97);
              }
            holder++;  
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
