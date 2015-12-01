/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Creates a resized version of a BMP file that is n times larger
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }
    
    //change argv[1] to int
    int newSize = atoi(argv[1]);
    
    //verfity that newSize is between 1 and 100
    if (newSize < 1 || newSize > 100)
    {
    
    printf("Cannot resize file to those dimensions \n");
    return 5;
    }
   
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);  
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    //Create new Headers
    BITMAPFILEHEADER newBf = bf;
    BITMAPINFOHEADER newBi = bi;
      
       //modify newBf and newBi
    if (newSize > 1)
    {
    newBi.biWidth = newSize * bi.biWidth;
    newBi.biHeight = newSize * bi.biHeight;
    }   
      
    // determine padding for scanlines in infile
    int inPadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // determine padding for scanlines in outfile
    int outPadding =  (4 - (newBi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
   
    //modify newBf and newBi
    if (newSize > 1)
    {
    newBi.biSizeImage = abs(newBi.biWidth *newBi.biHeight) * sizeof(RGBTRIPLE) + (abs(newBi.biHeight) * outPadding);
    newBf.bfSize = newBi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    }
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&newBf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&newBi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
      //repeat scan equal to outfile height
      for(int a = 0; a < newSize; a++)
          {
          int tracker = 0;
          // iterate over pixels in scanline
          for (int j = 0; j < bi.biWidth; j++, tracker++)
            {
             // temporary storage
             RGBTRIPLE triple;
            
              // read RGB triple from infile
              fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
              // write RGB triple to outfile as many times as newSize
              for(int b = 0; b < newSize; b++)
                {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
             }

            // add padding to outfile
            for (int k = 0; k < outPadding; k++)
              {
              fputc(0x00, outptr);
              }
            
            if(a < newSize-1)
              {
              //move infile position back to start of line  
              fseek(inptr, -(tracker*3), SEEK_CUR); 
              }      
           }
       // skip over padding in infile, if any
       fseek(inptr, inPadding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);
    
    // that's all folks
    return 0;
}
