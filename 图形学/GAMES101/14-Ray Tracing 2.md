# 包围盒 Bounding Box

长方体的本质：Three Pairs Of Slabs的交集

最常用的包围盒：轴对齐包围盒 AABB Axis-Aligned Bounding Box

光线和AABB包围盒求交的方法：对每对Slab分别计算tmin和tmax，tenter（进入时间）三组tmin取最大，texit（离开时间）三组tmax取最小

当tenter小于texit并且texit大于0时，光线与包围盒AABB相交

轴对齐的平面光线相交运算相比于普通平面光线相交运算简化很多

# 直线的光栅化：Bresenham算法

# 网格 Build Acceleration Grid

Grid不能太稀疏，也不能太密集

# 空间划分 Spatial Partitions

Oct-Tree
KD-Tree  
BSP-Tree

# KD-Tree 预处理

先把场景的加速结构构建好，再进行渲染

网格数据存储在叶子节点中

KD-Tree的建立很难，因为判定一个三角形是否和一个立方体有交集很困难，所以这种结构最近十年越来越衰落

# Bounding Volumn Hierarchy

找到整个场景的包围盒

递归地将一系列对象划分为两个子集

重新计算子集的包围盒

在划分足够细致的情况下停止，将网格数据存储在叶子节点中

BVH对空间划分的包围盒有可能相交，要尽量减少空间上的重叠

如果划分一个节点？
- 选择划分的维度时，总是选择最长的轴
- 尽量划分为数量相等的物体，减少树结构的深度，使树更加平衡
- 利用快速选择 算法，可以用o(n)的时间复杂度获取中间大小的数字
