//coding practice from CS50_2018 on edX
//Implement a program that resizes BMPs
//have to ensure it is a 24-bit uncompressed BMP 4.0

// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy n infile outfile\n");
        return 1;
    }

    //Ensure the positive number <= 100
    int n = atoi(argv[1]);

    if (n < 0 || n > 100)
    {
        fprintf(stderr, "The number must between 0-100\n");
        return 5;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //Create new BI&BF for outfile
    BITMAPFILEHEADER out_bf = bf;
    BITMAPINFOHEADER out_bi = bi;

    // determine padding for scanlines for infile
    int padding_in = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //determine outfile's width and height.
    out_bi.biWidth *= n;
    out_bi.biHeight *= n;

    // determine padding for scanlines for outfile
    int padding_out = (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //determine the outfile's size and image size
    out_bi.biSizeImage = (out_bi.biWidth * sizeof(RGBTRIPLE) + padding_out) * abs(out_bi.biHeight);
    out_bf.bfSize = out_bi.biSizeImage + 54;//BF + BI = 54

    // write outfile's BITMAPFILEHEADER
    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //scan the same scanline n times
        for (int k = 0; k < n; k++)
        {
            //get the current position of input file pointer to copy it n times
            fseek(inptr, 54 + (bi.biWidth * 3 + padding_in) * i, SEEK_SET);

            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                //write the pixel n times to outfile
                for (int x = 0; x < n; x++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

            }

            // skip over padding, if any
            fseek(inptr, padding_in, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int l = 0; l < padding_out; l++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
