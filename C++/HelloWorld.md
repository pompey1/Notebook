CPP与C#、Java的**不同**：
+ C#和Java这种运行在虚拟机上的语言需要先被翻译成中间语言，然后再由虚拟机来执行机器指令
+ CPP是本地语言（native language），直接被不同平台的编译器翻译成机器语言来执行
+ 如果你的CPP写得很烂的话，执行效率反而会不如Java和C#

Visual Studio：

你可以将解决方案理解为工作台，项目就是一组二进制文件

HelloWorld：
``` C++
#include <iostream>

int main() {
	std::cout << "Hello World" << std::endl;
	std::cin.get();
}
```
build生成exe后缀名的文件（可由计算机直接执行的二进制文件）
