## 简单示例
```CPP
#include <chrono>
#include <iostream>
#include <thread>
int main()
{
	using namespace std::literals::chrono_literals; // 用来解析1s
	auto start = std::chrono::high_resolution_clock::now(); // 计算初始时间
	std::this_thread::sleep_for(1s);
	auto end = std::chrono::high_resolution_clock::now(); // 计算结束时间
	std::chrono::duration<float> duration = end - start; // 计算时长
	std::cout << duration;
}
```
## 完整示例
### 实现函数/程序计时
我们可以通过结构体的构造和析构特性来计时。
### 计时器结构体
```CPP
struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() * 1000.0f;
		std::cout << "time(ms):" << ms << "\n";
	}
};
```
### 在被计时函数中插入构造语句
```CPP
void Print()
{
	Timer timer;
	for (int i = 0; i < 100; i++)
	{
		std::cout << "I HATE YOU!\n";
	}
}
```
### 调用函数开始计时
```CPP
int main()
{
	Print();
}
```