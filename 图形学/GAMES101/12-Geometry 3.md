# 网格细分 Mesh Subdivision

# Loop Subdivision（和循环没有关系）

先将一个三角形按照边上的中点分割成四个三角形

细分得到的顶点，通过两个相邻三角形四个顶点加权平均确定位置

原始顶点，通过将所有周围原始顶点（包括自己）加权平均确定位置

# Catmull-Clark Subdivision

Loop细分只能处理三角面，Catmull-Clark Subdivision可以处理General Mesh

度degree不为4的点称之为奇异点 Extraordinary Vertex

Non-Squad Mesh的顶点都为奇异点，用Squad Mesh细分Non-Squad Mesh以后会产生新的奇异点

Squad Mesh方便布线和循环

# 网格细分 Mesh Simplicaiton

LOD的平滑过渡仍然是个难题

# 边坍缩 Edge Collapsing

将每条边的二次度量误差排序，从误差最小的边开始坍缩

一条边坍缩以后所有边的二次度量误差都得重新计算，所以需要使用优先队列存储二次度量误差：既能判断最小值，又能动态更新其他值

# 网格规则化 Mesh Regularization