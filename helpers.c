/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>                                                          

#include "helpers.h"                                                                                


 // Returns true if value is in array of n values, else false.
 //BINARY SEARCH

bool search(int value, int values[], int n)
{
    int min = 0;
    int max = n;
    int mid = 0;
    
  do
   {
       
       mid = (min + max)/2;
  
       if (max < min)
       break;                                //If haystack doesn't have "value", "max" will get less than "min"; Hence, Loop breaks.
  
  
       else if (value > values[mid])
       {
           min = mid + 1;
       }
    
    
       else if (value < values[mid]) 
       {
           max = mid -1;
       }
  
  
       else 
       break;
    

    }
    while (value != values[mid]);
    
    if (value == values[mid])
    return true;
    else 
    return false;
    
     
}  
  




void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm---BUBBLE SORT
 
    
    int k, j, temp;
    
    for (k = 0; k<(n-1); k++)
    {
       
        temp = 0;                             //Here, assigning temp = 0 is significant; If temp stays 0 in the inner loop, then our array is sorted. Think about it!              
       
        for (j = 0; j < ((n-1)-k) ; j++)      //Subtracting "k" is significant: In bubble sort, bigger entries will bubble to the right. They will not swap anymore. Those entries are home, don't disturb them. 
    {
        
       
        if (values[j] > values[j+1])
        {
            temp = values[j];
            values[j] = values[j+1];
            values[j+1] = temp;
        }
    
       
    }
    
    if (temp == 0)                            //if temp is 0, exit the loop. Array is already sorted! 
    break;
    }
 
 
  /**
   * for (int s = 0; s <n; s++)    //To see the actual sorted array, uncomment it.
   * printf("%i ", values[s]);
   */
   
  
    return;
    
}