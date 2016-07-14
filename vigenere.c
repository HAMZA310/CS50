#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


int main (int argc, string argv[])                                                   
{
 
  
  
  if (argc!=2)
      {
       printf("Usage: /home/cs50/pset2/vigenere <keyword>\n");
      return 1;
      }
       int u=strlen(argv[1]);
      
     for (int i=0, n=strlen(argv[1]); i<n; i++)
     {   
      
      if (!isalpha(argv[1][i]))
     {
      printf("Keyword must only contain letters A-Z and a-z\n");
      return 1;
      
     }
      else if ((argv[1][i])>=65 && argv[1][i]<=90)
     {
       argv[1][i]=argv[1][i]-65; 
     }
      
      else if ((argv[1][i])>=96 && argv[1][i]<=122)
     { 
      argv[1][i]=argv[1][i]-97;
      
     }
    
     }  

  
  
                                        
  string s=GetString();
 
  int k,x=0;
 
 
  for (int j=0, n=strlen(s); j<n; j++) 
  {
   
 
   if (s[j]>= 65 && s[j]<=90) 
  { 
   k=x%u;
   s[j]=s[j]-65;
   s[j]=(s[j]+argv[1][k])%26;
   s[j]=s[j]+65;
   printf("%c", s[j]);
   x=x+1;
  }
  

  else if (s[j]>= 97 && s[j]<=122) 
  { 
   k=x%u;
   s[j]=s[j]-97;
   s[j]=(s[j]+argv[1][k])%26;
   s[j]=s[j]+97;
   printf("%c", s[j]);
   x=x+1;
  } 
  
  else 
  printf("%c", s[j]);
  
  }
  
   printf("\n");
   return 0;
}



































