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


////��������
////�����������
//class Solution {
//public:
//	int openLock(vector<string>& deadends, string target) {
//		if (target == "0000") //���������־��ǳ�ʼ���֣���Ҫ��ת0��
//			return 0;
//		unordered_set<string> dead(deadends.begin(), deadends.end());
//		if (dead.count("0000")) //��ʼ���������������У��޷��ٱ���ת
//			return -1;
//		//��ȡ��һ���ַ�
//		auto nextNum = [](char ch)->char{
//			return ch == '9' ? '0' : ch + 1;
//		};
//		//��ȡ��һ���ַ�
//		auto prevNum = [](char ch)->char{
//			return ch == '0' ? '9' : ch - 1;
//		};
//		//��ȡsͨ��һ����ת���Եõ�������
//		auto getNextStatus = [&](string s)->vector<string>{
//			vector<string> ret;
//			for (int i = 0; i < 4; i++) {
//				char cur = s[i];
//				s[i] = nextNum(cur);
//				ret.push_back(s);
//				s[i] = prevNum(cur);
//				ret.push_back(s);
//				s[i] = cur; //�Ļ�ȥ
//			}
//			return ret;
//		};
//		queue<pair<string, int>> q; //���ڽ��й����������
//		q.emplace("0000", 0);
//		unordered_set<string> seen; //�洢����������������
//		seen.insert("0000");
//		while (!q.empty()) {
//			auto[status, step] = q.front();
//			q.pop();
//			//��statusͨ��һ����ת���Եõ������������
//			for (auto&& nextStatus : getNextStatus(status)) {
//				if (nextStatus == target) //����תһ�μ��ɽ���
//					return step + 1;
//				if (!seen.count(nextStatus) && !dead.count(nextStatus)) { //������û�б������������Ҳ���һ����������
//					q.emplace(nextStatus, step + 1); //�����
//					seen.insert(move(nextStatus)); //���Ϊ������
//				}
//			}
//		}
//		return -1; //�޷�����
//	}
//};
////˫������������
//class Solution {
//public:
//	int openLock(vector<string>& deadends, string target) {
//		if (target == "0000") //���������־��ǳ�ʼ���֣���Ҫ��ת0��
//			return 0;
//		unordered_set<string> dead(deadends.begin(), deadends.end());
//		if (dead.count("0000")) //��ʼ���������������У��޷��ٱ���ת
//			return -1;
//		//��ȡ��һ���ַ�
//		auto nextNum = [](char ch)->char{
//			return ch == '9' ? '0' : ch + 1;
//		};
//		//��ȡ��һ���ַ�
//		auto prevNum = [](char ch)->char{
//			return ch == '0' ? '9' : ch - 1;
//		};
//		//��ȡsͨ��һ����ת���Եõ�������
//		auto getNextStatus = [&](string s)->vector<string>{
//			vector<string> ret;
//			for (int i = 0; i < 4; i++) {
//				char cur = s[i];
//				s[i] = nextNum(cur);
//				ret.push_back(s);
//				s[i] = prevNum(cur);
//				ret.push_back(s);
//				s[i] = cur; //�Ļ�ȥ
//			}
//			return ret;
//		};
//		queue<pair<string, int>> qBegin; //���ڽ��й����������
//		qBegin.emplace("0000", 0);
//		unordered_set<string> seenBegin; //�洢����������������
//		seenBegin.insert("0000");
//
//		queue<pair<string, int>> qEnd; //���ڽ��й����������
//		qEnd.emplace(target, 0);
//		unordered_set<string> seenEnd; //�洢����������������
//		seenEnd.insert(target);
//
//		while (!qBegin.empty() && !qEnd.empty()) {
//			int beginSize = qBegin.size();
//			for (int i = 0; i < beginSize; i++) {
//				auto[status, step] = qBegin.front();
//				qBegin.pop();
//				if (seenEnd.count(status))
//					return step + qEnd.front().second;
//				//��statusͨ��һ����ת���Եõ������������
//				for (auto&& nextStatus : getNextStatus(status)) {
//					//if(nextStatus == target) //����תһ�μ��ɽ���
//					//    return step+1;
//					if (!seenBegin.count(nextStatus) && !dead.count(nextStatus)) { //������û�б������������Ҳ���һ����������
//						qBegin.emplace(nextStatus, step + 1); //�����
//						seenBegin.insert(move(nextStatus)); //���Ϊ������
//					}
//				}
//			}
//			int endSize = qEnd.size();
//			for (int i = 0; i < endSize; i++) {
//				auto[status, step] = qEnd.front();
//				qEnd.pop();
//				if (seenBegin.count(status))
//					return step + qBegin.front().second;
//				//��statusͨ��һ����ת���Եõ������������
//				for (auto&& nextStatus : getNextStatus(status)) {
//					//if(nextStatus == "0000") //����תһ�μ��ɽ���
//					//    return step+1;
//					if (!seenEnd.count(nextStatus) && !dead.count(nextStatus)) { //������û�б������������Ҳ���һ����������
//						qEnd.emplace(nextStatus, step + 1); //�����
//						seenEnd.insert(move(nextStatus)); //���Ϊ������
//					}
//				}
//			}
//		}
//		return -1; //�޷�����
//	}
//};


