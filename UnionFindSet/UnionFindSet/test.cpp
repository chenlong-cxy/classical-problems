//推导部分和（带权并查集）
#include <iostream>
#include <vector>
using namespace std;
//查找x节点所在树的根节点，并进行路径压缩
int findRoot(int x, vector<int>& parent, vector<int>& weight) {
    if (parent[x] != x) { //压缩
        int tmp = parent[x]; //记录x节点的父节点
        parent[x] = findRoot(parent[x], parent, weight); //将x节点链接到根节点下（递归找根节点）
        weight[x] += weight[tmp]; //x节点的权值+=原父节点的权值（递归找到根节点后，x节点的父节点已经被链接到根节点下了）
    }
    return parent[x];
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> parent(n + 1); //记录每个节点所在树的根节点
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    vector<int> weight(n + 1, 0); //记录每个节点到其父节点的权值
    for (int i = 0; i < m; i++) {
        int l, r, s;
        cin >> l >> r >> s;
        int lParent = findRoot(l - 1, parent, weight), rParent = findRoot(r, parent, weight); //注意l-1
        //合并l-1节点和r节点所在的两棵树
        if (lParent != rParent) {
            parent[lParent] = rParent; //将l-1节点所在的树合并到r节点所在的树
            weight[lParent] = weight[r] + s - weight[l - 1]; //更新l-1节点所在树的根节点的权值
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        //获取l-1节点到r节点方向的权值
        int lParent = findRoot(l - 1, parent, weight), rParent = findRoot(r, parent, weight); //注意l-1
        if (lParent != rParent) //不在同一棵树
            cout << "UNKNOWN" << endl;
        else
            cout << weight[l - 1] - weight[r] << endl;
    }
    return 0;
}
//题目中需要包含端点的值，比如1-1区间的和，所以节点序号从0开始
//l->r转化为l-1->r，能够包含对应边在内
