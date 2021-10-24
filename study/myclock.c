#include <stdio.h>
#include <time.h>
#include <math.h>
#define MAXN 10 /* 多项式最大项数，即多项式阶数+1 */
#define MAXK 1e7 /* 被测函数最大重复调用次数 */

double f1(int n, double a[], double x);
double f2(int n, double a[], double x);
double measuringTime(double a[], int flag);


clock_t start, stop;
/* clock_t 是 clock 函数返回的变量类型 */
double duration;
/* 记录被测函数运行时间，以秒为单位 */
int main(void)
{
    int i;
    double a[MAXN]; /* 存储多项式的系数 */
    for (i = 0; i < MAXN; i++)
        a[i] = (double)i;
    measuringTime(a, 1);
    measuringTime(a, 2);

    return 0;
}

double f1(int n, double a[], double x)
{
    int i;
    double p = a[0];
    for (i = 1; i <= n; i++)
        p += (a[i] * pow(x, i));
    return p;
}

double f2(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for (i = n; i > 0; i--)
        p = a[i - 1] + x*p;
    return p;
}

double measuringTime(double a[], int flag)
{
    int i;
    /* 不在测试范围内的准备工作写在 clock() 调用之前 */
    start = clock();
    /* 把被测函数加在这里 */
    if (flag == 1) {
        for (i = 0; i < MAXK; i++) /* 重复调用函数以获得充分多的时钟打点数 */
            f1(MAXN - 1, a, 1.1);
    } else if (flag == 2) {
        for (i = 0; i < MAXK; i++)
            f2(MAXN-1, a, 1.1);
    }
    stop = clock();
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC / MAXK;
    /* 其他不在测试范围的处理写在后面 */
    printf("ticks1 = %f\n", (double)(stop - start));
    printf("duration1 = %6.2e\n", duration);
}
