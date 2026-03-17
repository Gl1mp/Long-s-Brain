```CPP
enum Level : unsigned int { //enum 结构名 ： 整型的类型名
	A, // 默认从0开始递增
	B,
	C
};
int main() {
	Level level = B; // B对应的是1
	std::cout << level << std::endl; //输出1
}
```
通过以上这个例子，我们对`enum`有了更多深刻的认识。