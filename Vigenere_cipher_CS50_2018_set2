//coding practice from CS50_2018 on edX
//Implement a program that encrypts messages using Vigenère’s cipher
//which encrypts messages using a keyword

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Check whether one command-line argument entered
    if (argc != 2)
    {
        //If not, prompt this and report error
        printf("Enter one keyword only.\n");
        return 1;
    }

    else
    {
        //Check if only contains letters
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Enter alphabet only.\n");
                return 1;
            }
        }

    }

    //Get the value of keyword
    string keyword = argv[1];

    //Get the length of keyword
    int klength = strlen(keyword);

    //Get plaintext to cipher
    string plaintext = get_string("plaintext: ");

    //Output the ciphertext first
    printf("ciphertext: ");

    //Loop over each character in the plaintext
    for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++)
    {
        //Get the key code for the letter
        int key = keyword[j % klength];

        if (isupper(key))
        {
            key -= 65;
        }

        else if (islower(key))
        {
            key -= 97;
        }

        //Check for every character one by one
        if (isupper(plaintext[i]))
        {
            //refer to caesar.c
            printf("%c", (plaintext[i] + key - 'A') % 26 + 'A');

            //only ++ when used
            j++;
        }

        else if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] + key - 'a') % 26 + 'a');
            j++;
        }

        else
        {
            printf("%c", plaintext[i]);
        }

    }
    printf("\n");
    return 0;
}
