////�����������
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
////�����������
//class Solution {
//public:
//	int maxAreaOfIsland(vector<vector<int>>& grid) {
//		int m = grid.size(), n = grid[0].size();
//		int ans = 0;
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				ans = max(ans, dfs(grid, i, j));
//			}
//		}
//		return ans;
//	}
//	int dfs(vector<vector<int>>& grid, int x, int y) {
//		if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size()) //�±�Խ��
//			return 0;
//		if (grid[x][y] == 0) //��λ��Ϊ����
//			return 0;
//		grid[x][y] = 0; //����ͬһ��λ�ñ���μ���
//		return dfs(grid, x - 1, y) + dfs(grid, x, y - 1) + dfs(grid, x + 1, y) + dfs(grid, x, y + 1) + 1;
//	}
//};
////�������������stack����ݹ飩
//class Solution {
//public:
//	int maxAreaOfIsland(vector<vector<int>>& grid) {
//		int m = grid.size(), n = grid[0].size();
//		int ans = 0;
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				int area = 0;
//				stack<pair<int, int>> st;
//				st.push({ i, j });
//				while (!st.empty()) {
//					pair<int, int> top = st.top();
//					st.pop();
//					int x = top.first, y = top.second;
//					if (x < 0 || y < 0 || x == m || y == n || grid[x][y] == 0)
//						continue;
//					grid[x][y] = 0; //��ֹͬһ��λ�ñ���η���
//					area += 1;
//					st.push({ x - 1, y });
//					st.push({ x + 1, y });
//					st.push({ x, y - 1 });
//					st.push({ x, y + 1 });
//				}
//				ans = max(ans, area);
//			}
//		}
//		return ans;
//	}
//};
////�����������
//class Solution {
//public:
//	int maxAreaOfIsland(vector<vector<int>>& grid) {
//		int m = grid.size(), n = grid[0].size();
//		int ans = 0;
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				int area = 0;
//				queue<pair<int, int>> q;
//				q.push({ i, j });
//				while (!q.empty()) {
//					pair<int, int> front = q.front();
//					q.pop();
//					int x = front.first, y = front.second;
//					if (x < 0 || y < 0 || x == m || y == n || grid[x][y] == 0)
//						continue;
//					grid[x][y] = 0; //��ֹͬһ��λ�ñ���η���
//					area += 1;
//					q.push({ x + 1, y });
//					q.push({ x - 1, y });
//					q.push({ x, y + 1 });
//					q.push({ x, y - 1 });
//				}
//				ans = max(ans, area);
//			}
//		}
//		return ans;
//	}
//};
//int main()
//{
//	vector<vector<int>> grid = { 
//		{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
//		{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 }, 
//		{ 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 
//		{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 }, 
//		{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 }, 
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 
//		{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 }, 
//		{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 } };
//	cout << Solution().maxAreaOfIsland(grid) << endl;
//	return 0;
//}


////����ͼ
////�����������
//class Solution {
//public:
//	bool isBipartite(vector<vector<int>>& graph) {
//		int n = graph.size();
//		color.assign(n, UNCOLORED);
//		valid = true;
//		for (int i = 0; i < n; i++) { //����ͼ���ܲ�������ͨͼ����Ҫ��������������Ⱦɫ
//			if (color[i] == UNCOLORED) {
//				dfs(graph, i, RED);
//				if (valid == false)
//					return false;
//			}
//		}
//		return true;
//	}
//	void dfs(vector<vector<int>>& graph, int node, int c) {
//		color[node] = c;
//		int nearbyC = c == RED ? GREEN : RED;
//		//����node������nodeȾ��nearbyC��ɫ
//		for (auto nearby : graph[node]) {
//			if (color[nearby] == UNCOLORED) {
//				dfs(graph, nearby, nearbyC);
//				if (valid == false)
//					return;
//			}
//			else if (color[nearby] != nearbyC) { //�����ڽ����node����ɫ��ͬ�����Ƕ���ͼ
//				valid = false;
//				return;
//			}
//		}
//	}
//private:
//	vector<int> color;
//	bool valid;
//	//constexpr�������γ������ʽ
//	static constexpr int UNCOLORED = 0;
//	static constexpr int RED = 1;
//	static constexpr int GREEN = 2;
//};
////�����������
//class Solution {
//public:
//	bool isBipartite(vector<vector<int>>& graph) {
//		int n = graph.size();
//		vector<int> color(n, UNCOLORED);
//		for (int i = 0; i < n; i++) {
//			if (color[i] == UNCOLORED) {
//				color[i] = RED;
//				queue<int> q;
//				q.push(i);
//				while (!q.empty()) {
//					int node = q.front();
//					q.pop();
//					int c = color[node];
//					int nearbyC = c == RED ? GREEN : RED;
//					for (auto nearby : graph[node]) {
//						if (color[nearby] == UNCOLORED) {
//							color[nearby] = nearbyC;
//							q.push(nearby);
//						}
//						else if (color[nearby] != nearbyC) {
//							return false;
//						}
//					}
//				}
//			}
//		}
//		return true;
//	}
//private:
//	static constexpr int UNCOLORED = 0;
//	static constexpr int RED = 1;
//	static constexpr int GREEN = 2;
//};


//�����еľ���
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//�����������
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		int m = mat.size(), n = mat[0].size();
		vector<vector<int>> dist(m, vector<int>(n, 0));
		vector<vector<bool>> seen(m, vector<bool>(n, false));
		queue<pair<int, int>> q;
		//��������Ϊ0��λ�������
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 0) {
					q.emplace(i, j);
					seen[i][j] = true;
				}
			}
		}
		//���δӶ����л�ȡλ�ã��õ��丽��λ��Ԫ�ؾ��������0�ľ���
		while (!q.empty()) {
			auto[x, y] = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xn = x + v[i][0];
				int yn = y + v[i][1];
				if (xn >= 0 && xn < m&&yn >= 0 && yn < n&&seen[xn][yn] == false) {
					dist[xn][yn] = dist[x][y] + 1;
					q.emplace(xn, yn);
					seen[xn][yn] = true;
				}
			}
		}
		return dist;
	}
private:
	static constexpr int v[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
};
//��̬�滮
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		int m = mat.size(), n = mat[0].size();
		//dp[i][j]��ʾ(i,j)λ�õ������0�ľ���
		vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1)); //��ֹdp[i][j]+1���
		//��0���ڵ�λ�õ������0�ľ�����0
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 0)
					dp[i][j] = 0;
			}
		}
		//�����Ͻǵ����½ǽ���ˢ��
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i - 1 >= 0)
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
				if (j - 1 >= 0)
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			}
		}
		//�����½ǵ����Ͻǽ���ˢ��
		for (int i = m - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (i + 1 < m)
					dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
				if (j + 1 < n)
					dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
			}
		}
		return dp;
	}
};
int main()
{
	vector<vector<int>> mat = { { 0, 0, 0 }, { 0, 1, 0 }, { 1, 1, 1 } };
	vector<vector<int>> ans = Solution().updateMatrix(mat);
	return 0;
}