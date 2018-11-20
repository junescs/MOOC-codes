//coding practice from CS50_2018 on edX
//printing a half-pyramid of not greater than 8x23

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //declare variable
    int height;

    //Prompt for a number
    do
    {
        height = get_int("Enter a positive number no greater than 23: ");
    }

    //Condition for validation
    while (height < 0 || height > 23);

    //Build the half pyramid row by row(i) using loop
    for (int i = 0; i < height; i++)
    {
        //Print spaces(j) for each column
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        //Print hashes(k) for each column
        for (int k = 0; k < i + 2; k++)
        {
            printf("#");
        }
        printf("\n");//Start to print at the next new row
    }
}
