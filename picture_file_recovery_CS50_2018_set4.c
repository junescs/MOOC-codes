//coding practice from CS50_2018 on edX
//Implement a program that recovers JPEGs from a deleted file

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }

    // open input file
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    //"unsigned char" declare variable for byte
    //memory card with FAT file system whose "block size" is 512 bytes
    //to temporarily store memory
    unsigned char buffer [512];

    //declare variable for jpeg counter
    int jpg_found = 0;

    //declare a variable of 8 characters
    char jpg_name[8];

    //initialize the recover_file
    FILE *recover_file = NULL;

    //Start to iterate the blocks
    while (fread(&buffer, 512, 1, raw_file))
    {
        //if found a new jpg (check the first 4 bytes)
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            //close the recover file if it is opened
            if (recover_file != NULL)
            {
                fclose(recover_file);
            }

            //create a new jpg file
            sprintf(jpg_name, "%03d.jpg", jpg_found);

            //open a jpg file for writing,
            //"a" = append data to the end of an already present file,
            //or create an empty file if filename doesn’t exist.
            recover_file = fopen(jpg_name, "a");

            jpg_found++;

        }
        //keep writing if the file is opened
        if (recover_file != NULL)
        {
            fwrite(&buffer, 512, 1, recover_file);
        }
    }

    //iteration done, close all files
    fclose(recover_file);
    fclose(raw_file);
    return 0;
}
