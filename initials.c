#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>


int main ()           //CAPITALIZE INITIALS ONLY 
{
    
  
    string s =GetString();
    
   
    printf("%c", toupper(s[0]));   //capitalize first character of first name
     
 
   
    for (int i=0, n=strlen(s); i<n; i++)   
   { 
      
      if (s[i]==' ')                        //End of first name 
      {
          printf("%c",toupper(s[i+1]));
      }
      
   }
  
    printf("\n");
  
  
  
}