////����·��
////�����������
//class Solution {
//public:
//	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//		tmp.push_back(0);
//		dfs(graph, 0);
//		return ans;
//	}
//	void dfs(vector<vector<int>>& graph, int cur) {
//		if (cur == graph.size() - 1) { //�ҵ���һ��·��
//			ans.push_back(tmp);
//			return;
//		}
//		for (auto nextNode : graph[cur]) {
//			tmp.push_back(nextNode);
//			dfs(graph, nextNode);
//			tmp.pop_back(); //����
//		}
//	}
//private:
//	vector<vector<int>> ans;
//	vector<int> tmp;
//};


////�������
//class Solution {
//public:
//	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//		//��������������id��ӳ���ϵ
//		int nodeNum = 0;
//		unordered_map<string, int> strId;
//		for (int i = 0; i < equations.size(); i++) {
//			if (!strId.count(equations[i][0])) {
//				strId[equations[i][0]] = nodeNum++;
//			}
//			if (!strId.count(equations[i][1])) {
//				strId[equations[i][1]] = nodeNum++;
//			}
//		}
//		//��ͼ��ÿ����֮������ӹ�ϵ���������߶�Ӧ��Ȩֵ��
//		vector<vector<pair<int, double>>> edge(nodeNum);
//		for (int i = 0; i < equations.size(); i++) {
//			int id1 = strId[equations[i][0]], id2 = strId[equations[i][1]];
//			edge[id1].emplace_back(id2, values[i]); //a/b
//			edge[id2].emplace_back(id1, 1.0 / values[i]); //b/a
//		}
//		vector<double> ret; //���
//		for (int i = 0; i < queries.size(); i++) {
//			string a = queries[i][0], b = queries[i][1];
//			if (!strId.count(a) || !strId.count(b)) { //��������֪������û�г����ַ���
//				ret.push_back(-1.0);
//			}
//			else {
//				int id1 = strId[a], id2 = strId[b];
//				//divRet[i]��ʾid1��Ӧ���ַ�����i��Ӧ���ַ�������Ľ��
//				vector<double> divRet(nodeNum, -1.0); //��ʼ��Ϊ-1.0���޷�ȷ���Ĵ���-1.0���棨���ܲ�����ͨͼ����
//				divRet[id1] = 1.0; //�Լ����Լ�������Ϊ1.0
//				queue<int> q;
//				q.push(id1);
//				while (!q.empty() && divRet[id2] < 0) { //divRet[id2]С��0˵������Ҫ��������
//					int x = q.front();
//					q.pop();
//					//����x��������û�б������Ľ�������У�������id1��Ӧ���ַ�����������Ľ��
//					for (auto[y, val] : edge[x]) {
//						if (divRet[y] < 0) {
//							divRet[y] = divRet[x] * val; //(a/b) * (b/c) = a/c
//							q.push(y);
//						}
//					}
//				}
//				ret.push_back(divRet[id2]);
//			}
//		}
//		return ret;
//	}
//};
////Floyd�㷨
//class Solution {
//public:
//	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//		int nodeNum = 0;
//		unordered_map<string, int> strId;
//		for (int i = 0; i < equations.size(); i++) {
//			if (!strId.count(equations[i][0])) {
//				strId[equations[i][0]] = nodeNum++;
//			}
//			if (!strId.count(equations[i][1])) {
//				strId[equations[i][1]] = nodeNum++;
//			}
//		}
//		vector<vector<double>> graph(nodeNum, vector<double>(nodeNum, -1.0));
//		for (int i = 0; i < equations.size(); i++) {
//			int id1 = strId[equations[i][0]], id2 = strId[equations[i][1]];
//			graph[id1][id2] = values[i];
//			graph[id2][id1] = 1.0 / values[i];
//		}
//
//		//Ԥ�ȼ������������ľ��루�����ֵ��
//		for (int k = 0; k < nodeNum; k++) {
//			for (int i = 0; i < nodeNum; i++) {
//				for (int j = 0; j < nodeNum; j++) {
//					if (graph[i][k] > 0 && graph[k][j] > 0) {
//						graph[i][j] = graph[i][k] * graph[k][j];
//					}
//				}
//			}
//		}
//		vector<double> ret;
//		for (int i = 0; i < queries.size(); i++) {
//			string a = queries[i][0], b = queries[i][1];
//			if (!strId.count(a) || !strId.count(b)) {
//				ret.push_back(-1.0);
//			}
//			else {
//				int id1 = strId[a], id2 = strId[b];
//				ret.push_back(graph[id1][id2]);
//			}
//		}
//		return ret;
//	}
//};


