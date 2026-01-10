strlen()是一个用来计算字符串长度的库函数。需要字符串以'\0'结尾，会计算'\0'前的元素个数。**注意**：不包含'\0'。
## 函数原型

```C
size_t strlen ( const char * str );
```
值得注意的是，他的返回值是一个`size_t`类型的值，也就是无符号整型。如果用`3-6`得到的会是一个很大的正数。这个const可以使得str指向的元素无法通过指针修改。但是str自己是可以被修改的。
## 模拟实现
### count计数器法
```C
int m_strlen_1(const char* str) {
	int count = 0;
	while (*str++ != '\0'){
		count++;
		//str++; 这个累加可以整合在条件判断中
	}
	return count;
}
```
上面这个写法可以得出正确结果，但是可能会产生误解。虽然str指针多移动了一个，但是count循环并没有执行，所以得出的答案是对的。不推荐这么写。
```C
int m_strlen_1(const char* str) {
	int count = 0;
	while (*str) {
		count++;
		str++;
	}
	return count;
}
```
这样写就非常清晰啦。
### 指针减法
```C
int m_strlen_2(const char* str) {
	const char* h = str;
	while(*str) str++;
	return str - h;
}
```
### 递归的实现
#### 无限递归的陷阱
```C
int m_strlen_3(const char* str) {
	if (*str) {
		return 1 + m_strlen_3(str++);
	}
	return 0;
}
```
会产生无限递归的主要原因就是在于`str++`，因为这是后缀递增，所以先把str的值传过去，再递增。所以下一层的递归用的还是原值。
```C
int m_strlen_3(const char* str) {
	if (*str) {
		return 1 + m_strlen_3(++str);
	}
	return 0;
}
```
这样做的话就正确了。但是也不好，因为修改了str的值。虽然在此环境下影响不大，但是依旧是个潜在的出错点。
#### 正确的实现
```C
int m_strlen_3(const char* str) {
	if (*str) {
		return 1 + m_strlen_3(str+1);
	}
	return 0;
}
```