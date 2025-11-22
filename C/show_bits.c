/*
Show the bits of a number:
The bits of a number are the binary representation of the number.
*/

#include <stdio.h>

int main()
{
    int num = 0x12345678;

    for (int i = 31;i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }

    printf("\n");
    return 0;
}

/*
OUTPUT:
00010010001101000101011001111000
*/