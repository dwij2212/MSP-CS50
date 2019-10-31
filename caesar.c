#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(int argc, string argv[])
{    
    //checks for number of arguements
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    
    //to find the key
    int x = atoi(argv[1]);
    
    //to check if key is +ve or not
    if (x < 0)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    
    //gets string from user
    string ch = get_string("Enter text : ");
    
    int n = strlen(ch);
    int i = 0;
    
    
    
    while (x > 26)
    {
        x -= 26;
    }
    for (i = 0; i < n; i++)
    {
        if (!((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 'A' && ch[i] <= 'Z')))
        {
            continue;
        }
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
        
    printf("ciphertext: %s\n", ch);
    return 0;
}
