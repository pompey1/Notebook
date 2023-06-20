# 不同语言的内存分配
C++和C#可以在堆上和栈上自由选择
Java只能分配在堆上

# new和delete
每次你使用new，都必须有配套的delete，如果是new [],则必须有配套的delete []

new有一个placement new的技巧，在new后面加上小括号和变量，但现在暂时不用管。

# 隐式转换和explicit关键字
用explicit关键词修饰的函数必须显式地调用构造函数

# 运算符重载

# this关键字

# C++对象的生存期