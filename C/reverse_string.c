/*
Reverse a string from a given string
The string is reversed by swapping the characters from the start and the end of the string.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter a string : ");
    scanf("%s", str);

    int len = strlen(str);
    for(int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    printf("Reversed string: %s\n", str);
    return 0;
}

/*
OUTPUT:
Enter a string : Vihaan
Reversed string: naahiV
*/
