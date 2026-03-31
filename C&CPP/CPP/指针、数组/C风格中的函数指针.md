## 基础使用
```CPP
void Print(int data)
{
	std::cout << "TestData:" << data << "\n";
}
```
现有此函数，函数指针的类型为：`void(*)(int)`。尝试将此指针分配给某个变量。
### 直接使用
```CPP
void(*fun)(int) = Print;
fun(3);
```
这个`fun`就是函数指针变量。
### 通过`auto`
```CPP
auto fun = Print;
fun(3);
```
编译器可以自动帮我们推导出类型。请不要加括号，如果加了圆括号会被视为调用。

### 通过`typedef`
```CPP
typedef void(*PrintFun)(int);
PrintFun fun = Print;
fun(3);
```
这里的语法比较特殊：`typedef void(*PrintFun)(int);`中的`PrintFun`才是自定义的类型名称。
### 通过`using`
```CPP
using PrintType = void(*)(int);
PrintType fun= Print;
fun(3);
```
同理。
## 例子
```CPP
#include <iostream>
#include <vector>
void Print(int val)
{
	std::cout << "val:" << val << "\n";
}
void Fun(std::vector<int>& vec, void(*Print)(int))
{
	for (int val:vec)
	{
		Print(val);
	}
	
}
int main()
{
	std::vector<int> vec = {1, 0, 11, 6, 8};
	Fun(vec, Print);
}
```
### 改版：通过lambda匿名函数
```CPP
Fun(vec, [](int val){std::cout << "val:" << val << "\n"; });
```
这样就完成了改进，点击[[../Lambda（匿名函数）|Lambda（匿名函数）]]获取更多。