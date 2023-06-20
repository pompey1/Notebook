# 类和结构体外部使用static
这块内存只有这个**翻译单元**能看到
# 类和结构体内部使用static
这个类的所有实例都共享这块内存
```C++
class TestClass {
public:
	static int x, y;
	static void TestFunction() {
		std::cout << x + y << std::endl;
	}
};

int TestClass::x;
int TestClass::y;//这两个变量需要链接器连接

int main() {
	TestClass::x = 10;
	TestClass::y = 11;
	TestClass::TestFunction();
}
```

类中定义的**非静态**方法本质上是一种调用自身实例的静态方法，所以其实不是每个对象一个方法，而是方法以对象为传入参数

```C++
class TestClass{
private:
    int x,y;
public:
    static void TestFunciton(TestClass testClass){
       std::cout << testClass.x + testClass.y << std::endl;
    }
}
```

这里和Lua实现面向对象的思路是一样的，Lua通过    :   调用将自己作为参数传入方法，而C++自动帮你把自己的示例作为参数传递给了静态的方法

# local static
变量的生存期：变量实际存在的时间。（在他被删除之前，他会在内存当中存在多久？）

变量的作用域：可以访问变量的范围。

static修饰的变量生存期几乎和整个程序的生存期一样长，但是作用域仅限于他所在的函数。（也不一定是函数，可能是在任何位置）

> 定义类对象基本格式是：Student a；在定义之后就已经为a这个对象分配了内存，且为内存栈；

> 定义类指针基本格式是：Student b = new Student()；在定义b的时候并没有分配内存，只有执行new后才会分配内存，且为内存堆。

有点复杂，还没想明白

``` C++
#include <iostream>

class Singleton {
private:
	static Singleton* instance;
public:
	int a = 10;
	static Singleton Get222() {
		&instance->a;
		return *instance;
	}
	static Singleton& Get111() {
		return *instance;
	}
	//返回一个instance的引用
	void Hello() {
		std::cout << "Hello" << std::endl;
	}
};

Singleton* Singleton::instance = NULL;


int main() {
	Singleton test1 = Singleton::Get111();
	std::cout << test1.a << std::endl;
	Singleton test2 = Singleton::Get222();
	std::cout << test2.a << std::endl;
}
```