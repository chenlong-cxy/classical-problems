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


////�����еľ���
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
////�����������
//class Solution {
//public:
//	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//		int m = mat.size(), n = mat[0].size();
//		vector<vector<int>> dist(m, vector<int>(n, 0));
//		vector<vector<bool>> seen(m, vector<bool>(n, false));
//		queue<pair<int, int>> q;
//		//��������Ϊ0��λ�������
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (mat[i][j] == 0) {
//					q.emplace(i, j);
//					seen[i][j] = true;
//				}
//			}
//		}
//		//���δӶ����л�ȡλ�ã��õ��丽��λ��Ԫ�ؾ��������0�ľ���
//		while (!q.empty()) {
//			auto[x, y] = q.front();
//			q.pop();
//			for (int i = 0; i < 4; i++) {
//				int xn = x + v[i][0];
//				int yn = y + v[i][1];
//				if (xn >= 0 && xn < m&&yn >= 0 && yn < n&&seen[xn][yn] == false) {
//					dist[xn][yn] = dist[x][y] + 1;
//					q.emplace(xn, yn);
//					seen[xn][yn] = true;
//				}
//			}
//		}
//		return dist;
//	}
//private:
//	static constexpr int v[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
//};
////��̬�滮
//class Solution {
//public:
//	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//		int m = mat.size(), n = mat[0].size();
//		//dp[i][j]��ʾ(i,j)λ�õ������0�ľ���
//		vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1)); //��ֹdp[i][j]+1���
//		//��0���ڵ�λ�õ������0�ľ�����0
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (mat[i][j] == 0)
//					dp[i][j] = 0;
//			}
//		}
//		//�����Ͻǵ����½ǽ���ˢ��
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (i - 1 >= 0)
//					dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
//				if (j - 1 >= 0)
//					dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
//			}
//		}
//		//�����½ǵ����Ͻǽ���ˢ��
//		for (int i = m - 1; i >= 0; i--) {
//			for (int j = n - 1; j >= 0; j--) {
//				if (i + 1 < m)
//					dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
//				if (j + 1 < n)
//					dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
//			}
//		}
//		return dp;
//	}
//};
//int main()
//{
//	vector<vector<int>> mat = { { 0, 0, 0 }, { 0, 1, 0 }, { 1, 1, 1 } };
//	vector<vector<int>> ans = Solution().updateMatrix(mat);
//	return 0;
//}


////�����ݱ�
//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//#include <unordered_map>
//using namespace std;
////�Ż���ͼ�����������㣩+�����������
//class Solution {
//public:
//	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//		num = 0;
//		//����ÿ���ַ�������id�Ķ�Ӧ��ϵ����ͨ�������ַ�����id������ת����ӳ���ϵ
//		for (auto& word : wordList) {
//			addEdge(word);
//		}
//		addEdge(beginWord); //beginWord���ܲ���wordList��
//		if (!wordId.count(endWord)) //endWord����wordList�У�������ת���ɹ�
//			return 0;
//		vector<int> changeNum(num, INT_MAX); //changeNum[i]��ʾ��beginWordת�������ַ�����Ҫ���е�ת������
//		int beginId = wordId[beginWord], endId = wordId[endWord];
//		changeNum[beginId] = 0; //beginWordת����beginWord��Ҫת��0��
//
//		queue<int> q; //���ڽ��й����������
//		q.push(beginId);
//		while (!q.empty()) {
//			int x = q.front();
//			q.pop();
//			if (x == endId) { //ת���ɹ�
//				//ͼ�м���������ڵ㣬ʵ����Ҫ��ת�������ǵ�ǰ��һ��
//				//��ĿҪ�����ת�����еĳ��ȣ����Ի���Ҫ��һ
//				return changeNum[x] / 2 + 1;
//			}
//			for (auto nei : relation[x]) {
//				if (changeNum[nei] == INT_MAX) { //�����߻ص��߹��ĵ�
//					changeNum[nei] = changeNum[x] + 1; //ת��������һ
//					q.push(nei); //��������У��������й���
//				}
//			}
//		}
//		return 0;
//	}
//	void addWord(string& word) {
//		if (!wordId.count(word)) {
//			wordId[word] = num++;
//			relation.emplace_back(); //�������������洢word��ת����ϵ
//		}
//	}
//	void addEdge(string& word) {
//		addWord(word);
//		int id1 = wordId[word];
//		for (char& ch : word) {
//			char tmp = ch;
//			ch = '*'; //�����޸�
//			addWord(word);
//			int id2 = wordId[word];
//			relation[id1].push_back(id2);
//			relation[id2].push_back(id1);
//			ch = tmp; //�Ļ�ȥ
//		}
//	}
//private:
//	unordered_map<string, int> wordId;
//	vector<vector<int>> relation;
//	int num;
//};
////˫������������
//class Solution {
//public:
//	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//		nodeNum = 0;
//		for (auto& word : wordList) {
//			addEdge(word);
//		}
//		addEdge(beginWord);
//		if (!wordId.count(endWord))
//			return 0;
//		vector<int> disBegin(nodeNum, INT_MAX);
//		int beginId = wordId[beginWord];
//		disBegin[beginId] = 0;
//		queue<int> qBegin;
//		qBegin.push(beginId);
//
//		vector<int> disEnd(nodeNum, INT_MAX);
//		int endId = wordId[endWord];
//		disEnd[endId] = 0;
//		queue<int> qEnd;
//		qEnd.push(endId);
//
//		while (!qBegin.empty() && !qEnd.empty()) {
//			int beginSize = qBegin.size();
//			for (int i = 0; i < beginSize; i++) {
//				int x = qBegin.front();
//				qBegin.pop();
//				if (disEnd[x] != INT_MAX) { //�Ѿ�����һ�����������������
//					return (disBegin[x] + disEnd[x]) / 2 + 1;
//				}
//				for (auto nearNode : edge[x]) {
//					if (disBegin[nearNode] == INT_MAX) { //��ǰ���������û�б������ý��
//						disBegin[nearNode] = disBegin[x] + 1;
//						qBegin.push(nearNode);
//					}
//				}
//			}
//			int endSize = qEnd.size();
//			for (int i = 0; i < endSize; i++) {
//				int x = qEnd.front();
//				qEnd.pop();
//				if (disBegin[x] != INT_MAX) { //�Ѿ�����һ�����������������
//					return (disBegin[x] + disEnd[x]) / 2 + 1;
//				}
//				for (auto nearNode : edge[x]) {
//					if (disEnd[nearNode] == INT_MAX) { //��ǰ���������û�б������ý��
//						disEnd[nearNode] = disEnd[x] + 1;
//						qEnd.push(nearNode);
//					}
//				}
//			}
//		}
//		return 0;
//	}
//	void addEdge(string& word) {
//		addWord(word);
//		int id1 = wordId[word];
//		for (auto& ch : word) {
//			char tmp = ch;
//			ch = '*';
//			addWord(word);
//			int id2 = wordId[word];
//			edge[id1].push_back(id2);
//			edge[id2].push_back(id1);
//			ch = tmp;
//		}
//	}
//	void addWord(string& word) {
//		if (!wordId.count(word)) { //����������Ѿ�����ӹ���
//			wordId[word] = nodeNum++;
//			edge.emplace_back();
//		}
//	}
//private:
//	unordered_map<string, int> wordId;
//	vector<vector<int>> edge;
//	int nodeNum;
//};
//int main()
//{
//	vector<string> v = { "hot", "dot", "dog", "lot", "log", "cog" };
//	cout << Solution().ladderLength("hit", "cog", v) << endl;
//	return 0;
//}


//��������
//�����������
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		if (target == "0000") //���������־��ǳ�ʼ���֣���Ҫ��ת0��
			return 0;
		unordered_set<string> dead(deadends.begin(), deadends.end());
		if (dead.count("0000")) //��ʼ���������������У��޷��ٱ���ת
			return -1;
		//��ȡ��һ���ַ�
		auto nextNum = [](char ch)->char{
			return ch == '9' ? '0' : ch + 1;
		};
		//��ȡ��һ���ַ�
		auto prevNum = [](char ch)->char{
			return ch == '0' ? '9' : ch - 1;
		};
		//��ȡsͨ��һ����ת���Եõ�������
		auto getNextStatus = [&](string s)->vector<string>{
			vector<string> ret;
			for (int i = 0; i < 4; i++) {
				char cur = s[i];
				s[i] = nextNum(cur);
				ret.push_back(s);
				s[i] = prevNum(cur);
				ret.push_back(s);
				s[i] = cur; //�Ļ�ȥ
			}
			return ret;
		};
		queue<pair<string, int>> q; //���ڽ��й����������
		q.emplace("0000", 0);
		unordered_set<string> seen; //�洢����������������
		seen.insert("0000");
		while (!q.empty()) {
			auto[status, step] = q.front();
			q.pop();
			//��statusͨ��һ����ת���Եõ������������
			for (auto&& nextStatus : getNextStatus(status)) {
				if (nextStatus == target) //����תһ�μ��ɽ���
					return step + 1;
				if (!seen.count(nextStatus) && !dead.count(nextStatus)) { //������û�б������������Ҳ���һ����������
					q.emplace(nextStatus, step + 1); //�����
					seen.insert(move(nextStatus)); //���Ϊ������
				}
			}
		}
		return -1; //�޷�����
	}
};
//˫������������
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		if (target == "0000") //���������־��ǳ�ʼ���֣���Ҫ��ת0��
			return 0;
		unordered_set<string> dead(deadends.begin(), deadends.end());
		if (dead.count("0000")) //��ʼ���������������У��޷��ٱ���ת
			return -1;
		//��ȡ��һ���ַ�
		auto nextNum = [](char ch)->char{
			return ch == '9' ? '0' : ch + 1;
		};
		//��ȡ��һ���ַ�
		auto prevNum = [](char ch)->char{
			return ch == '0' ? '9' : ch - 1;
		};
		//��ȡsͨ��һ����ת���Եõ�������
		auto getNextStatus = [&](string s)->vector<string>{
			vector<string> ret;
			for (int i = 0; i < 4; i++) {
				char cur = s[i];
				s[i] = nextNum(cur);
				ret.push_back(s);
				s[i] = prevNum(cur);
				ret.push_back(s);
				s[i] = cur; //�Ļ�ȥ
			}
			return ret;
		};
		queue<pair<string, int>> qBegin; //���ڽ��й����������
		qBegin.emplace("0000", 0);
		unordered_set<string> seenBegin; //�洢����������������
		seenBegin.insert("0000");

		queue<pair<string, int>> qEnd; //���ڽ��й����������
		qEnd.emplace(target, 0);
		unordered_set<string> seenEnd; //�洢����������������
		seenEnd.insert(target);

		while (!qBegin.empty() && !qEnd.empty()) {
			int beginSize = qBegin.size();
			for (int i = 0; i < beginSize; i++) {
				auto[status, step] = qBegin.front();
				qBegin.pop();
				if (seenEnd.count(status))
					return step + qEnd.front().second;
				//��statusͨ��һ����ת���Եõ������������
				for (auto&& nextStatus : getNextStatus(status)) {
					//if(nextStatus == target) //����תһ�μ��ɽ���
					//    return step+1;
					if (!seenBegin.count(nextStatus) && !dead.count(nextStatus)) { //������û�б������������Ҳ���һ����������
						qBegin.emplace(nextStatus, step + 1); //�����
						seenBegin.insert(move(nextStatus)); //���Ϊ������
					}
				}
			}
			int endSize = qEnd.size();
			for (int i = 0; i < endSize; i++) {
				auto[status, step] = qEnd.front();
				qEnd.pop();
				if (seenBegin.count(status))
					return step + qBegin.front().second;
				//��statusͨ��һ����ת���Եõ������������
				for (auto&& nextStatus : getNextStatus(status)) {
					//if(nextStatus == "0000") //����תһ�μ��ɽ���
					//    return step+1;
					if (!seenEnd.count(nextStatus) && !dead.count(nextStatus)) { //������û�б������������Ҳ���һ����������
						qEnd.emplace(nextStatus, step + 1); //�����
						seenEnd.insert(move(nextStatus)); //���Ϊ������
					}
				}
			}
		}
		return -1; //�޷�����
	}
};


//����·��
//�����������
class Solution {
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		tmp.push_back(0);
		dfs(graph, 0);
		return ans;
	}
	void dfs(vector<vector<int>>& graph, int cur) {
		if (cur == graph.size() - 1) { //�ҵ���һ��·��
			ans.push_back(tmp);
			return;
		}
		for (auto nextNode : graph[cur]) {
			tmp.push_back(nextNode);
			dfs(graph, nextNode);
			tmp.pop_back(); //����
		}
	}
private:
	vector<vector<int>> ans;
	vector<int> tmp;
};