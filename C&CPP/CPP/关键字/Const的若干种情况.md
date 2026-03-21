## 函数的参数类型
### 传值
如果是传值调用，那么函数参数中的`Const`修饰就没有特别大的必要性了。因为无论如何影响到只有副本而不会影响到原始数据。
### 传值/引用
在此处的修改会直接影响到原始数据。我们的原则是：**如果不修改原始数据，那么一定要加上`Const`。**原因很简单：
- 防止修改原始数据
- 可以调用非`Const`对象和`Const`对象。
如果不加，那么只能调用非`Const`对象，因为你没有保证不修改`Const`对象。我们给出一个例子：
```CPP
// 原来的版本：只能接受非const对象
static void Print(Player& player) {}

// const版本：可以接受const和非const对象
static void Print(const Player& player) {}

int main() {
    Player p1;           // 非const对象
    const Player p2;     // const对象
    
    Print(p1);  // ✅ 两个版本都可以
    Print(p2);  // ❌ 非const版本不行，✅ const版本可以
}
```
## 构造函数
构造函数请不要加`Const`参数！因为他是用来初始化对象的，也就是说他一定会对对象进行修改。
## 对象和成员函数
还是核心的一句话：**`const`对象只能调用`const`成员函数**。而非`Const`对象则可以调用`Const`和非`Const`成员函数
```CPP
class Player {
    String m_name;
public:
    void func1() {}           // 非const成员函数
    void func2() const {}     // const成员函数
};
int main() {
    const Player p1;  // const对象
    p1.func1();  // ❌ 错误：const对象不能调用非const成员函数
    p1.func2();  // ✅ 正确：const对象可以调用const成员函数
    
    Player p2;     // 非const对象
    p2.func1();  // ✅ 正确
    p2.func2();  // ✅ 正确（非const对象可以调用const成员函数）
}
```
## 方法前后的两个Const
### 方法后的Const
```CPP
class ScopedPtr {
    Entity* m_ptr;
public:
    // 版本A：非const成员函数
    Entity* operator->() { 
        cout << "非const版本\n";
        return m_ptr; 
    }
    
    // 版本B：const成员函数  
    const Entity* operator->() const { 
        cout << "const版本\n";
        return m_ptr; 
    }
};
```
对于这个重载运算符我们给出了两个版本。一个是给Const对象使用的，一个是给非Const对象使用的。请注意：
```CPP
Entity* operator->() const;
const Entity* operator->() const;
```
这两个其实是无法共存的，因为他们的函数签名是一致的。也就是说编译器不关心返回值的类型，他们两个函数列表相同且都是Const函数（看括号后的那个Const），所以无法共存。那我们知道非Const方法可以调用Const和非Const方法，那么他会优先调用和自己类型相近的非Const方法。而调用Const方法是下策。
### 方法前的Const
这个Const其实是用来限定返回值的。我们希望Const的变量传回去依旧还是Const。但是通过添加这个Const不能用来区分两个函数。