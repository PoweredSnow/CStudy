#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    int score;
    char name[16];
} STU;

int min(int x, int y, int z)
{
    if (x > y)
        x = y;
    if (x > z)
        x = z;
    return x;
}

int Neri;
char flag[10] = {'f', 'l', 'a', 'g', '=', '{', '}'};
int isSky;

int main(void)
{
    int n;
    STU *p = NULL;
    puts("How many students do you want to have?");
    scanf("%d", &n);
    printf("Plz input %d students' score and name.\n", n);
    p = (STU *)calloc(n, sizeof(STU));
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %s", &p[i].score, p[i].name);
    }
    int num = min(6, 1, 8);
    printf("Succesfull Added!\n");
    free(p);
    return 0;
}
