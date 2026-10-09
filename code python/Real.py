#nhap
n, m = map(int, input().split())
N = 2 ** n
a = list(map(int, input().split()))
tree = [0] * (4 * N)
#
def build(node, l, r, level):
    if l == r:
        tree[node] = a[l]
        return

    mid = (l + r) // 2

    build(node * 2, l, mid, level - 1)
    build(node * 2 + 1, mid + 1, r, level - 1)

    if level % 2 == 1:
        # tầng này dùng OR
        tree[node] = tree[node * 2] | tree[node * 2 + 1]
    else:
        # tầng này dùng XOR
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1]


def update(node, l, r, pos, value, level):
    if l == r:
        tree[node] = value
        return

    mid = (l + r) // 2

    if pos <= mid:
        update(node * 2, l, mid, pos, value, level - 1)
    else:
        update(node * 2 + 1, mid + 1, r, pos, value, level - 1)

    if level % 2 == 1:
        tree[node] = tree[node * 2] | tree[node * 2 + 1]
    else:
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1]


build(1, 0, N - 1, n)

for _ in range(m):
    p, b = map(int, input().split())

    p -= 1

    update(1, 0, N - 1, p, b, n)

    print(tree[1])