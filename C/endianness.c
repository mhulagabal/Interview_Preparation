/* Check the endianness of the machine */
/* The endianness of a machine is the order in which bytes are stored in memory.
 * There are two types of endianness: little endian and big endian.
 * Little endian is the order in which bytes are stored in memory from the least significant byte to the most significant byte.
 * Big endian is the order in which bytes are stored in memory from the most significant byte to the least significant byte.
 * The endianness of a machine is determined by the architecture of the machine. */

#include <stdio.h>

int main()
{
    int num = 1;

    if(*((char *) &num) == 1)
    {
        printf("little endian\n");
    }
    else
    {
        printf("big endian\n");
    }
}
