#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h> 

                                                                                  

int main (int argc, string argv[])                                             
{
   
   int k;
   if (argc!=2)                     //handles lack of argv[1]
   {
      printf("Usage: /home/cs50/pset2/caesar <key>\n");
      return 1;
   }
   else
    
    k=atoi(argv[1]); 
    string s= GetString();         
                              
                              /*
                        
                                1- START WITH ASCII VALUES
                                2- ENCIPHER ALPHABETICAL TEXT
                                3- PRINT IN ASCII VALUES
                               
                              */
 
  
  
  for (int i=0, n=strlen (s); i<n; i++)             //enciphering uppercase letters 
 {
     if (s[i]>= 65 && s[i]<=90)                     //or use isupper in ctype.h
    {
     s[i]=s[i]-65;
     s[i]= ((s[i]+k)%26);
     s[i]=s[i]+65;
     
     printf("%c", s[i]);
    }
    
    
    else if (s[i]>=97 && s[i]<=122)                  //enciphering lowercase letters---(islower can be used)
    {
    s[i]=s[i]-97;
    s[i]=(s[i]+k)%26;
    s[i]=s[i]+97;
   
    printf("%c", s[i]);
    
    }
    
    else
    printf("%c", s[i]);                             //returning non-alphabetical chars unaltered                                  
      
    
    }
    printf("\n");
    
    
}
