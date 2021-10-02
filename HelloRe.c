#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char s[] = {0x3A, 0x36, 0x37, 0x3B, 0x80, 0x7A, 0x71, 0x78, 0x63, 0x66,
                0x73, 0x67, 0x62, 0x65, 0x73, 0x60, 0x6B, 0x71, 0x78, 0x6A,
                0x73, 0x70, 0x64, 0x78, 0x6E, 0x70, 0x70, 0x64, 0x70, 0x64,
                0x6E, 0x7B, 0x76, 0x78, 0x6A, 0x73, 0x7B, 0x80};
    char a[] = {1, 2, 3, 4, 5};
    int v4 = 0;

    while (v4 < strlen(s))
    {
        for (int i = 0; i < strlen(a) && v4 < strlen(s); ++i)
        {
            s[v4++] -= a[i % 5];
            printf("%c", s[i]);
        }
    }
    printf("\n");

    /*
    int i;
    char s[36] = {0};
    char v7[8];
    char v8[28];

    strcpy(v7, "harambe");
    strcpy(v8, ":\"AL_RT^L*.?+6/46");
    for (i = 0; i < strlen(v8); ++i)
    {
        s[i] = (v7[i % 7]) ^ v8[i];
        printf("%c", s[i]);
    }
    printf("\n");
    */

    /*
    int first = 0xcafe;
    int second;
    char argv[] = "h4cky0u";
    unsigned int hash = first * 31337 + 8 * 11 + strlen(argv) - 1615810207;

    printf("Get your key: ");
    printf("%x\n", hash);
    */

    /*
    // 0x0 BUUCTF reverse_2
    char flag[] = "{hacking_for_fun}";
    for (i = 0; i <= strlen(flag); i++)
        if (flag[i] == 105 || flag[i] == 114)
            flag[i] = 49;
    */

    return 0;
}
