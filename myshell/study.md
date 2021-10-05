# Shell Study

## C 库函数

### C 标准库 - <stdio.h>

## 函数指针数组

<!-- https://zhuanlan.zhihu.com/p/136615909 -->

### 概念

- **函数指针：** 一个指向函数入口地址的指针。一般用函数名表示。
- **函数指针数组：** 元素为函数指针的数组。转移表。c 语言中函数不可以定义为数组，只能通过定义函数指针来操作。

### 函数指针数组的使用例子

```c
#include <stdio.h>
#include <stdlib.h>

int fun1(int n)
{
    printf("func1: %d\n", n);
    return n;
}

int func2(int n)
{
    printf("func2: %d\n", n);
    return n;
}

int main()
{
    int (*a[2])(int); // 定义保存了两个函数指针的数组
    a[0] = func1;
    a[1] = func2;
    a[0](1);
    a[1](2);

    return 0;
}
```

`int (*a[2])(int)` 数组保存指针，什么样的指针呢？

> 形如 `int func(int input)`的 func 函数指针，形参为 int 变量，返回 int 变量。
>
> 因此，数组保存的是形参为单一 int 变量和返回值为 int 值的函数指针

### 注意事项

**正确使用函数指针数组的前提条件是，这若干个需要通过函数指针数组保存的函数必须有相同的输入、输出值。**
