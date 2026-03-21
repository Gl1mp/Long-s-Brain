## 基础使用案例
```CPP
#include <iostream>
#include <vector>

struct Gp
{
	int m_x, m_y, m_z;
};

std::ostream& operator<<(std::ostream& stream, const Gp& gp)
{
	stream << gp.m_x << " " << gp.m_y << " " << gp.m_z;
	return stream;
}

int main()
{
	std::vector<Gp> gps;
	gps.push_back({0, 1, 7});
	gps.push_back({2, 1, 6});
	for (Gp& v:gps)
	{
		std::cout << v << "\n";
	}
	gps.erase(gps.begin()+1);
	gps.clear();
}
```
这是一个完整的例子。
### 引用
`for (Gp& v:gps)`如果不加`&`那么会把所有都复制到块作用域内，这是非常大的开销。
### erase的参数
我们可以通过阅读函数签名来知道我们需要的是什么类型的参数。
## 从两个特征来优化Vector
我们先看这些代码：
```CPP
#include <iostream>
#include <vector>

struct Gp
{
	int m_x, m_y, m_z;
	Gp(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z) {}
	Gp(const Gp& gp)
		: m_x(gp.m_x), m_y(gp.m_y), m_z(gp.m_z)
	{
		std::cout << "copied!";
	}
};

int main()
{
	std::vector<Gp> gps;
	gps.push_back({0, 1, 7});
	gps.push_back(Gp{1, 2, 3});
}
```
此时我们的输出结果是3，那么结果为什么是3呢？我们需要分段来解析。这个`vector`对象（也就是这里的`gps`）实际上是存在于`main函数栈帧`上。而我们的`vector`实际数据是在堆上。也就有了以下步骤：
1. `main函数栈帧`中创建`临时对象{0,1,7}`
2. `vector`在堆上分配内存，通过*拷贝构造*复制`临时对象{0,1,7}`（默认容量为1）
3. 销毁`临时对象{0,1,7}`
4. 创建`临时对象Gp{1,2,3}`
5. `vector`发现容量不够，需要扩容。在堆上分配新内存（容量变为2）
6. 将旧元素从旧堆内存拷贝到新堆内存，此处调用了*一次拷贝构造函数。通过*拷贝构造*将临时对象复制到了新堆中
7. 释放旧堆内存
8. 临时对象销毁
这样就是一个完整的过程了，总共涉及了3次拷贝构造。
### 优化
通过上面的那个例子，我们清楚的知道了问题就在于预先设置的容量不足、无意义的拷贝构造。接下来对其进行优化即可。
#### 设置默认容量
```CPP
gps.reserve(3);
```
我们可以通过这个命令来预先设置堆的大小。
#### 直接在堆中创建对象
```CPP
gps.emplace_back(1, 2, 3);
```