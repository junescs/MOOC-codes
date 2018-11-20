# Questions

## What's `stdint.h`?

It is a library which contains BMP-related data types based on Microsoft's own.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

They are aliases for C/C++ primitive data types. The purpose of using such declarations is those numbers literally indicate how many bits they can allocate.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

Byte: 1byte(8bits); DWORD: 4bytes(32bits); LONG: 4bytes(32bits); WORD: 2bytes(16bits).

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM(ASCII)/42, 4D(decimal)/0x42 0x4D(hexadecimal).

## What's the difference between `bfSize` and `biSize`?

bfsize refers to the size of the bmp file (size of the picture itself(pixels + padding) & bitmapfileheader & bitmapinfoheader) whereas bisize means the size of the bmp header information(aka 40bytes).

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB with the origin at the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

The value of biBitCount.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

In line 24, it returns an error indicating that the program is unable to open the source image file while in line 32 it tells an error of failing to create a bmp file for output.

## Why is the third argument to `fread` always `1` in our code?

Because there is only one object (bitmapfileheader) to be read.
The function fread() reads [nmemb] elements of data, each [size] bytes long.
The library bmp.h has set up the elements of bitmapfileheader which contains only one structure.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

The value of int padding will be 3 bytes.

## What does `fseek` do?

It is to skip over the bytes of padding and look for the next pixel.
stream - file stream to modify
offset - number of characters to shift the position relative to origin
origin - position to which offset is added. It can have one of the following values: SEEK_ SET, SEEK_ CUR, SEEK_END
By using fssek, it sets the file position indicator for the file inptr to the value pointed to by padding.
The new position, measured in bytes, is obtained by adding padding bytes to the position specified by SEEK_CUR.

## What is `SEEK_CUR`?

SEEK_CUR means the current position indicator.
When it is used, the new position is exactly [offset] (here is the padding) bytes measured from the current file position.