# Questions

## What's `stdint.h`?

This is a header file that provides access to several functions related to integer standards, such as uint8_t, uint32_t, int32_t, and uint16_t . These functions specify the exact width of integers. These functions allow code to be more portable by setting widths dependent on the processor targets (whether 32 bit or 64 bit, for example).

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

With `uint8_t` you give 1 byte or 8 bits to the data type. Which corresponds to 255 in decimal. Because 2^8 = 256, but because you start counting from 0 its 256-1 = 255.  
The `uint16_t` gives you 2 bytes or 16 bits for your data type. Which corresponds to 65535 in decimal. Because 2^16 = 65536, but again like with the uint8_t you start counting from 0. So it's 65536-1 = 65535.  
The u in `unit8_t` stands for unsigned. So int32_t is a signed 16 bits int. They're useful to tell the processor how much maximum memory each data type can have.


## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

`BYTE` is a 8-bit unsigned value.  
`DWORD` is a 32-bit unsigned integer. Because `DWORD` is unsigned, its first bit is not reserved for signing.  
`LONG` is a 32-bit signed integer. The first bit is the signing bit.  
`WORD` is a 16-bit unsigned integer. Its first bit is also not reserved for signing.  

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first 2 bytes are called the header field. This is used to identify the BMP and DIB file is 0x42, 0x4D in hexadecimal or BM in ASCII.

## What's the difference between `bfSize` and `biSize`?

`bfSize` is the size of the bitmap file. Which includes the headerfiles.  
`biSize` is the size of the `BITMAPINFOHEADER` header file.

## What does it mean if `biHeight` is negative?

If `biHeight` is negative, `biCompression` must either be `BI_RGB` or `BI-BITFIELDS`, it also indicates a top-down DIB.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount`, the `biBitCount` member of the `BITMAPINFOHEADER` structure determines the number of bits that define each pixel and the maximum number of colors in the bitmap.

## Why might `fopen` return `NULL` in `copy.c`?

`fopen` might return `NULL` when it can't find the file or when there's not enough memory to open the file.

## Why is the third argument to `fread` always `1` in our code?

The third argument gives the number of elements. Since we only read 1 file it's 1.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

TODO

## What does `fseek` do?

TODO

## What is `SEEK_CUR`?

TODO
