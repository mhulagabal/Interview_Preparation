/* Convert the endianness of a number */

#include <stdio.h>

int convert_endianness(int num)
{
    int b0, b1, b2, b3;

    b0 = (num & 0x000000FF) >> 0;
    b1 = (num & 0x0000FF00) >> 8;
    b2 = (num & 0x00FF0000) >> 16;
    b3 = (num & 0xFF000000) >> 24;

    return (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;
}

int main()
{
    int num = 0x12345678;

    printf("Original number in hexadecimal : %x\n", num);

    num = convert_endianness(num);

    printf("Converted number in hexadecimal: %x\n", num);

}

/* 
OUTPUT:
Original number in hexadecimal : 12345678
Converted number in hexadecimal: 78563412
*/
