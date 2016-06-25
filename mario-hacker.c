#include<stdio.h>
#include<cs50.h>

int main()
{
    
    // Mario's pyramid--Hacker Edition
    
    int height;                         
    
     do                                     //this loop handles height input (0-23)
        {        
            printf("Tell me height (0-30)\n");
            height= GetInt();
        }
        while (height<0 || height>23);
       
       
    for (int i=1; i<=height; i++)    
    {
        for (int j=height-i; j>0; j--)     // print spaces--if height is 5, we are gonna need 4 spaces
    {
        printf(" ");   
    }     
    
        for (int k=i; k>0; k--)           //print #s, on the first line, we need 1 hash, i.e. k=i. On the second line 2 #s.... so on and so forth
    {
        printf("#");    
    }
    
    
    printf("  ");                          // constant space between two pyramids... no need of any standalone loop
    
     for (int k=i; k>0; k--)               // prints #s similar to what we printed above, but without printing spaces so that our pyramid could face opposite side.
    {
        printf("#");    
    }
    
    
     printf("\n");                         // comes to new line, and the whole thing follows up again. 
     
    }
}



