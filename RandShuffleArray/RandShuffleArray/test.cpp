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
//        list<int> lt(_nums.begin(), _nums.end()); //链表，方便删除
//        //随机从没有取过的元素中取一个作为第i个元素
//        for (int i = 0; i < _nums.size(); i++) {
//            int j = rand() % (lt.size()); //对链表的长度取模
//            auto iter = lt.begin();
//            advance(iter, j); //迭代器前进j次
//            _nums[i] = *iter;
//            lt.erase(iter); //将取过的元素从链表中删除
//        }
//        return _nums; //返回打乱后的数组
//    }
//private:
//    vector<int> _nums; //记录数组
//    vector<int> _original; //记录数组的初始状态
//};
//洗牌算法
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
        //每次从下标为[i, n-1]的数中随机选一个数放到下标为i的位置
        for (int i = 0; i < _nums.size(); i++) {
            int j = i + rand() % (_nums.size() - i); //随机下标
            swap(_nums[i], _nums[j]); //与第i个数交换
        }
        return _nums;
    }
private:
    vector<int> _nums; //记录数组
    vector<int> _original; //记录数组的初始状态
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
