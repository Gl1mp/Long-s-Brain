`qsort()`是一个快速排序的函数。
函数原型为：
``` C
void qsort (void* base, size_t num, size_t size,int (*compar)(const void*,const void*));
```
更多的细节参见：[CPlusPlus中的详细介绍](https://cplusplus.com/reference/cstdlib/qsort/?kw=qsort)
此处我也作简单的介绍：
- base：作为一个起始的指针，会被强制转化为void*
- num：要排序的元素个数
- size：每个元素的大小
- compar：指向一个比较函数，这个函数能对两个元素进行比较，并返回一个整型值：如果大于零，交换；小于等于零，不交换。
## 调用qsort()
```C
/* qsort example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main ()
{
  int n;
  qsort (values, 6, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}
```
`10 20 25 40 90 100`为输出。因为a＞b的时候为1，那么需要交换，所以结果是升序的。
## 造一个类似的泛型冒泡排序😀

```C
#include <stdio.h>
#include <string.h>  // 为 memcpy

int compare_ints(const void* a, const void* b) {
    int va = *(const int*)a;
    int vb = *(const int*)b;
    return (va > vb) - (va < vb); // 2
}

void Swap(void* a, void* b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

void qbubble_sort(void* base, size_t num, size_t size, int (*cmp)(const void*, const void*)) {
    for (size_t i = 0; i < num; i++) {
        for (size_t j = 0; j < num - 1 - i; j++) {
            void* elem1 = (char*)base + j * size;
            void* elem2 = (char*)base + (j + 1) * size;
            if (cmp(elem1, elem2) > 0) {  // 1
                Swap(elem1, elem2, size);
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    size_t num = sizeof(arr) / sizeof(arr[0]);
    qbubble_sort(arr, num, sizeof(arr[0]), compare_ints);
    for (size_t i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```
### 修正&说明
1. if判断的逻辑是0和非0，应该明确写大于零，否则会有逻辑错误。
2. 这里是怕相减产生一个过大的数，修改成这样就不会有溢出int的问题了
### 整体逻辑
首先我知道了元素的首地址，但是是一个void*，无法进行解引用操作，所以需要size大小，来获取下一个地址。其他的就是一个基本的冒泡外壳。

### 本地.c文件
![[../../代码库/泛型冒泡排序.c|泛型冒泡排序]]