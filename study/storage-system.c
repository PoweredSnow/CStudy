#include <stdio.h>

union oneMem
{
    char a;
    short b;
    int c;
};

int main(int argc, char const *argv[])
{
    union oneMem om;
    om.c = 0x12345678;

    printf("a = %x\n", om.a);
    printf("b = %x\n", om.b);
    printf("c = %x\n", om.c);

    if (om.a == 0x78)
        printf("little endian!\n");
    else if (om.a == 0x12)
        printf("big endian!\n");
    else
        printf("error\n");

    return 0;
}

