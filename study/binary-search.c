#include<stdio.h>
#include<math.h>

int binary_search(int arr[], int len, int target);
int binary_search_alternative(int arr[], int len, int target);

int main(void)
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = binary_search(arr, 10, 9);
    printf("%d\n", result);

    return 0;
}

/**
 * 二分查找
 * 非降有序数组 arr, 数组大小 len, 目标数 target
 * 最坏情况的时间复杂度 T(n) = O(log(n))
 */
int binary_search(int arr[], int len, int target)
{
    int mid;
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        mid = floor((left + right) / 2);
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binary_search_alternative(int arr[], int len, int target)
{
    int mid;
    int left = 0;
    int right = len - 1;
    while (left != right) {
        mid = ceil((left + right) / 2);
        if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    if (arr[left] == target)
        return left;
    return -1;
}
