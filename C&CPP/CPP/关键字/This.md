`this` 指针是成员函数中指向当前对象自身地址的隐含常量指针。
## this指针的类型
`this`指针的类型由成员函数的`const`限定符决定
### const成员函数
```CPP
int GetX() const
{
	const Entity* e = this;
}
```
### 非const成员函数
```CPP
Entity(const int x, const int y)
{
	this->x = x;
	this->y = y;
	Entity* e = this;
}
```
他的使用场景很普遍。如果说你有一个叫`x`和`y`的成员变量，在成员方法中又有叫`x`和`y`的参数，我们就可以用`this->x`和`this->y`来区分开来他们。当然我们可以直接避免这种情况。
## 成员方法内部调用以自身类对象为参数的外部函数
假设我们有这样一个函数`void PrintEntity(const Entity& e);`，我们需要在方法内部调用这个函数。我们就可以用`PrintEntity(*this);`来调用啦。请注意静态方法是不能调用`this`指针的，因为这根本没有涉及到一个对象。