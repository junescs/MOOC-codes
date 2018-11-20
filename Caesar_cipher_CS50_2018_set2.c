//coding practice from CS50_2018 on edX
//Implement a program that encrypts messages using Caesar’s cipher
//which encrypts messages by "rotating" each letter by (number) positions

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Check if only one command-line argument entered
    if (argc != 2)
    {
        //If not, prompt this sentence, and return 1 stating an error happened
        printf("Error! You need to enter a positive key number.\n");
        return 1;
    }
    else
    {
        //Convert the key into an integer
        //designated key to argv[1]
        int key = atoi(argv[1]);

        //Run if the key number is positive
        if (key > 0)
        {
            //Prompt for plaintext to cipher
            string plaintext = get_string("plaintext: ");

            printf("ciphertext: ");

            //Loop for cipher, character by character
            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                //Check if the character is alphabet and uppercase
                if (isalpha(plaintext[i]) && isupper(plaintext[i]))
                {
                    //Just type 'A' will auto transfer into ASCII num(65)
                    //-65 will make it into the range of ASCII
                    //To %26 is to control the num within 26 alphabets
                    //+65 will convert it back to ASCII range
                    printf("%c", (plaintext[i] - 'A' + key) % 26 + 'A');
                }
                else if (isalpha(plaintext[i]) && islower(plaintext[i]))
                {
                    printf("%c", (plaintext[i] - 'a' + key) % 26 + 'a');
                }
                else//Print any non-alphabetical character without converting
                {
                    printf("%c", plaintext[i]);
                }
            }
        }
    }
    printf("\n");
    return 0;
}
