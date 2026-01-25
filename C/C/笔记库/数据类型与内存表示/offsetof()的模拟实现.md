该函数用来求类型中某一个成员的偏移量。
## 模拟实现
```C
#include <stdio.h>
//#include <stddef.h>
#define OFFSETOF(type, member) (size_t)&(((type*)0)->member)
struct S {
	int a;
	char b;
	int c;
};
int main() {
	printf("%u\n", OFFSETOF(struct S,a));
	printf("%u\n", OFFSETOF(struct S,b));
	printf("%u\n", OFFSETOF(struct S,c));
}
```
如果要用本身的函数offsetof()，那么可以用头文件`#include <stddef.h>`，参数与模拟实现的一致。在模拟过程中，我发现如果最后的member再套一层括号，会编译错误，是因为本身结构体访问的时候就不能有括号！该模拟的原理就是假定0地址处有一个这样的结构体，通过成员的的地址就可以知道成员的偏移量了。