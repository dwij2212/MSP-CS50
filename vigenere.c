#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int shift(char c);

int main(int argc, string argv[])
{
    //checks for number of arguements
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
        
    int x;
    
    for(int i = 0; argv[1][i] != '\0' ; i++)
    {
       if(!(isalpha(argv[1][i])))
       {
           return 1;
       }
    }
    //gets string from user
    string ch = get_string("Enter text : ");
    
    int n = strlen(ch);
    
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        if (argv[1][j] == '\0')
        {
            j = 0;
        }
        
        x = shift(argv[1][j]);
        
        if(!(isalpha(ch[i])))
        {
            j--;
             continue;   
        }
       
        if (islower(ch[i]))
        {
                 //compares whether the key + char exceeds z or not and adjusts it accordingly
            if ((ch[i] + x) > 'z')
            {
                ch[i] = 'a' + x - 1 - ('z' - ch[i]);
            }
            else
            {
                ch[i] = (ch[i] + x);
            }
        }
        
        if(isupper(ch[i]))
        {
                 //compares whether the key + char exceeds z or not and adjusts it accordingly
            if ((ch[i] + x) > 'Z')
            {
                ch[i] = 'A' + x - 1 - ('Z' - ch[i]);
            }
            else
            {
                ch[i] = (ch[i] + x);
            }
        }
    }
    printf("ciphertext: %s\n", ch);
}

int shift(char c)
{
    int val;
    //converts to integer
    if (c >= 'a' && c <= 'z')
    {
        val = c - 'a';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        val = c - 'A';
    }
    //returns 1 in case any other character than a number is entered
    else 
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    return val;
}