////�����·��
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
////���仯�����������
//class Solution {
//public:
//	int longestIncreasingPath(vector<vector<int>>& matrix) {
//		int m = matrix.size(), n = matrix[0].size();
//		//maxPath[i][j]��ʾ��(i,j)λ�ó����������·��
//		vector<vector<int>> maxPath(m, vector<int>(n, 0));
//		int ans = 0;
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				ans = max(ans, dfs(matrix, i, j, maxPath)); //�ҵ�ÿ��λ�õ������·�������ֵ
//			}
//		}
//		return ans;
//	}
//	int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& maxPath) {
//		if (maxPath[x][y] != 0) //��λ���Ѿ������
//			return maxPath[x][y];
//		//maxPath[x][y]������Χֵ�����Լ��ĸ���λ���У������·�����·��+1
//		int maxLen = 0;
//		for (int i = 0; i < 4; i++) {
//			int row = x + dirs[i][0], col = y + dirs[i][1];
//			if (row >= 0 && row<matrix.size() && col >= 0 && col<matrix[0].size() && matrix[row][col]>matrix[x][y]) {
//				maxLen = max(maxLen, dfs(matrix, row, col, maxPath));
//			}
//		}
//		maxPath[x][y] = maxLen + 1;
//		return maxPath[x][y];
//	}
//private:
//	static constexpr int dirs[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//};
////��������
//class Solution {
//public:
//	int longestIncreasingPath(vector<vector<int>>& matrix) {
//		//1������ÿ��λ�õĳ��ȣ����Ӹ�λ����������������
//		int m = matrix.size(), n = matrix[0].size();
//		vector<vector<int>> dp(m, vector<int>(n, 0));
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				for (int k = 0; k < 4; k++) {
//					int nx = i + dirs[k][0], ny = j + dirs[k][1];
//					if (nx >= 0 && nx < m&&ny >= 0 && ny < n&&matrix[nx][ny] > matrix[i][j])
//						dp[i][j]++; //����++
//				}
//			}
//		}
//		//2��������Ϊ0��λ������У�����Ϊ0��Ϊ·�ߵ��յ㣩
//		queue<pair<int, int>> q;
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (dp[i][j] == 0)
//					q.push({ i, j });
//			}
//		}
//		//3���ӳ���Ϊ0��λ�ÿ�ʼ���й��ѣ����Ѽ����������·������Ϊ��
//		int ans = 0;
//		while (!q.empty()) {
//			ans++;
//			//ȡ���ò�ȫ����λ�ý��й���
//			int size = q.size();
//			for (int i = 0; i < size; i++) {
//				auto[x, y] = q.front();
//				q.pop();
//				//���ڳ���Ϊ0��λ�õ���Χ��λ����˵�������ȥ�˸ó���Ϊ0��λ�õĹ��׺�����ȱ�Ϊ0
//				//��Ӧ��������һ����ѵ�λ�ã������
//				for (int j = 0; j < 4; j++) {
//					int nx = x + dirs[j][0], ny = y + dirs[j][1];
//					if (nx >= 0 && nx < m&&ny >= 0 && ny < n&&matrix[nx][ny] < matrix[x][y]) {
//						dp[nx][ny]--;
//						if (dp[nx][ny] == 0)
//							q.push({ nx, ny });
//					}
//				}
//			}
//		}
//		return ans;
//	}
//private:
//	static constexpr int dirs[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
//};
//int main()
//{
//	vector<vector<int>> v = { { 9, 9, 4 }, { 6, 6, 8 }, { 2, 1, 1 } };
//	cout << Solution().longestIncreasingPath(v) << endl;
//	return 0;
//}


////�γ�˳����������
////�����������
//class Solution {
//public:
//	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//		edges.resize(numCourses);
//		visited.resize(numCourses, 0);
//		valid = true;
//		//1������������ϵ��������ͼ
//		for (const auto& rel : prerequisites) {
//			edges[rel[1]].push_back(rel[0]);
//		}
//		//2��ѡһ��δ�����ĵ㿪ʼ���������������
//		for (int i = 0; i < numCourses&&valid; i++) {
//			if (visited[i] == 0) { //δ����
//				dfs(i);
//			}
//		}
//		if (!valid) //�ɻ�
//			return vector<int>();
//		//ջ����ջ�׵�����Ϊ��������
//		reverse(st.begin(), st.end());
//		return st;
//	}
//	void dfs(int u) {
//		visited[u] = 1; //���Ϊ������
//		//�������ڽڵ�
//		for (const auto& v : edges[u]) {
//			if (visited[v] == 0) { //���ڽڵ�δ����
//				dfs(v); //����
//				if (!valid)
//					return;
//			}
//			else if (visited[v] == 1) { //���ڽڵ������У�˵���ɻ�
//				valid = false;
//				return;
//			}
//		}
//		visited[u] = 2; //���Ϊ������
//		st.push_back(u); //ѹ��ջ��
//	}
//private:
//	vector<vector<int>> edges; //�洢����ͼ
//	vector<int> visited; //0��ʾδ������1��ʾ�����У�2��ʾ������
//	vector<int> st; //����ģ��ջ
//	bool valid = true; //�Ƿ���Ҫ�����жϣ�����ɻ��򲻱ؼ����жϣ�
//};
////�����������
//class Solution {
//public:
//	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//		vector<vector<int>> edges(numCourses);
//		vector<int> inNum(numCourses, 0);
//		//1������������ϵ��������ͼ����ͳ��ÿ���ڵ�����
//		for (const auto& rel : prerequisites) {
//			edges[rel[1]].push_back(rel[0]);
//			inNum[rel[0]]++;
//		}
//		//2�������Ϊ0�Ľڵ������
//		queue<int> q;
//		for (int i = 0; i < numCourses; i++) {
//			if (inNum[i] == 0) {
//				q.push(i);
//			}
//		}
//		//3�������ó����Ϊ0�Ľڵ㣬���ýڵ��Ӧ�ı�ȥ���������³��ֵ����Ϊ0�Ľڵ������
//		vector<int> ans;
//		while (!q.empty()) {
//			int u = q.front();
//			q.pop();
//			ans.push_back(u);
//			for (const auto& v : edges[u]) {
//				inNum[v]--;
//				if (inNum[v] == 0)
//					q.push(v);
//			}
//		}
//		if (ans.size() != numCourses) //���нڵ����Ȳ�Ϊ0��˵���ɻ�
//			return vector<int>();
//		return ans;
//	}
//};


////�������ֵ䣨��������
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <unordered_map>
//#include <queue>
//using namespace std;
//////�����������
////class Solution {
////public:
////	string alienOrder(vector<string>& words) {
////		valid = true; //Ĭ�ϴ��ںϷ���ĸ˳��
////		//1�����������ַ����б��õ����г��ֹ�����ĸ
////		for (const string& word : words) {
////			for (const char& ch : word) {
////				if (!edges.count(ch))
////					edges[ch] = vector<char>();
////			}
////		}
////		//2�������ַ����б��и������ڵ��ַ�����������ͼ
////		int n = words.size();
////		for (int i = 1; i < n && valid; i++) {
////			addEdge(words[i - 1], words[i]);
////		}
////		if (valid == false)
////			return "";
////		//3��������ͼ��ѡȡһ���ڵ㿪ʼ�����������������ֱ�����нڵ㶼������
////		for (const auto [u, _] : edges) {
////			if (!status.count(u)) {
////				dfs(u);
////			}
////			if (valid == false)
////				break;
////		}
////		if (valid == false)
////			return "";
////		//4��������������õ����ַ�����ת��Ϊ��������
////		reverse(ans.begin(), ans.end());
////		return ans;
////	}
////	//�������������ַ���������ͼ�в����
////	void addEdge(const string& s1, const string& s2) {
////		int len1 = s1.size(), len2 = s2.size();
////		int len = min(len1, len2);
////		int i = 0;
////		while (i < len) {
////			if (s1[i] != s2[i]) { //����s1[i]��s2[i]�������
////				edges[s1[i]].push_back(s2[i]);
////				break; //���������ַ���ֻ��ȷ��������ĸ���Ⱥ�˳��
////			}
////			i++;
////		}
////		if (i == len && len1 > len2) //�����ںϷ��⣬����ab��a
////			valid = false;
////	}
////	//�����������
////	void dfs(const char u) {
////		status[u] = 1; //���ڵ�u���Ϊ������
////		for (const char& v : edges[u]) {
////			if (!status.count(v)) { //�ڵ�vδ����
////				dfs(v);
////				if (valid == false)
////					return;
////			}
////			else if (status[v] == 1) { //�ڵ�v�������У�˵������ͼ�ɻ�
////				valid = false;
////				return;
////			}
////		}
////		status[u] = 2; //���ڵ�u���Ϊ������
////		ans += u; //ѹ��ջ��
////	}
////private:
////	unordered_map<char, vector<char>> edges; //�洢����ͼ
////	unordered_map<char, int> status; //���ÿ���ڵ������״̬
////	bool valid; //�Ƿ��н�
////	string ans; //ģ��ջ
////};
//class Solution {
//public:
//	string alienOrder(vector<string>& words) {
//		valid = true; //Ĭ�ϴ��ںϷ���ĸ˳��
//		//1�����������ַ����б��õ����г��ֹ�����ĸ
//		for (const string& word : words) {
//			for (const char& ch : word) {
//				if (!edges.count(ch)) {
//					edges[ch] = vector<char>();
//					indegrees[ch] = 0; //��ĸ����ȳ�ʼ��Ϊ0
//				}
//			}
//		}
//		//2�������ַ����б��и������ڵ��ַ�����������ͼ
//		int n = words.size();
//		for (int i = 1; i < n && valid; i++) {
//			addEdge(words[i - 1], words[i]);
//		}
//		if (valid == false)
//			return "";
//		//3�������Ϊ0�Ľڵ�������
//		queue<char> q;
//		for (const auto[ch, indegree] : indegrees) {
//			if (indegree == 0)
//				q.push(ch);
//		}
//		//4�������ó����Ϊ0�Ľڵ㣬���ýڵ��Ӧ�ı�ȥ���������³��ֵ����Ϊ0�Ľڵ�������
//		string ans;
//		while (!q.empty()) {
//			char u = q.front();
//			q.pop();
//			for (const auto& v : edges[u]) {
//				indegrees[v]--;
//				if (indegrees[v] == 0)
//					q.push(v);
//			}
//			ans += u;
//		}
//		if (ans.size() < edges.size()) //���нڵ����Ȳ�Ϊ0��˵���ɻ������еĽڵ㲻�������������
//			return "";
//		return ans;
//	}
//	//�������������ַ���������ͼ�в����
//	void addEdge(const string& s1, const string& s2) {
//		int len1 = s1.size(), len2 = s2.size();
//		int len = min(len1, len2);
//		int i = 0;
//		while (i < len) {
//			if (s1[i] != s2[i]) { //����s1[i]��s2[i]�������
//				edges[s1[i]].push_back(s2[i]);
//				indegrees[s2[i]]++; //s2[i]�ڵ�����++
//				break; //���������ַ���ֻ��ȷ��������ĸ���Ⱥ�˳��
//			}
//			i++;
//		}
//		if (i == len && len1 > len2) { //�����ںϷ��⣬����ab��a
//			valid = false;
//		}
//	}
//private:
//	unordered_map<char, vector<char>> edges; //�洢����ͼ
//	unordered_map<char, int> indegrees; //��¼ÿ���ڵ�����
//	bool valid; //�Ƿ��н�
//};
//int main() {
//	vector<string> v = { "wrt", "wrf", "wrft", "wrff" };
//	cout << Solution().alienOrder(v) << endl;
//	return 0;
//}


////�ؽ����У���������
//#include <iostream>
//#include <unordered_set>
//#include <queue>
//#include <vector>
//using namespace std;
////�����������
//class Solution {
//public:
//	bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
//		int n = nums.size();
//		vector<unordered_set<int>> edges(n + 1); //�洢����ͼ
//		vector<int> indegrees(n + 1, 0); //��¼ÿ���ڵ�����
//		//1������sequences����������ͼ
//		for (const auto& sequence : sequences) {
//			for (int i = 1; i < sequence.size(); i++) {
//				int u = sequence[i - 1], v = sequence[i];
//				if (!edges[u].count(v)) { //��ֹ�ظ�����
//					edges[u].insert(v); //����u->v�ı�
//					indegrees[v]++; //v�ڵ�����++
//				}
//			}
//		}
//		//2�������Ϊ0�Ľڵ�������
//		queue<int> q;
//		for (int i = 1; i <= n; i++) {
//			if (indegrees[i] == 0)
//				q.push(i);
//		}
//		//3�������ó����Ϊ0�Ľڵ㣬���ýڵ�ı�ȥ���������³��ֵ����Ϊ0�Ľڵ�������
//		while (!q.empty()) {
//			//��ʼʱ���Ϊ0�Ľڵ�����ж������˵��nums��������û��sequences�г��ֹ������nums�϶�������̳�����
//			//����������ֶ����е�Ԫ�ظ�������һ����˵����һ�������ж��ֿ��ܣ����nums����Ψһ����̳�����
//			//sequences�е�ÿ�����ж���nums�������У���������в����ڻ�
//			if (q.size() > 1)
//				return false;
//			int u = q.front();
//			q.pop();
//			for (const auto& v : edges[u]) {
//				indegrees[v]--;
//				if (indegrees[v] == 0)
//					q.push(v);
//			}
//		}
//		return true;
//	}
//};
//int main() {
//	vector<int> nums = { 1, 2, 3 };
//	vector<vector<int>> sequences = { { 1, 2 }, { 1, 3 }, { 2, 3 } };
//	cout << Solution().sequenceReconstruction(nums, sequences) << endl;
//	return 0;
//}


////ʡ������
//#include <iostream>
//#include <vector>
//using namespace std;
//////�����������
////class Solution {
////public:
////	int findCircleNum(vector<vector<int>>& isConnected) {
////		int cities = isConnected.size(); //�ڵ������
////		vector<bool> visited(cities, false); //��¼ÿ���ڵ��Ƿ񱻷��ʹ�
////		int provinces = 0; //��¼��ͨ����������
////		for (int i = 0; i < cities; i++) {
////			if (visited[i] == false) { //ÿ�δ�һ��δ���ʹ��Ľڵ㿪ʼ��������
////				dfs(isConnected, i, visited, cities);
////				provinces++;
////			}
////		}
////		return provinces;
////	}
////	void dfs(vector<vector<int>>& isConnected, int u, vector<bool>& visited, int cities) {
////		visited[u] = true; //���Ϊ���ʹ�
////		for (int i = 0; i < cities; i++) {
////			if (isConnected[u][i] == 1 && visited[i] == false) //�����ӣ����Ҹýڵ�û�б����ʹ�
////				dfs(isConnected, i, visited, cities);
////		}
////	}
////};
//////�����������
////class Solution {
////public:
////	int findCircleNum(vector<vector<int>>& isConnected) {
////		int cities = isConnected.size(); //�ڵ������
////		vector<bool> visited(cities, false); //��¼ÿ���ڵ��Ƿ񱻷��ʹ�
////		int provinces = 0; //��¼��ͨ����������
////		for (int i = 0; i < cities; i++) {
////			if (visited[i] == false) { //ÿ�δ�һ��δ���ʹ��Ľڵ㿪ʼ���й���
////				queue<int> q;
////				q.push(i);
////				while (!q.empty()) {
////					int u = q.front();
////					visited[u] = true; //���Ϊ���ʹ�
////					q.pop();
////					for (int v = 0; v < cities; v++) {
////						if (isConnected[u][v] == 1 && visited[v] == false) //�����ӣ����Ҹýڵ�û�б����ʹ�
////							q.push(v);
////					}
////				}
////				provinces++;
////			}
////		}
////		return provinces;
////	}
////};
////���鼯
//class Solution {
//public:
//	int findCircleNum(vector<vector<int>>& isConnected) {
//		int cities = isConnected.size();
//		vector<int> parent(cities);
//		//1����ÿ���ڵ�ĸ��ڵ��ʼ��Ϊ�Լ�
//		for (int i = 0; i < cities; i++) {
//			parent[i] = i;
//		}
//		//2������������ϵ�������鼯
//		for (int i = 0; i < cities; i++) {
//			for (int j = i + 1; j < cities; j++) {
//				if (isConnected[i][j] == 1)
//					unionCity(parent, i, j);
//			}
//		}
//		//3��ͳ����ͨ�����������������ڵ�Ϊ�Լ��Ľڵ�ĸ���
//		int provinces = 0;
//		for (int i = 0; i < cities; i++) {
//			if (parent[i] == i)
//				provinces++;
//		}
//		return provinces;
//	}
//	//��i��j���ڵ���ͨ��ϲ�
//	void unionCity(vector<int>& parent, int i, int j) {
//		parent[findRoot(parent, j)] = findRoot(parent, i); //��j�������ĸ��ڵ�ĸ��ڵ㣬��Ϊi�������ĸ��ڵ�
//	}
//	//����i�������ĸ��ڵ�
//	int findRoot(vector<int>& parent, int i) {
//		if (parent[i] == i) //���ڵ�����Լ�
//			return i;
//		return findRoot(parent, parent[i]); //���ڵ㲻���Լ������������ڵ��ǲ��Ǹ��ڵ�
//	}
//};
//int main() {
//	vector<vector<int>> isConnected = { { 1, 0, 0, 1 }, { 0, 1, 1, 0 }, { 0, 1, 1, 1 }, { 1, 0, 1, 1 } };
//	cout << Solution().findCircleNum(isConnected) << endl;
//	return 0;
//}


////���Ƶ��ַ���
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
////���鼯
//class Solution {
//public:
//	int numSimilarGroups(vector<string>& strs) {
//		int n = strs.size();
//		vector<int> parent(n);
//		//1����ÿ���ڵ�ĸ��ڵ��ʼ��Ϊ�Լ�
//		for (int i = 0; i < n; i++) {
//			parent[i] = i;
//		}
//		//2�����������ַ����б������鼯
//		for (int i = 0; i < n; i++) {
//			for (int j = i + 1; j < n; j++) {
//				//���ҵ������ַ����ĸ��ڵ�
//				//������ڵ���ͬ�������ж��������ַ����Ƿ�����
//				int iRoot = findRoot(parent, i);
//				int jRoot = findRoot(parent, j);
//				if (iRoot == jRoot)
//					continue;
//				if (check(strs[i], strs[j]))
//					parent[jRoot] = iRoot; //��j�������ĸ��ڵ�ĸ��ڵ㣬��Ϊi�������ĸ��ڵ�
//			}
//		}
//		//3��ͳ����ͨ�����������������ڵ�Ϊ�Լ��Ľڵ�ĸ���
//		int groups = 0;
//		for (int i = 0; i < n; i++) {
//			if (parent[i] == i)
//				groups++;
//		}
//		return groups;
//	}
//	//����i�ڵ��������ĸ��ڵ�
//	int findRoot(vector<int>& parent, int i) {
//		return parent[i] == i ? i : findRoot(parent, parent[i]);
//	}
//	//��������ַ����Ƿ�����
//	bool check(const string& s1, const string& s2) {
//		int len = s1.size();
//		int count = 0;
//		for (int i = 0; i < len; i++) {
//			if (s1[i] != s2[i]) {
//				count++;
//				if (count > 2)
//					return false;
//			}
//		}
//		return true;
//	}
//};
//int main() {
//	vector<string> strs = { "tars", "rats", "arts", "star" };
//	cout << Solution().numSimilarGroups(strs) << endl;
//	return 0;
//}


////����ı�
////���鼯
//class Solution {
//public:
//	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//		//n���ڵ��������n-1���ߣ���Ŀ�����������������һ���ߺ��ͼedges�����edges�бߵĸ���Ϊn�����ڵ�ĸ���
//		int n = edges.size();
//		vector<int> parent(n + 1); //�ڵ���Ϊ1��n��0���±겻��
//		//1����ÿ���ڵ�ĸ��ڵ��ʼ��Ϊ�Լ�
//		for (int i = 1; i <= n; i++) {
//			parent[i] = i;
//		}
//		//2������������ϵ�������鼯
//		for (int i = 0; i < n; i++) {
//			int u = edges[i][0], v = edges[i][1];
//			int uRoot = findRoot(parent, u), vRoot = findRoot(parent, v);
//			if (uRoot == vRoot) //u��v�ĸ��ڵ���ͬ��˵���������Ƕ���ģ����ڶ���ı�ֻ��һ��������ֱ�ӷ���
//				return vector<int>{u, v};
//			parent[uRoot] = vRoot; //��u���ڵ����ϲ���v���ڵ�����
//		}
//		return vector<int>{};
//	}
//	//����i�������ĸ��ڵ�
//	int findRoot(vector<int>& parent, int i) {
//		return parent[i] == i ? i : findRoot(parent, parent[i]);
//	}
//};


//���������
//��ϣ��+����ö��
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		//1���������е�������unordered_set������
		unordered_set<int> numSet;
		for (const auto& num : nums) {
			numSet.insert(num);
		}
		//2��ö����󳤶�
		int maxLen = 0;
		for (const auto& num : nums) {
			//�������в�����num-1ʱ����Ҫ��ʼö�٣���ʾnum���������еĵ�һ����
			//��Ϊ���������еķǵ�һ������ʼö�٣��õ����������еĳ���һ���ȴӵ�һ������ʼö�ٵĳ��ȶ�
			if (!numSet.count(num - 1)) {
				int curNum = num;
				int curLen = 1;
				//��num��ʼ����ö�٣�������һ�������������򳤶ȼ�һ
				while (numSet.count(curNum + 1)) {
					curNum++;
					curLen++;
				}
				maxLen = max(maxLen, curLen); //������󳤶�
			}
		}
		return maxLen;
	}
};
