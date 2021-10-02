#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void unexitFile(void)
{
    FILE *pf;
    pf = fopen("unexit.txt", "rb");
    if (NULL == pf)
    {
        fprintf(stderr, "错误号：%d\n", errno);
        perror("通过 perror 输出错误");
        fprintf(stderr, "打开文件错误：%s\n", strerror(errno));
    }
    else
    {
        fclose(pf);
    }
}

void divisorIsZero(void)
{
    int dividend = 20;
    int divisor = 0;
    int quotient;

    if (divisor == 0)
    {
        fprintf(stderr, "除数为 0 退出运行...、\n");
        exit(EXIT_FAILURE);
    }
    quotient = dividend / divisor;
    fprintf(stderr, "quotient 变量的值为： %d\n", quotient);

    exit(EXIT_SUCCESS);
}

int learnPerror(void)
{
    FILE *fp;

    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        perror("Error");
        return -1;
    }
    fclose(fp);
}

int main(void)
{
    unexitFile();
    divisorIsZero();
    // learnPerror();

    return 0;
}
