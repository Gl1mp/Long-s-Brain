`Mutable`一共有两种用法，第一种用法是在[[基础Const#第三种用法]]中有提到。而第二种则是在`Lambda`函数中使用。
## 引用捕获
```CPP
#include <iostream>
int main()
{
	int x = 3;
	auto Info = [&]()
	{
		x++;
	};
	Info();
	std::cout << x << "\n";
}
```
Lambda函数中如果是引用的话那么可以直接执行自增。
## 按值捕获
但是如果是传值的话将不能自增，必须将其给一个新的局部变量再进行自增。
```CPP
int x = 3;
auto Info = [=]()
{
	int y = x;
	y++;
};
```
在此处我们可以使用`Mutable`关键字使得传值时可以直接自增。
```CPP
int x = 3;
auto Info = [=]() mutable 
{
	x++;
};
```
这样问题就解决了。