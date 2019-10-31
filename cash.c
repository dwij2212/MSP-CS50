#include <stdio.h>
#include <math.h>
#include <cs50.h>
int main()
{
    float change = get_float("Enter change : ");
    while ((int)change < 0)    //for +ve change only
    {
        change = get_float("Positive number : ");
    }
    int cents = round(change * 100);
    int count = 0;    // number of coins
    while (cents >= 25) //count 25 penny coins
    {
        cents = cents - 25;
        count++;
    }
    while (cents >= 10) //count 10 penny coins
    {
        cents = cents - 10;
        count++;
    }
    while (cents >= 5) // count 5 penny coins
    {
        cents = cents - 5;
        count++;
    } 
    while (cents >= 1) //count 1 peny coins
    {
        cents = cents - 1;
        count++;
    }
    printf("%d \n", count); //print coins
}
