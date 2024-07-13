// 并查集模版(牛客)
// 路径压缩 + 小挂大
// 测试链接 : https://www.nowcoder.com/practice/e7ed657974934a30b2010046536a5372

#include <iostream>
using namespace std;

const int MAXN = 1000001;

int father[MAXN];
int fsize[MAXN];
int stack[MAXN];
int n;

void build() {
    for (int i = 0; i <= n; i++) {
        father[i] = i;
        fsize[i] = 1;
    }
}

int find(int i) {
    int stackSize = 0;
    while (i != father[i]) {
        stack[stackSize++] = i;
        i = father[i];
    }
    while (stackSize > 0) {
        father[stack[--stackSize]] = i;
    }
    return i;
}

bool isSameSet(int x, int y) {
    return find(x) == find(y);
}

void unionSets(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        if (fsize[fx] >= fsize[fy]) {
            fsize[fx] += fsize[fy];
            father[fy] = fx;
        }
        else {
            fsize[fy] += fsize[fx];
            father[fx] = fy;
        }
    }
}

int main() {
    scanf("%d", &n);
    build();
    int m;
    scanf("%d", &m);
    while (m--) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            printf("%s\n", isSameSet(x, y) ? "Yes" : "No");
        }
        else {
            unionSets(x, y);
        }
    }
    return 0;
}