/*
Print the before and after of the main function
*/

#include <stdio.h>
#include <stdlib.h>

/*
Runs in Turbo C compiler only
#pragma startup before_main
#pragma exit after_main
*/

// GCC-specific attribute: runs before main
void before_main() __attribute__((constructor));
void before_main()
{
    printf("Before main\n");
}

// GCC-specific attribute: runs after main
void after_main() __attribute__((destructor));
void after_main()
{
    printf("After main\n");
}

int main()
{
    printf("Inside main\n");
    return 0;
}

/*
OUTPUT:
Before main
Inside main
After main
*/