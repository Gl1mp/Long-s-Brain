Lambda 是编译器自动帮你生成一个匿名类并创建对象，这个对象重载了 `operator()` 使得能像函数一样调用它。
## 捕获列表
`[]`就是捕获列表。常见的方式有：
- = 捕获自动变量的值（请注意此时内部的副本为Const）
- & 以引用的方式传入自动变量
当然也可以直接传入某个特定变量，例如：`[a]`或`[&a]`。
## 典例
```CPP
#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	auto fun = [](int val){return val > 3;};
	std::vector<int> vec= {1,2,5,10,4};
	auto it = std::find_if(vec.begin(),vec.end(),fun);
	std::cout << *it;
}
```
这个程序实现了找到`vec`中第一个大于三的数。
## 常见问题
### 值传递下的外部变量副本无法修改
 ```CPP
int a = 3;
auto fun = [=](int val){a = 5;};
 ```
按值传递的时候，默认变量都是Const的。如果想要修改的话，需要额外添加一个`Mutable`关键字：
```CPP
auto fun = [=](int val) mutable {a = 5;};
```
就可以解决啦。