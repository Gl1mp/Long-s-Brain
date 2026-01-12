## memcpy()
该函数的作用是进行内存层面上的复制。在C的标准中，不需要实现内存重叠区的正确复制。在VS2026自带的库函数中，可以正确进行重叠部分的正确复制。
### 函数原型
```C
void * memcpy ( void * destination, const void * source, size_t num );
```
- `num`是要复制多少字节的内容
- 返回一个指针指向`destiantion`的首元素
### 样例
```C
#include <stdio.h>
#include <string.h>
int main() {
	char a[] = "abcdef";
	char b[] = "xyz";
	char *c = memcpy(a,b,2);
	printf("%s\n", c);
	int d[] = {1, 2, 3, 4};
	int e[] = {91, 78};
	int *f = memcpy(d, e, 4);
	int i = 0;
	while (i < 4) {
		printf("%d ",d[i]);
		i++;
	}
}
```
```C
xycdef
91 2 3 4
```
参数`num`是字节数！不要输入成拷贝的元素个数了。
### 模拟实现
```C
void* m_memcpy_1(void* dest, const void* src, size_t num) {
	char* d = (char*)dest;
	const char* s = (const char*)src;
	while (num--) {
		*d++ = *s++;
	}
	return dest;
}
```
`*d++`先用d的值解引用，再自增。实际上是后缀自增先运算，但是此时还没有改变值。
## memmove()
该函数是memcpy()的升级版，他解决了内存重叠区复制的问题。
### 函数原型
```C
void * memmove ( void * destination, const void * source, size_t num );
```
### 样例
```C
int main() {
	char a[] = "abcdef";
	char* c = memmove(a+1, a, 2);
	printf("%s\n", a);
}
```
```C
aabdef
```
### 模拟实现
## memcmp()
### 函数原型
```C

```
### 样例
```C
```
```C
```
### 模拟实现