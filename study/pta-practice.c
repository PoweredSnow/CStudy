#include <stdio.h>
#include <stdlib.h>

int MaxSubseqSum2(int a[], int n);
int MaxSubseqSum3(int list[], int n);
int DivideAndConquer(int list[], int left, int right);
int Max3(int a, int b, int c);

int main(void)
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    int result = MaxSubseqSum2(a, n);
    printf("%d\n", result);

    return 0;
}

/* 最大子列和问题 */
int MaxSubseqSum2(int a[], int n)
{   /* T(N) = O(N^2) */
    int ThisSum ,Maxsum = 0;
    for (int i = 0; i < n; i++) { /* i 是子列左端位置 */
        ThisSum = 0; /* a[i] 到 a[j] 的子列和 */
        for (int j = i; j < n; j++) { /* j 是子列右端位置 */
            ThisSum += a[j];
            /* 对于相同的 i, 不同的 j, 只要在 j-1 次循环的基础上累加 1 项即可 */
            if (ThisSum > Maxsum) /* 如果刚得到的这个子列和更大 */
                Maxsum = ThisSum; /* 则更新结果 */
        }
    }
    return Maxsum;
}

int DivideAndConquer(int list[], int left, int right)
{   /* 分治法求 list[left] 到 list[right] 的最大子列和 */
    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /* 存放跨分界线的结果 */

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if (left == right) { /* 递归的终止条件，子列只有1个数字 */
        if (list[left] > 0) return list[left];
        else return 0;
    }

    /* 下面是“分”的过程 */
    center = (left + right) / 2; /* 找到中分点 */
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer(list, left, center);
    MaxRightSum = DivideAndConquer(list, center, right);

    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for (i = center; i >= left; i--) { /* 从中间线向左扫描 */
        LeftBorderSum += list[i];
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    } /* 左边扫描结束 */

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for (i = center; i <= right; i++) {
        RightBorderSum += list[i];
        if (RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    } /* 右边扫描结束 */

    /* 下面返回“治”的结果 */
    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int Max3(int a, int b, int c)
{   /* 返回 3 个整数中的最大值 */
    return a > b ? a > c ? a : c : b > c ? b : c;
    // ? ? ?
}

int MaxSubseqSum3(int list[], int n)
{   /* 保持与前2种算法相同的函数接口 */
    return DivideAndConquer(list, 0, n-1);
}
