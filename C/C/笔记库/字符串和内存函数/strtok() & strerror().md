## strtok()

### 函数原型
```C
char * strtok ( char * str, const char * sep );
```
- `sep`是一个字符串，是分隔符的集合，将其首元素地址传入
- `str`是待分割的字符串
1. 如果第一个参数不是`NULL`，那么将在`str`中找到第一个分隔标记，将其变为`\0`，并返回首元素地址。并存储被修改位置的地址到一个静态变量中。
2. 如果第一个参数是`NULL`，那么他将读取这个被修改位置。从这个地方开始寻找下一个分隔符，并做类似第一点的操作。返回这一个部分的首元素地址。

**注意：** 这个函数会修改`str`字符串的内容，`str`必须是要可读可改的！
### 样例
#### 错误示范
```C
int main() {
	char* a = strtok("i-love.u","-.");
	printf("%s", a);
}
```
我第一次是这么使用的，实际上程序会崩溃。因为我传过去了一个存储在只读取的不可修改的字符串字面量。而这个函数会修改这个字符串！
#### 正确示范
```C
int main() {
	char str[] = "i-love.u";
	char* a = strtok(str,"-.");
	printf("%s\n", a);
	a = strtok(NULL, "-.");
	printf("%s\n", a);
	a = strtok(NULL, "-.");
	printf("%s\n", a);
}
```
```C
i
love
u
```
## strerror()
C语言的库函数在执行失败的时候，都会设置错误码。
### 函数原型
```C
char * strerror ( int errnum );
```
- 返回的是一个地址，应该用%s打印
- 使用的时候需要头文件`#include <errno.h>`
### 样例
```C
#include <stdio.h>
#include <errno.h>
int main(){
	printf("%s", strerror(1));
}
```
```C
Operation not permitted
```