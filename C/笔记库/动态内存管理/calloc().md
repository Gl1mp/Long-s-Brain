calloc()是同样用来开辟动态内存空间的函数。
## 函数原型
```C
void* calloc (size_t num, size_t size);
```
- 为`num`个大小为`size`的元素开辟空间
- 返回一个指针指向开辟的空间，如果开辟失败，那么返回空指针（需要空指针检查）
- 注意返回值是`void*`，使用时需要强制类型转换
- **重要特性**：会将开辟的空间全部初始化为0
## 样例
```C
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *p = (int*)calloc(5, sizeof(int));
	if (!p) {
		perror("在初始化的时候发生了致命错误");
		return 1;
	}
	int i = 0;
	for (i = 0; i < 3; i++) {
		*(p + i) = i;
	}
	for (i = 0; i < 5; i++) {
		printf("%d ", * (p + i));
	}
	free(p);
	p = NULL;
	return 0;
}
```
```C
0 1 2 0 0
```
- 不要忘记返回值类型转换
- 一定要记得释放
- `p`释放后要置为空指针
- 有`return 0`的代码更加标准
- 检查是否返回空指针

你会发现后两个是0，因为该函数会自动初始化。