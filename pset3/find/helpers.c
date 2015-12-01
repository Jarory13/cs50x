/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
   if(n<1)
     {
     return false;
     }
   //initialize set min, max, and mid points of array
   int min = 0;
   int max = n-1;
   int mid = n/2;
   
   //binary search
     while (mid > 0)
       {
       //return true if at midpoint
         if(value == values[mid])
           {
           mid = 0;
           return true;
           } 
        
         //if value is less then mid search left
         else if(value < values[mid])
           {
           max = mid - 1;
           mid = (max+1)/2;
           }
        
         //if value is greater than mid search right
         else if(value > values[mid])
           {
           min = mid + 1;
           mid = (min+max)/2;
           }
         
         //corner case
         else
           {
           mid = 0;
           return false;
           }
           
       }
    
      return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    //set flag variables
    bool sorted = false; 
    
    //start sort
  while(sorted == false)
  {
     bool pass = false;
      for(int i = 0; i < n; i++)
        {
         if(values[i] > values[i+1])
          {
          int temp = values[i];
          values[i] = values[i+1];
          values[i+1] = temp;
          pass = true;
          }
        }
      if(pass == false)
        {
        sorted = true ; 
        }   
  }  
}
