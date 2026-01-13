## 函数原型
```C
char * strstr ( const char *str1, const char * str2);
```
- Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
## 样例
```C
#include <stdio.h>
#include <string.h>
int main() {
	char* a= strstr("nihaoya","hao");
	printf("%s", a);
}
```
```C
haoya
```
## 模拟实现
```C
char* m_strstr_1(char* str1, const char* str2) {
	char* h = str1;
	int i = 0;
	while (*h) {
		i = 0;
		while (*(str2+i)) {
			if (*(h + i) == *(str2 + i)) {
				i++;
			}
			else break;
		}
		if(!*(str2 + i)) return h;
		h++;
	}
	return NULL;
}
```
这是我写的第一个版本，有一些小问题，我对其进行了修改。
```C
char* m_strstr_2(char* str1, const char* str2) {
	if (str1 == NULL) return NULL;
	if (str2 == NULL || *str2 == '\0') return str1;
	char* h = str1;
	while (*h) {
		const char* p1 = h;
		const char* p2 = str2;
		while (*p1 && *p2 && (*p1 == *p2)) {
			p1++;
			p2++;
		}
		if(!*p2) return h;
		h++;
	}
	return NULL;
}
```
- 对两个字符串进行了空指针检查，防止对于空指针的解引用！
- 最外层是防止`h`走到结束，里层是确保`p1`和`p2`对应元素在范围内相同
- 如果`p2`对应元素是字符结束的话，那么久说明找到了