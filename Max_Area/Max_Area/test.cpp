#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
//����ջ
class Solution {
public:
	//���������ľ���
	int maximalRectangle(vector<string>& matrix) {
		if (matrix.size() == 0)
			return 0;
		vector<int> heights(matrix[0].size(), 0); //ֱ��ͼ
		int maxArea = 0;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				if (matrix[i][j] == '1') //ֱ��ͼ��jλ�õ�height��һ
					heights[j]++;
				else //ֱ��ͼ��jλ�õ�height����
					heights[j] = 0;
			}
			//���ݸ�ֱ��ͼ��������������¾��������ľ������
			maxArea = max(maxArea, largestRectangleArea(heights));
		}
		return maxArea;
	}
	//ֱ��ͼ���������
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		stack<int> st; //ջ�д洢����ֱ��ͼ�е��±꣬���������εĿ�
		st.push(-1);
		int maxArea = 0;
		for (int i = 0; i < n; i++) {
			while (st.top() != -1 && heights[i] < heights[st.top()]) { //����ջ������ջ������С��˵���ҵ���ջ���������ұ߽�
				int h = heights[st.top()]; //���εĸ߶�
				st.pop();
				maxArea = max(maxArea, h*(i - st.top() - 1)); //���εĿ��Ϊ����ջ�������±��ȥ��ջ���������±��ټ�һ
			}
			st.push(i); //����ǰ����ջ
		}
		//ȫ����������ջ��ϣ�ջ��ʣ�������ұ߽綼��n
		while (st.top() != -1) {
			int h = heights[st.top()]; //���εĸ߶�
			st.pop();
			maxArea = max(maxArea, h*(n - st.top() - 1));
		}
		//��һ���������û�б�����С����ʱ��-1�ͻ���Ϊ����߽�
		//��һ�������ұ�û�б�����С����ʱ��n�ͻ���Ϊ���ұ߽�
		return maxArea;
	}
};
int main()
{
	vector<string> matrix = { "10100", "10111", "11111", "10010" };
	cout << Solution().maximalRectangle(matrix) << endl;
	return 0;
}
