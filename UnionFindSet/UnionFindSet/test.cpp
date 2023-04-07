//�Ƶ����ֺͣ���Ȩ���鼯��
#include <iostream>
#include <vector>
using namespace std;
//����x�ڵ��������ĸ��ڵ㣬������·��ѹ��
int findRoot(int x, vector<int>& parent, vector<int>& weight) {
    if (parent[x] != x) { //ѹ��
        int tmp = parent[x]; //��¼x�ڵ�ĸ��ڵ�
        parent[x] = findRoot(parent[x], parent, weight); //��x�ڵ����ӵ����ڵ��£��ݹ��Ҹ��ڵ㣩
        weight[x] += weight[tmp]; //x�ڵ��Ȩֵ+=ԭ���ڵ��Ȩֵ���ݹ��ҵ����ڵ��x�ڵ�ĸ��ڵ��Ѿ������ӵ����ڵ����ˣ�
    }
    return parent[x];
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> parent(n + 1); //��¼ÿ���ڵ��������ĸ��ڵ�
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    vector<int> weight(n + 1, 0); //��¼ÿ���ڵ㵽�丸�ڵ��Ȩֵ
    for (int i = 0; i < m; i++) {
        int l, r, s;
        cin >> l >> r >> s;
        int lParent = findRoot(l - 1, parent, weight), rParent = findRoot(r, parent, weight); //ע��l-1
        //�ϲ�l-1�ڵ��r�ڵ����ڵ�������
        if (lParent != rParent) {
            parent[lParent] = rParent; //��l-1�ڵ����ڵ����ϲ���r�ڵ����ڵ���
            weight[lParent] = weight[r] + s - weight[l - 1]; //����l-1�ڵ��������ĸ��ڵ��Ȩֵ
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        //��ȡl-1�ڵ㵽r�ڵ㷽���Ȩֵ
        int lParent = findRoot(l - 1, parent, weight), rParent = findRoot(r, parent, weight); //ע��l-1
        if (lParent != rParent) //����ͬһ����
            cout << "UNKNOWN" << endl;
        else
            cout << weight[l - 1] - weight[r] << endl;
    }
    return 0;
}
//��Ŀ����Ҫ�����˵��ֵ������1-1����ĺͣ����Խڵ���Ŵ�0��ʼ
//l->rת��Ϊl-1->r���ܹ�������Ӧ������
