/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
    //open card file to read
    FILE* openFile = fopen("card.raw", "r");
    
    //make sure it opens properly
    if(openFile == NULL)
    {
    fclose(openFile);
    printf("Unble to read memory card \n");
    return 1;
    } 

   /**
   create the following: buffer to store data, start file codes, out pointer
   wrtie flag, file counter, check buffer and file name array
   **/  
   uint8_t buffer[64] = {0};
   uint8_t jpgStart1[4] = {0xff, 0xd8, 0xff, 0xe0};
   uint8_t jpgStart2[4] = {0xff, 0xd8, 0xff, 0xe1};
   int fileCounter = 0;
   char jpgName[24];
   FILE* outptr;
   int writeFlag = 0;
   
   //begin reading through card.raw
   while(fread(&buffer, sizeof(buffer), 1, openFile) == 1) 
     {         
     //sanity check
     if(fileCounter > 16)
       {
       fclose(openFile);
       fclose(outptr);
       printf("Misread card.raw. Too many files created.");
       return 2;
       }
     
     //check if start of new jpg, if so create a new file for that jpg and update file counter
     if(memcmp(buffer, jpgStart1, 4) == 0 || memcmp(buffer, jpgStart2, 4) == 0)
       {
         writeFlag++;
         
         //close old jpg if possible
         if(fileCounter > 0)
           {
           fclose(outptr);
           }
           
         //update file name  
         sprintf(jpgName, "%03d.jpg", fileCounter);
        
        //open out file
        outptr = fopen(jpgName, "w");  
        
        //update counter
        fileCounter++;
       } 
       
     if(writeFlag != 0)
       {
       //write to outfile
       fwrite(&buffer, sizeof(buffer), 1, outptr); 
       }
       
    }    
    
       //close card.raw and outfile
       fclose(openFile); 
       fclose(outptr);
       return 0;
}
