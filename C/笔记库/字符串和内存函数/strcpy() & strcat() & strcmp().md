这三个函数都不安全，因为都是长度不受限制的
## strcpy()
### 函数原型
```C
char* strcpy(char * destination, const char * source );
```
- 返回的是一个地址，指向destination的首元素
- 需要两个参数，destination的首元素地址和source的首元素地址
- 这是一个不安全的函数，因为长度不受限制
- **他会复制source中的'\0'**
### 样例
```C
#include <stdio.h>
#include <string.h>
int main() {
	char a[10] = "abc";
	char b[10] = {0};
	strcpy(b,a);
	printf("%s",b);
}
```
### 模拟实现
```C
char* m_strcpy_1(char* destination, const char* source) {
	char* h = destination;
	while (*source) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = *source;
	return h;
}
```
在编写的时候我遇到了以下几个问题：
- 忘记返回值，代表着destination的首元素
- **忘记复制source的最后一个'\0'，这是一个很严重的问题！**
这是我试着写的第一个代码。接下来要呈现一个更完美、专业的模拟实现：
```C
char* m_strcpy_2(char* dest, const char* src) {
	char* ret = dest;
	assert(dest && src);
	while ((*dest++ = *src++)) {
		;
	}
	return ret;
}
```
- 这个版本进行了断言检查，避免了空指针。
- 在一行中同时完成了：赋值、判断、累加。
- src会多走一次，指向了'\0'后面的元素。但是没有解引用，也没有返回，问题不大。
## strcat()
### 函数原型
```C
char * strcat ( char * destination, const char * source );
```
- strcat是一个追加函数，将source的内容追加到destination的尾上。
- destination不能加const，因为他需要被修改
- 返回值是destination的首元素地址
### 样例
```C
#include <stdio.h>
#include <string.h>
int main() {
	char a[10] = "abc";
	char b[10] = "xyz";
	strcat(b,a);
	printf("%s",b);
}
```
### 模拟实现
```C
char* m_strcat_1(char* dest, const char* src) {
	assert(dest && src);
	char* ret = dest;
	while (*dest) dest++;
	while ((*dest++ = *src++)) {
		;
	}
	return ret;
}
```
这个函数的实现与[[strcpy() & strcat() & strcmp()#模拟实现]]高度类似。只是先找到了dest的尾部。
## strcmp()
### 函数原型
```C
int strcmp ( const char * str1, const char * str2 );
```
这个函数主要实现两个字符串的比较。
- str1大于str2，返回正数
- str1小于str2，返回负数
- str1等于str2，返回0
### 样例
```C
#include <stdio.h>
#include <string.h>
int main() {
	char a[10] = "abc";
	char b[10] = "xyz";
	int ret = strcmp(a,b);
	printf("%d", ret);
}
```
### 模拟实现
```C
int m_strcmp_1(const char* str1, const char* str2) {
	assert(str1 && str2);
	while (*str1 && (*str1 == *str2)) {
		str1++;
		str2++;
	}
	return (*(unsigned char*)str1 - *(unsigned char*)str2);
}
```
这样的实现是非常好的，主要有以下几个理由：
- 两个const，不允许通过指针修改str1和str2
- `*str1 && (*str1 == *str2)`可以保证不出现`\0`且两个字符相同
- 在返回的时候避免了繁琐的比较逻辑，直接进行相减
- 转化为无符号字符型指针，这样更加标准化！
- 预期中是不考虑正负的，全都是有效位

## 更加安全的实现
我们可以用`strncpy` `strncat` `strncmp`来实现长度控制。这样是更加安全的。
他们都通过`size_t num`来控制长度，这样就不会发生越界行为了。
### strncpy()
```C
char * strncpy ( char * destination, const char * source, size_t num );
```
如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后边追加0，直到num个。
### strncat()
```C
char * strncat ( char * destination, const char * source, size_t num );
```
**`strncat` 总是确保结果字符串以 `\0` 结尾**，无论 `src` 的长度是否足够。
### strncmp()
```C
int strncmp ( const char * str1, const char * str2, size_t num );
```
比较到出现另个字符不一样或者一个字符串结束或者num个字符全部比较完。