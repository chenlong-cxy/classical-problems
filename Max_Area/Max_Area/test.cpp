#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
//单调栈
class Solution {
public:
	//矩阵中最大的矩形
	int maximalRectangle(vector<string>& matrix) {
		if (matrix.size() == 0)
			return 0;
		vector<int> heights(matrix[0].size(), 0); //直方图
		int maxArea = 0;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				if (matrix[i][j] == '1') //直方图中j位置的height加一
					heights[j]++;
				else //直方图中j位置的height清零
					heights[j] = 0;
			}
			//根据该直方图中最大矩形面积更新矩阵中最大的矩形面积
			maxArea = max(maxArea, largestRectangleArea(heights));
		}
		return maxArea;
	}
	//直方图最大矩形面积
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		stack<int> st; //栈中存储的是直方图中的下标，方便计算矩形的宽
		st.push(-1);
		int maxArea = 0;
		for (int i = 0; i < n; i++) {
			while (st.top() != -1 && heights[i] < heights[st.top()]) { //待入栈的数比栈顶的数小，说明找到了栈顶的数的右边界
				int h = heights[st.top()]; //矩形的高度
				st.pop();
				maxArea = max(maxArea, h*(i - st.top() - 1)); //矩形的宽度为待入栈的数的下标减去新栈顶的数的下标再减一
			}
			st.push(i); //将当前数入栈
		}
		//全部数都已入栈完毕，栈中剩余数的右边界都是n
		while (st.top() != -1) {
			int h = heights[st.top()]; //矩形的高度
			st.pop();
			maxArea = max(maxArea, h*(n - st.top() - 1));
		}
		//当一个数的左边没有比它更小的数时，-1就会作为其左边界
		//当一个数的右边没有比它更小的数时，n就会作为其右边界
		return maxArea;
	}
};
int main()
{
	vector<string> matrix = { "10100", "10111", "11111", "10010" };
	cout << Solution().maximalRectangle(matrix) << endl;
	return 0;
}
