#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
	//矩阵中最大的矩形
	int maximalRectangle(vector<string>& matrix) {
		if (matrix.size() == 0)
			return 0;
		vector<int> heights(matrix[0].size(), 0);
		int maxArea = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			string s = matrix[i];
			for (int j = 0; j < s.size(); j++)
			{
				if (matrix[i][j] == '1')
					heights[j]++;
				else
					heights[j] = 0;
			}
			maxArea = max(maxArea, largestRectangleArea(heights));
		}
		return maxArea;
	}
	//直方图最大矩形面积
	int largestRectangleArea(vector<int>& heights)
	{
		int n = heights.size();
		stack<int> st;
		st.push(-1);
		int maxArea = 0;
		for (int i = 0; i < n; i++)
		{
			while (st.top() != -1 && heights[i] < heights[st.top()])
			{
				int h = heights[st.top()];
				st.pop();
				maxArea = max(maxArea, h*(i - st.top() - 1));
			}
			st.push(i);
		}
		while (st.top() != -1)
		{
			int h = heights[st.top()];
			st.pop();
			maxArea = max(maxArea, h*(n - st.top() - 1));
		}
		return maxArea;
	}
};
int main()
{
	vector<string> matrix = { "10100", "10111", "11111", "10010" };
	cout << Solution().maximalRectangle(matrix) << endl;
	return 0;
}
