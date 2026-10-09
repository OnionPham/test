from collections import deque

t = int(input())

for _ in range(t):
    input()

    n, k = map(int, input().split())

    graph = [[] for _ in range(n + 1)]
    degree = [0] * (n + 1)

    for _ in range(n - 1):
        u, v = map(int, input().split())

        graph[u].append(v)
        graph[v].append(u)

        degree[u] += 1
        degree[v] += 1

    q = deque()

    for v in range(1, n + 1):
        if degree[v] <= 1:
            q.append(v)

    removed = 0

    for _ in range(k):

        if not q:
            break

        size = len(q)

        for _ in range(size):
            u = q.popleft()
            removed += 1

            for v in graph[u]:
                degree[v] -= 1

                if degree[v] == 1:
                    q.append(v)

    print(n - removed)