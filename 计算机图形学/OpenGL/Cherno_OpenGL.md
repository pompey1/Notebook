# OpenGL是一种规范
他没有确定代码和任何类似的事情，他是一种规范，比如：

这个函数应该存在，需要什么参数，并且返回这个值

OpenGL的具体实现由你的显卡驱动来实行，包括具体代码的编写

# 着色器
传统OpenGL和现代OpenGL最大的区别就是可编程的Shader，Shader是一段程序，是在你的GPU上运行的代码

# 状态机
OpenGL作为一个状态机工作，在CPU发出drawcall指令之前，就需要把所有状态都传给OpenGL

alt + shift可以选定矩形区域来CV

# Vertex并不是Position
顶点不仅可以包含位置信息，他还可以包含更多Vertex Attributes（顶点属性）

他可能包括位置，法线，纹理坐标，颜色，by normals，切线

顶点位置并不是主键，主键不能重复，但是顶点位置重复是常事