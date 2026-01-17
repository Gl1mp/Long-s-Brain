realloc()用来调整动态内存空间大小。`realloc(NULL,<size>)`其实就和`malloc(1,<size>)`功能相同了。
## 函数原型
```C
void* realloc (void* ptr, size_t size);
```
- 为`num`个大小为`size`的元素开辟空间
- 指针`ptr`指向动态内存空间，如果开辟失败，那么返回空指针（需要空指针检查）
- 注意返回值是`void*`，使用时需要强制类型转换
## 工作机制
如果空间是变小的，一般会尝试在原空间内缩小。如果新的空间大于原空间，一般情况下，他将找一个全新的大小为`size`的空间，将`ptr`指向的空间内容全部复制过去，再返回`void*`类型的新空间指针。
## ⚠警告
**请不要将返回的指针直接赋值给原来的指针变量！如果返回了空指针，将直接导致内存泄露！**
## 样例
该样例在[[malloc() & free()#样例]]的基础上继续改进。
```C
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *p = (int*)malloc(4 * sizeof(int));
	if(!p){
		perror("初次分配内存空间时发生了致命错误");
		return 1;
	}
	int* q = (int*)realloc(p, 5 * sizeof(int));
	if (!q) {
		perror("重新分配内存空间时发生了致命错误");
		free(p);
		return 1;
	}
	p = q;
	int i = 0;
	for (i = 0; i < 5; i++) {
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
0 1 2 3 4
```
- 这里用`perror`替代了`strerror(errno)`，因为VS认为后者不安全。前者会自动加上冒号和错误信息
- 在每次返回指针的时候都要注意类型转换和空指针检查
- 在重新分配错误的时候，要注意释放掉`p`，因为他依然是有效的
- 拿临时变量接重新分配后的指针，不然容易导致内存泄露
- `return 1`用来返回错误码，告诉操作系统发生了错误