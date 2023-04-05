#include <iostream>
#include <vector>
#include <list>
#include <ctime>
using namespace std;
//class Solution {
//public:
//    Solution(vector<int>& nums)
//        :_nums(nums)
//        , _original(nums)
//    {
//        srand((unsigned int)time(nullptr));
//    }
//
//    vector<int> reset() {
//        copy(_original.begin(), _original.end(), _nums.begin());
//        return _nums;
//    }
//
//    vector<int> shuffle() {
//        list<int> lt(_nums.begin(), _nums.end()); //��������ɾ��
//        //�����û��ȡ����Ԫ����ȡһ����Ϊ��i��Ԫ��
//        for (int i = 0; i < _nums.size(); i++) {
//            int j = rand() % (lt.size()); //������ĳ���ȡģ
//            auto iter = lt.begin();
//            advance(iter, j); //������ǰ��j��
//            _nums[i] = *iter;
//            lt.erase(iter); //��ȡ����Ԫ�ش�������ɾ��
//        }
//        return _nums; //���ش��Һ������
//    }
//private:
//    vector<int> _nums; //��¼����
//    vector<int> _original; //��¼����ĳ�ʼ״̬
//};
//ϴ���㷨
class Solution {
public:
    Solution(vector<int>& nums)
        :_nums(nums)
        , _original(nums)
    {
        srand((unsigned int)time(nullptr));
    }

    vector<int> reset() {
        copy(_original.begin(), _original.end(), _nums.begin());
        return _nums;
    }

    vector<int> shuffle() {
        //ÿ�δ��±�Ϊ[i, n-1]���������ѡһ�����ŵ��±�Ϊi��λ��
        for (int i = 0; i < _nums.size(); i++) {
            int j = i + rand() % (_nums.size() - i); //����±�
            swap(_nums[i], _nums[j]); //���i��������
        }
        return _nums;
    }
private:
    vector<int> _nums; //��¼����
    vector<int> _original; //��¼����ĳ�ʼ״̬
};
int main() {
    vector<int> v = { 23,45,5,12,2,32,43,43 };
    Solution obj(v);
    vector<int> tmp = obj.shuffle();
    for (auto e : tmp) {
        cout << e << " ";
    }
    cout << endl;
    tmp = obj.reset();
    for (auto e : tmp) {
        cout << e << " ";
    }
    cout << endl;
    tmp = obj.shuffle();
    for (auto e : tmp) {
        cout << e << " ";
    }
    cout << endl;
    tmp = obj.reset();
    for (auto e : tmp) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
