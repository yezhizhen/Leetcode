import collections
class Solution:
    def criticalConnections(self, n, connections):
        # 生成邻接表
        graph = collections.defaultdict(list)
        for conn in connections:
            graph[conn[0]].append(conn[1])
            graph[conn[1]].append(conn[0])

        # 集合，注意排序让小的节点在前面，避免重复
        connections = set(map(tuple, (map(sorted, connections))))
        # DFS 访问每个节点的深度，只有访问过的路径有深度，初始化为 -1
        rank = [-1] * n

        def dfs(node, parent, depth):
            # 如果已经访问过该边，则已经记录了 rank
            if rank[node] >= 0:
                return rank[node]
            # 记录当前的 rank，默认会回溯 +1
            rank[node] = depth
            # 最大可能为 n
            min_depth = n
            for v in graph[node]:
                # 跳过父节点
                if v == parent:
                    continue
                # 获得子节点的最小深度
                back_depth = dfs(v, node, depth+1)
                # 子节点比当前深度小，显然是环
                if back_depth <= depth:
                    connections.discard(tuple(sorted((node, v))))
                # 当前节点的最小深度也要记录下来，以便把整个环去掉
                min_depth = min(min_depth, back_depth)
            # 返回给父节点
            print(node,min_depth)
            return min_depth
        dfs(0, -1, 0)
        return list(connections)

Solution().criticalConnections(4,[[0,1],[1,2],[2,0],[1,3]])