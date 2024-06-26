BFS（Breadth-First Search，广度优先搜索）是一种用于图的遍历算法，它能够系统地探索图中的节点。
BFS从选定的节点（通常称为“根”或“起始节点”）开始，先访问当前深度级别的所有相邻节点，然后再移动到下一个深度级别的节点。
BFS的遍历方式类似于“宽度优先”，它从当前节点出发，逐层向外探索。

### 主要概念：

1. **队列：** BFS使用队列来存储待遍历的节点。节点按照它们被遍历的顺序加入队列，然后以先进先出（FIFO）的方式进行处理。

2. **已访问集合：** 为了避免多次处理同一节点（这可能导致在含有环的图中出现无限循环），BFS维护一个已访问节点的集合。这确保每个节点最多被访问一次。

### BFS的步骤：

1. **开始：** 选择一个起始节点并将其入队，同时标记为已访问。

2. **遍历：** 从队列的前端出队一个节点并进行访问。

3. **入队相邻节点：** 将被出队节点的所有未访问相邻节点入队，并标记为已访问。

4. **重复：** 持续执行上述步骤，直到队列为空。这意味着所有可达节点都已被访问。

### 性质和应用：

- **最短路径：** BFS保证在无权重图中找到起始节点与任何其他可达节点之间的最短路径（以边数计）。
这个性质使得BFS在迷宫中寻找最短路径或者确定网络中节点之间的距离等任务中非常有用。

- **内存需求：** 与深度优先搜索（DFS）相比，BFS通常需要更多的内存，因为它需要存储当前级别的所有节点。这对于大型图可能是一个问题。

- **应用：** BFS在各种应用中都有广泛的应用，包括网络路由协议、社交网络分析、网络爬虫以及解决谜题，如在迷宫中寻找最短路径或解决魔方。

总的来说，BFS是一种基础算法，为许多其他图算法奠定了基础，在计算机科学及相关领域有着广泛的应用。

下面给出BFS的模板
> Python

``` Python3
from collections import deque
n = # 图点的个数
m = # 图边的个数
st = [False for _ in range(n)]    # 状态数组，表示每个节点的使用状态
h = [[] for _ in range(n)]        # 存放图
def dfs(start):
    q = deque([(start)])
    st[start] = True
    while q:
        t = q.popleft()
        # 遍历节点t的所有相邻的所有节点
        for node in h[t]:
            # 如果当前节点没有被使用过
            if not st[node]:
                # 将当前节点标记为使用过
                st[node] = True
                # 将当前节点放入队列中，变为就绪态
                q.append(node)
```
