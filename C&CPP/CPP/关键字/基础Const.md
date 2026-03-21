Const大抵有三种用法。值得一提的是，类似于可见性，这是一个编译时的用法。这是一种承诺，更利于开发者和其他想要阅读代码的人来看。
## 前两种用法
我们用一个简单的程序来直观描述。[[../../C/笔记库/指针、数组与传参/常量指针和指针常量|常量指针和指针常量]]中也提及过这一点。
```CPP
constexpr int val = 3;

const int* val1 = new int;
// *val1 = 3; 不能修改
val1 = &val;

int* const val2 = new int;
// val2 = &val; 不能修改
*val2 = 5;
```
实际上这非常简单，如果const关键字在`*`前面，则指指针指向的内容无法修改。如果在`*`后面那么指指针变量自己的内容无法修改，也就是说指向的地址无法被修改。
### 组合
```CPP
const int* const val = 5;
```
如果我们用两层const来约束这个变量，那无论是自身指向的地址还是指向地址中的内容都无法修改了。
## 第三种用法
第三种用法适用于类中的成员方法/函数。我们仍举例说明
```CPP
#include <iostream>
#include <string>

class Example
{
private:
	int m_x,m_y;
	mutable int m_val;
public:
	Example()
	{
		m_x = 0;
		m_y = 0;
		m_val = 0x8ADC837;
	}
	void setPosition(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	void print() const
	{
		m_val = 4;
		std::cout << m_x << " " << m_y << "\n";
	}
};

void Print(const Example& example)
{
	example.print();
}

int main()
{
	Example example;
	example.setPosition(3, 5);
	Print(example);
}
```
这是一个完整的CPP程序。观察`TAG1`和`TAG2`处，这两个地方要同时为`Const`不然会产生错误。在方法后的`Const`代表着这里面不会修改类中的数据。但是如果有特例一定要修改怎么办？我们可以效仿`TAG3`中的将变量设置为`Mutable`，这样即使在Const中也可以修改啦。我们在[[Mutable]]中更详细的讲述了关键字`Mutable`。