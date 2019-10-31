#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("Enter a +ve number : ");
    while (n <= 0)
    {
        n = get_int("Enter a +ve number : ");
    }
    if(n>0 && n<=8)
    {    
         for(int i = 0; i<n; i++)
         {
             for (int j = 0; j<=(n - i); j++)
                 printf(" ");
             for (int j = 0; j<=i; j++)
                  printf("#");
          
             printf("\n");
            }
                       
    }
}
            
      
        
