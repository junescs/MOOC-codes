//coding practice from CS50_2018 on edX
//Implement a program that calculates the minimum number of coins required to give a user change.

#include <cs50.h>
#include <stdio.h>
#include <math.h>

//Define the value for each coins, penny = 1 so no need to define
#define quarter 25;
#define dime 10;
#define nickel 5;

int main(void)
{
    //Declare variables
    float change;
    int totalcents, leftover, quartercount, dimecount, nickelcount, coinscount;

    //Prompt for a valid number
    do
    {
        change = get_float("How much change you owned: ");
    }
    while (change < 0);

    //Convert dollars given to cents for counting
    totalcents = (int)round(change * 100);

    //Count how many quarter needed
    quartercount = totalcents / quarter;
    leftover = totalcents % quarter;

    //Count how many dime needed
    dimecount = leftover / dime;
    leftover = leftover % dime;

    //Count how many nickel needed
    nickelcount = leftover / nickel;
    leftover = leftover % nickel;

    //Count how many coins needed in total (included pennies)
    coinscount = quartercount + dimecount + nickelcount + leftover;

    printf("Here you go, %i coin(s) in total\n", coinscount);

}
