////岛屿的最大面积
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
////深度优先搜索
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
//		if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size()) //下标越界
//			return 0;
//		if (grid[x][y] == 0) //该位置为海洋
//			return 0;
//		grid[x][y] = 0; //避免同一个位置被多次计算
//		return dfs(grid, x - 1, y) + dfs(grid, x, y - 1) + dfs(grid, x + 1, y) + dfs(grid, x, y + 1) + 1;
//	}
//};
////深度优先搜索（stack代替递归）
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
//					grid[x][y] = 0; //防止同一个位置被多次访问
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
////广度优先搜索
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
//					grid[x][y] = 0; //防止同一个位置被多次访问
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


////二分图
////深度优先搜索
//class Solution {
//public:
//	bool isBipartite(vector<vector<int>>& graph) {
//		int n = graph.size();
//		color.assign(n, UNCOLORED);
//		valid = true;
//		for (int i = 0; i < n; i++) { //所给图可能并不是连通图，需要遍历各个结点进行染色
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
//		//将与node相连的node染成nearbyC颜色
//		for (auto nearby : graph[node]) {
//			if (color[nearby] == UNCOLORED) {
//				dfs(graph, nearby, nearbyC);
//				if (valid == false)
//					return;
//			}
//			else if (color[nearby] != nearbyC) { //该相邻结点与node的颜色相同，不是二分图
//				valid = false;
//				return;
//			}
//		}
//	}
//private:
//	vector<int> color;
//	bool valid;
//	//constexpr用来修饰常量表达式
//	static constexpr int UNCOLORED = 0;
//	static constexpr int RED = 1;
//	static constexpr int GREEN = 2;
//};
////广度优先搜索
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


////矩阵中的距离
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
////广度优先搜索
//class Solution {
//public:
//	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//		int m = mat.size(), n = mat[0].size();
//		vector<vector<int>> dist(m, vector<int>(n, 0));
//		vector<vector<bool>> seen(m, vector<bool>(n, false));
//		queue<pair<int, int>> q;
//		//将矩阵中为0的位置入队列
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (mat[i][j] == 0) {
//					q.emplace(i, j);
//					seen[i][j] = true;
//				}
//			}
//		}
//		//依次从队列中获取位置，得到其附近位置元素距离最近的0的距离
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
////动态规划
//class Solution {
//public:
//	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//		int m = mat.size(), n = mat[0].size();
//		//dp[i][j]表示(i,j)位置到最近的0的距离
//		vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1)); //防止dp[i][j]+1溢出
//		//将0所在的位置到最近的0的距离是0
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (mat[i][j] == 0)
//					dp[i][j] = 0;
//			}
//		}
//		//从左上角到右下角进行刷新
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (i - 1 >= 0)
//					dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
//				if (j - 1 >= 0)
//					dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
//			}
//		}
//		//从右下角到左上角进行刷新
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


////单词演变
//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//#include <unordered_map>
//using namespace std;
////优化建图（加入虚拟结点）+广度优先搜索
//class Solution {
//public:
//	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//		num = 0;
//		//建立每个字符串与其id的对应关系，并通过各个字符串的id建立可转换的映射关系
//		for (auto& word : wordList) {
//			addEdge(word);
//		}
//		addEdge(beginWord); //beginWord可能不在wordList中
//		if (!wordId.count(endWord)) //endWord不在wordList中，不可能转换成功
//			return 0;
//		vector<int> changeNum(num, INT_MAX); //changeNum[i]表示从beginWord转换到该字符串需要进行的转换次数
//		int beginId = wordId[beginWord], endId = wordId[endWord];
//		changeNum[beginId] = 0; //beginWord转换到beginWord需要转换0次
//
//		queue<int> q; //用于进行广度优先搜索
//		q.push(beginId);
//		while (!q.empty()) {
//			int x = q.front();
//			q.pop();
//			if (x == endId) { //转换成功
//				//图中加入了虚拟节点，实际需要的转换次数是当前的一半
//				//题目要求的是转换序列的长度，所以还需要加一
//				return changeNum[x] / 2 + 1;
//			}
//			for (auto nei : relation[x]) {
//				if (changeNum[nei] == INT_MAX) { //避免走回到走过的点
//					changeNum[nei] = changeNum[x] + 1; //转换次数加一
//					q.push(nei); //放入队列中，后续进行广搜
//				}
//			}
//		}
//		return 0;
//	}
//	void addWord(string& word) {
//		if (!wordId.count(word)) {
//			wordId[word] = num++;
//			relation.emplace_back(); //该子数组用来存储word的转换关系
//		}
//	}
//	void addEdge(string& word) {
//		addWord(word);
//		int id1 = wordId[word];
//		for (char& ch : word) {
//			char tmp = ch;
//			ch = '*'; //引用修改
//			addWord(word);
//			int id2 = wordId[word];
//			relation[id1].push_back(id2);
//			relation[id2].push_back(id1);
//			ch = tmp; //改回去
//		}
//	}
//private:
//	unordered_map<string, int> wordId;
//	vector<vector<int>> relation;
//	int num;
//};
////双向广度优先搜索
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
//				if (disEnd[x] != INT_MAX) { //已经被另一个广度搜索遍历过了
//					return (disBegin[x] + disEnd[x]) / 2 + 1;
//				}
//				for (auto nearNode : edge[x]) {
//					if (disBegin[nearNode] == INT_MAX) { //当前广度搜索还没有遍历过该结点
//						disBegin[nearNode] = disBegin[x] + 1;
//						qBegin.push(nearNode);
//					}
//				}
//			}
//			int endSize = qEnd.size();
//			for (int i = 0; i < endSize; i++) {
//				int x = qEnd.front();
//				qEnd.pop();
//				if (disBegin[x] != INT_MAX) { //已经被另一个广度搜索遍历过了
//					return (disBegin[x] + disEnd[x]) / 2 + 1;
//				}
//				for (auto nearNode : edge[x]) {
//					if (disEnd[nearNode] == INT_MAX) { //当前广度搜索还没有遍历过该结点
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
//		if (!wordId.count(word)) { //虚拟结点可能已经被添加过了
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


////开密码锁
////广度优先搜索
//class Solution {
//public:
//	int openLock(vector<string>& deadends, string target) {
//		if (target == "0000") //解锁的数字就是初始数字，需要旋转0次
//			return 0;
//		unordered_set<string> dead(deadends.begin(), deadends.end());
//		if (dead.count("0000")) //初始数字在死亡数字中，无法再被旋转
//			return -1;
//		//获取下一个字符
//		auto nextNum = [](char ch)->char{
//			return ch == '9' ? '0' : ch + 1;
//		};
//		//获取上一个字符
//		auto prevNum = [](char ch)->char{
//			return ch == '0' ? '9' : ch - 1;
//		};
//		//获取s通过一次旋转可以得到的数字
//		auto getNextStatus = [&](string s)->vector<string>{
//			vector<string> ret;
//			for (int i = 0; i < 4; i++) {
//				char cur = s[i];
//				s[i] = nextNum(cur);
//				ret.push_back(s);
//				s[i] = prevNum(cur);
//				ret.push_back(s);
//				s[i] = cur; //改回去
//			}
//			return ret;
//		};
//		queue<pair<string, int>> q; //用于进行广度优先搜索
//		q.emplace("0000", 0);
//		unordered_set<string> seen; //存储所有搜索过的数字
//		seen.insert("0000");
//		while (!q.empty()) {
//			auto[status, step] = q.front();
//			q.pop();
//			//将status通过一次旋转可以得到的数字入队列
//			for (auto&& nextStatus : getNextStatus(status)) {
//				if (nextStatus == target) //再旋转一次即可解锁
//					return step + 1;
//				if (!seen.count(nextStatus) && !dead.count(nextStatus)) { //该数字没有被搜索过，并且不是一个死亡数字
//					q.emplace(nextStatus, step + 1); //入队列
//					seen.insert(move(nextStatus)); //标记为搜索过
//				}
//			}
//		}
//		return -1; //无法解锁
//	}
//};
////双向广度优先搜索
//class Solution {
//public:
//	int openLock(vector<string>& deadends, string target) {
//		if (target == "0000") //解锁的数字就是初始数字，需要旋转0次
//			return 0;
//		unordered_set<string> dead(deadends.begin(), deadends.end());
//		if (dead.count("0000")) //初始数字在死亡数字中，无法再被旋转
//			return -1;
//		//获取下一个字符
//		auto nextNum = [](char ch)->char{
//			return ch == '9' ? '0' : ch + 1;
//		};
//		//获取上一个字符
//		auto prevNum = [](char ch)->char{
//			return ch == '0' ? '9' : ch - 1;
//		};
//		//获取s通过一次旋转可以得到的数字
//		auto getNextStatus = [&](string s)->vector<string>{
//			vector<string> ret;
//			for (int i = 0; i < 4; i++) {
//				char cur = s[i];
//				s[i] = nextNum(cur);
//				ret.push_back(s);
//				s[i] = prevNum(cur);
//				ret.push_back(s);
//				s[i] = cur; //改回去
//			}
//			return ret;
//		};
//		queue<pair<string, int>> qBegin; //用于进行广度优先搜索
//		qBegin.emplace("0000", 0);
//		unordered_set<string> seenBegin; //存储所有搜索过的数字
//		seenBegin.insert("0000");
//
//		queue<pair<string, int>> qEnd; //用于进行广度优先搜索
//		qEnd.emplace(target, 0);
//		unordered_set<string> seenEnd; //存储所有搜索过的数字
//		seenEnd.insert(target);
//
//		while (!qBegin.empty() && !qEnd.empty()) {
//			int beginSize = qBegin.size();
//			for (int i = 0; i < beginSize; i++) {
//				auto[status, step] = qBegin.front();
//				qBegin.pop();
//				if (seenEnd.count(status))
//					return step + qEnd.front().second;
//				//将status通过一次旋转可以得到的数字入队列
//				for (auto&& nextStatus : getNextStatus(status)) {
//					//if(nextStatus == target) //再旋转一次即可解锁
//					//    return step+1;
//					if (!seenBegin.count(nextStatus) && !dead.count(nextStatus)) { //该数字没有被搜索过，并且不是一个死亡数字
//						qBegin.emplace(nextStatus, step + 1); //入队列
//						seenBegin.insert(move(nextStatus)); //标记为搜索过
//					}
//				}
//			}
//			int endSize = qEnd.size();
//			for (int i = 0; i < endSize; i++) {
//				auto[status, step] = qEnd.front();
//				qEnd.pop();
//				if (seenBegin.count(status))
//					return step + qBegin.front().second;
//				//将status通过一次旋转可以得到的数字入队列
//				for (auto&& nextStatus : getNextStatus(status)) {
//					//if(nextStatus == "0000") //再旋转一次即可解锁
//					//    return step+1;
//					if (!seenEnd.count(nextStatus) && !dead.count(nextStatus)) { //该数字没有被搜索过，并且不是一个死亡数字
//						qEnd.emplace(nextStatus, step + 1); //入队列
//						seenEnd.insert(move(nextStatus)); //标记为搜索过
//					}
//				}
//			}
//		}
//		return -1; //无法解锁
//	}
//};


////所有路径
////深度优先搜索
//class Solution {
//public:
//	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//		tmp.push_back(0);
//		dfs(graph, 0);
//		return ans;
//	}
//	void dfs(vector<vector<int>>& graph, int cur) {
//		if (cur == graph.size() - 1) { //找到了一条路径
//			ans.push_back(tmp);
//			return;
//		}
//		for (auto nextNode : graph[cur]) {
//			tmp.push_back(nextNode);
//			dfs(graph, nextNode);
//			tmp.pop_back(); //回溯
//		}
//	}
//private:
//	vector<vector<int>> ans;
//	vector<int> tmp;
//};


////计算除法
//class Solution {
//public:
//	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//		//建立各个变量与id的映射关系
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
//		//建图（每个点之间的连接关系，及其连边对应的权值）
//		vector<vector<pair<int, double>>> edge(nodeNum);
//		for (int i = 0; i < equations.size(); i++) {
//			int id1 = strId[equations[i][0]], id2 = strId[equations[i][1]];
//			edge[id1].emplace_back(id2, values[i]); //a/b
//			edge[id2].emplace_back(id1, 1.0 / values[i]); //b/a
//		}
//		vector<double> ret; //结果
//		for (int i = 0; i < queries.size(); i++) {
//			string a = queries[i][0], b = queries[i][1];
//			if (!strId.count(a) || !strId.count(b)) { //给定的已知条件中没有出现字符串
//				ret.push_back(-1.0);
//			}
//			else {
//				int id1 = strId[a], id2 = strId[b];
//				//divRet[i]表示id1对应的字符串与i对应的字符串相除的结果
//				vector<double> divRet(nodeNum, -1.0); //初始化为-1.0（无法确定的答案用-1.0代替（可能不是连通图））
//				divRet[id1] = 1.0; //自己与自己相除结果为1.0
//				queue<int> q;
//				q.push(id1);
//				while (!q.empty() && divRet[id2] < 0) { //divRet[id2]小于0说明还需要继续广搜
//					int x = q.front();
//					q.pop();
//					//将与x相连并且没有遍历过的结点加入队列，并计算id1对应的字符串与其相除的结果
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
////Floyd算法
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
//		//预先计算出任意两点的距离（相除的值）
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


////最长递增路径
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
////记忆化深度优先搜索
//class Solution {
//public:
//	int longestIncreasingPath(vector<vector<int>>& matrix) {
//		int m = matrix.size(), n = matrix[0].size();
//		//maxPath[i][j]表示从(i,j)位置出发的最长递增路径
//		vector<vector<int>> maxPath(m, vector<int>(n, 0));
//		int ans = 0;
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				ans = max(ans, dfs(matrix, i, j, maxPath)); //找到每个位置的最长递增路径的最大值
//			}
//		}
//		return ans;
//	}
//	int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& maxPath) {
//		if (maxPath[x][y] != 0) //该位置已经计算过
//			return maxPath[x][y];
//		//maxPath[x][y]等于周围值大于自己的各个位置中，最长递增路径最长的路径+1
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
////拓扑排序
//class Solution {
//public:
//	int longestIncreasingPath(vector<vector<int>>& matrix) {
//		//1、计算每个位置的出度，即从该位置能往几个方向走
//		int m = matrix.size(), n = matrix[0].size();
//		vector<vector<int>> dp(m, vector<int>(n, 0));
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				for (int k = 0; k < 4; k++) {
//					int nx = i + dirs[k][0], ny = j + dirs[k][1];
//					if (nx >= 0 && nx < m&&ny >= 0 && ny < n&&matrix[nx][ny] > matrix[i][j])
//						dp[i][j]++; //出度++
//				}
//			}
//		}
//		//2、将出度为0的位置入队列（出度为0的为路线的终点）
//		queue<pair<int, int>> q;
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (dp[i][j] == 0)
//					q.push({ i, j });
//			}
//		}
//		//3、从出度为0的位置开始进行广搜，能搜几层则最长递增路径长度为几
//		int ans = 0;
//		while (!q.empty()) {
//			ans++;
//			//取出该层全部的位置进行广搜
//			int size = q.size();
//			for (int i = 0; i < size; i++) {
//				auto[x, y] = q.front();
//				q.pop();
//				//对于出度为0的位置的周围的位置来说，如果减去了该出度为0的位置的贡献后，其出度变为0
//				//则应该算作下一层广搜的位置，入队列
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


////课程顺序（拓扑排序）
////深度优先搜索
//class Solution {
//public:
//	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//		edges.resize(numCourses);
//		visited.resize(numCourses, 0);
//		valid = true;
//		//1、根据所给关系建立有向图
//		for (const auto& rel : prerequisites) {
//			edges[rel[1]].push_back(rel[0]);
//		}
//		//2、选一个未搜索的点开始进行深度优先搜索
//		for (int i = 0; i < numCourses&&valid; i++) {
//			if (visited[i] == 0) { //未搜索
//				dfs(i);
//			}
//		}
//		if (!valid) //成环
//			return vector<int>();
//		//栈顶到栈底的序列为拓扑排序
//		reverse(st.begin(), st.end());
//		return st;
//	}
//	void dfs(int u) {
//		visited[u] = 1; //标记为搜索中
//		//搜索相邻节点
//		for (const auto& v : edges[u]) {
//			if (visited[v] == 0) { //相邻节点未搜索
//				dfs(v); //深搜
//				if (!valid)
//					return;
//			}
//			else if (visited[v] == 1) { //相邻节点搜索中，说明成环
//				valid = false;
//				return;
//			}
//		}
//		visited[u] = 2; //标记为已搜索
//		st.push_back(u); //压入栈中
//	}
//private:
//	vector<vector<int>> edges; //存储有向图
//	vector<int> visited; //0表示未搜索，1表示搜索中，2表示已搜索
//	vector<int> st; //数组模拟栈
//	bool valid = true; //是否需要继续判断（如果成环则不必继续判断）
//};
////广度优先搜索
//class Solution {
//public:
//	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//		vector<vector<int>> edges(numCourses);
//		vector<int> inNum(numCourses, 0);
//		//1、根据所给关系建立有向图，并统计每个节点的入度
//		for (const auto& rel : prerequisites) {
//			edges[rel[1]].push_back(rel[0]);
//			inNum[rel[0]]++;
//		}
//		//2、将入度为0的节点入队列
//		queue<int> q;
//		for (int i = 0; i < numCourses; i++) {
//			if (inNum[i] == 0) {
//				q.push(i);
//			}
//		}
//		//3、依次拿出入度为0的节点，将该节点对应的边去掉，并将新出现的入度为0的节点入队列
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
//		if (ans.size() != numCourses) //还有节点的入度不为0，说明成环
//			return vector<int>();
//		return ans;
//	}
//};


////外星文字典（拓扑排序）
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <unordered_map>
//#include <queue>
//using namespace std;
//////深度优先搜索
////class Solution {
////public:
////	string alienOrder(vector<string>& words) {
////		valid = true; //默认存在合法字母顺序
////		//1、遍历所给字符串列表，得到所有出现过的字母
////		for (const string& word : words) {
////			for (const char& ch : word) {
////				if (!edges.count(ch))
////					edges[ch] = vector<char>();
////			}
////		}
////		//2、根据字符串列表中各个相邻的字符串建立有向图
////		int n = words.size();
////		for (int i = 1; i < n && valid; i++) {
////			addEdge(words[i - 1], words[i]);
////		}
////		if (valid == false)
////			return "";
////		//3、从有向图中选取一个节点开始进行深度优先搜索，直到所有节点都被搜索
////		for (const auto [u, _] : edges) {
////			if (!status.count(u)) {
////				dfs(u);
////			}
////			if (valid == false)
////				break;
////		}
////		if (valid == false)
////			return "";
////		//4、深度优先搜索得到的字符串翻转后即为拓扑排序
////		reverse(ans.begin(), ans.end());
////		return ans;
////	}
////	//根据两个相邻字符串向有向图中插入边
////	void addEdge(const string& s1, const string& s2) {
////		int len1 = s1.size(), len2 = s2.size();
////		int len = min(len1, len2);
////		int i = 0;
////		while (i < len) {
////			if (s1[i] != s2[i]) { //插入s1[i]到s2[i]的有向边
////				edges[s1[i]].push_back(s2[i]);
////				break; //两个相邻字符串只能确定两个字母的先后顺序
////			}
////			i++;
////		}
////		if (i == len && len1 > len2) //不存在合法解，比如ab和a
////			valid = false;
////	}
////	//深度优先搜索
////	void dfs(const char u) {
////		status[u] = 1; //将节点u标记为搜索中
////		for (const char& v : edges[u]) {
////			if (!status.count(v)) { //节点v未搜索
////				dfs(v);
////				if (valid == false)
////					return;
////			}
////			else if (status[v] == 1) { //节点v在搜索中，说明有向图成环
////				valid = false;
////				return;
////			}
////		}
////		status[u] = 2; //将节点u标记为搜索完
////		ans += u; //压入栈中
////	}
////private:
////	unordered_map<char, vector<char>> edges; //存储有向图
////	unordered_map<char, int> status; //标记每个节点的搜索状态
////	bool valid; //是否有解
////	string ans; //模拟栈
////};
//class Solution {
//public:
//	string alienOrder(vector<string>& words) {
//		valid = true; //默认存在合法字母顺序
//		//1、遍历所给字符串列表，得到所有出现过的字母
//		for (const string& word : words) {
//			for (const char& ch : word) {
//				if (!edges.count(ch)) {
//					edges[ch] = vector<char>();
//					indegrees[ch] = 0; //字母的入度初始化为0
//				}
//			}
//		}
//		//2、根据字符串列表中各个相邻的字符串建立有向图
//		int n = words.size();
//		for (int i = 1; i < n && valid; i++) {
//			addEdge(words[i - 1], words[i]);
//		}
//		if (valid == false)
//			return "";
//		//3、将入度为0的节点放入队列
//		queue<char> q;
//		for (const auto[ch, indegree] : indegrees) {
//			if (indegree == 0)
//				q.push(ch);
//		}
//		//4、依次拿出入度为0的节点，将该节点对应的边去掉，并将新出现的入度为0的节点放入队列
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
//		if (ans.size() < edges.size()) //还有节点的入度不为0，说明成环（环中的节点不会加入拓扑排序）
//			return "";
//		return ans;
//	}
//	//根据两个相邻字符串向有向图中插入边
//	void addEdge(const string& s1, const string& s2) {
//		int len1 = s1.size(), len2 = s2.size();
//		int len = min(len1, len2);
//		int i = 0;
//		while (i < len) {
//			if (s1[i] != s2[i]) { //插入s1[i]到s2[i]的有向边
//				edges[s1[i]].push_back(s2[i]);
//				indegrees[s2[i]]++; //s2[i]节点的入度++
//				break; //两个相邻字符串只能确定两个字母的先后顺序
//			}
//			i++;
//		}
//		if (i == len && len1 > len2) { //不存在合法解，比如ab和a
//			valid = false;
//		}
//	}
//private:
//	unordered_map<char, vector<char>> edges; //存储有向图
//	unordered_map<char, int> indegrees; //记录每个节点的入度
//	bool valid; //是否有解
//};
//int main() {
//	vector<string> v = { "wrt", "wrf", "wrft", "wrff" };
//	cout << Solution().alienOrder(v) << endl;
//	return 0;
//}


////重建序列（拓扑排序）
//#include <iostream>
//#include <unordered_set>
//#include <queue>
//#include <vector>
//using namespace std;
////广度优先搜索
//class Solution {
//public:
//	bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
//		int n = nums.size();
//		vector<unordered_set<int>> edges(n + 1); //存储有向图
//		vector<int> indegrees(n + 1, 0); //记录每个节点的入度
//		//1、遍历sequences，建立有向图
//		for (const auto& sequence : sequences) {
//			for (int i = 1; i < sequence.size(); i++) {
//				int u = sequence[i - 1], v = sequence[i];
//				if (!edges[u].count(v)) { //防止重复插入
//					edges[u].insert(v); //插入u->v的边
//					indegrees[v]++; //v节点的入度++
//				}
//			}
//		}
//		//2、将入度为0的节点放入队列
//		queue<int> q;
//		for (int i = 1; i <= n; i++) {
//			if (indegrees[i] == 0)
//				q.push(i);
//		}
//		//3、依次拿出入度为0的节点，将该节点的边去掉，并将新出现的入度为0的节点放入队列
//		while (!q.empty()) {
//			//初始时入度为0的节点如果有多个，则说明nums中有数字没在sequences中出现过，因此nums肯定不是最短超序列
//			//后续如果出现队列中的元素个数大于一，则说明下一个数字有多种可能，因此nums不是唯一的最短超序列
//			//sequences中的每个序列都是nums的子序列，因此序列中不存在环
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


////省份数量
//#include <iostream>
//#include <vector>
//using namespace std;
//////深度优先搜索
////class Solution {
////public:
////	int findCircleNum(vector<vector<int>>& isConnected) {
////		int cities = isConnected.size(); //节点的数量
////		vector<bool> visited(cities, false); //记录每个节点是否被访问过
////		int provinces = 0; //记录连通分量的数量
////		for (int i = 0; i < cities; i++) {
////			if (visited[i] == false) { //每次从一个未访问过的节点开始进行深搜
////				dfs(isConnected, i, visited, cities);
////				provinces++;
////			}
////		}
////		return provinces;
////	}
////	void dfs(vector<vector<int>>& isConnected, int u, vector<bool>& visited, int cities) {
////		visited[u] = true; //标记为访问过
////		for (int i = 0; i < cities; i++) {
////			if (isConnected[u][i] == 1 && visited[i] == false) //有连接，并且该节点没有被访问过
////				dfs(isConnected, i, visited, cities);
////		}
////	}
////};
//////广度优先搜索
////class Solution {
////public:
////	int findCircleNum(vector<vector<int>>& isConnected) {
////		int cities = isConnected.size(); //节点的数量
////		vector<bool> visited(cities, false); //记录每个节点是否被访问过
////		int provinces = 0; //记录连通分量的数量
////		for (int i = 0; i < cities; i++) {
////			if (visited[i] == false) { //每次从一个未访问过的节点开始进行广搜
////				queue<int> q;
////				q.push(i);
////				while (!q.empty()) {
////					int u = q.front();
////					visited[u] = true; //标记为访问过
////					q.pop();
////					for (int v = 0; v < cities; v++) {
////						if (isConnected[u][v] == 1 && visited[v] == false) //有连接，并且该节点没有被访问过
////							q.push(v);
////					}
////				}
////				provinces++;
////			}
////		}
////		return provinces;
////	}
////};
////并查集
//class Solution {
//public:
//	int findCircleNum(vector<vector<int>>& isConnected) {
//		int cities = isConnected.size();
//		vector<int> parent(cities);
//		//1、将每个节点的父节点初始化为自己
//		for (int i = 0; i < cities; i++) {
//			parent[i] = i;
//		}
//		//2、根据所给关系建立并查集
//		for (int i = 0; i < cities; i++) {
//			for (int j = i + 1; j < cities; j++) {
//				if (isConnected[i][j] == 1)
//					unionCity(parent, i, j);
//			}
//		}
//		//3、统计连通分量的数量，即父节点为自己的节点的个数
//		int provinces = 0;
//		for (int i = 0; i < cities; i++) {
//			if (parent[i] == i)
//				provinces++;
//		}
//		return provinces;
//	}
//	//将i和j所在的连通域合并
//	void unionCity(vector<int>& parent, int i, int j) {
//		parent[findRoot(parent, j)] = findRoot(parent, i); //将j所在树的根节点的父节点，改为i所在树的根节点
//	}
//	//返回i所在树的根节点
//	int findRoot(vector<int>& parent, int i) {
//		if (parent[i] == i) //根节点就是自己
//			return i;
//		return findRoot(parent, parent[i]); //根节点不是自己，继续看父节点是不是根节点
//	}
//};
//int main() {
//	vector<vector<int>> isConnected = { { 1, 0, 0, 1 }, { 0, 1, 1, 0 }, { 0, 1, 1, 1 }, { 1, 0, 1, 1 } };
//	cout << Solution().findCircleNum(isConnected) << endl;
//	return 0;
//}


////相似的字符串
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
////并查集
//class Solution {
//public:
//	int numSimilarGroups(vector<string>& strs) {
//		int n = strs.size();
//		vector<int> parent(n);
//		//1、将每个节点的父节点初始化为自己
//		for (int i = 0; i < n; i++) {
//			parent[i] = i;
//		}
//		//2、根据所给字符串列表建立并查集
//		for (int i = 0; i < n; i++) {
//			for (int j = i + 1; j < n; j++) {
//				//先找到两个字符串的根节点
//				//如果根节点相同则无需判断这两个字符串是否相似
//				int iRoot = findRoot(parent, i);
//				int jRoot = findRoot(parent, j);
//				if (iRoot == jRoot)
//					continue;
//				if (check(strs[i], strs[j]))
//					parent[jRoot] = iRoot; //将j所在树的根节点的父节点，改为i所在树的根节点
//			}
//		}
//		//3、统计连通分量的数量，即父节点为自己的节点的个数
//		int groups = 0;
//		for (int i = 0; i < n; i++) {
//			if (parent[i] == i)
//				groups++;
//		}
//		return groups;
//	}
//	//返回i节点所在树的根节点
//	int findRoot(vector<int>& parent, int i) {
//		return parent[i] == i ? i : findRoot(parent, parent[i]);
//	}
//	//检查两个字符串是否相似
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


////多余的边
////并查集
//class Solution {
//public:
//	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//		//n个节点的树中有n-1条边，题目给定的是在树种添加一条边后的图edges，因此edges中边的个数为n，即节点的个数
//		int n = edges.size();
//		vector<int> parent(n + 1); //节点编号为1到n，0号下标不用
//		//1、将每个节点的父节点初始化为自己
//		for (int i = 1; i <= n; i++) {
//			parent[i] = i;
//		}
//		//2、根据所给关系建立并查集
//		for (int i = 0; i < n; i++) {
//			int u = edges[i][0], v = edges[i][1];
//			int uRoot = findRoot(parent, u), vRoot = findRoot(parent, v);
//			if (uRoot == vRoot) //u和v的根节点相同，说明这条边是多余的，由于多余的边只有一个，所以直接返回
//				return vector<int>{u, v};
//			parent[uRoot] = vRoot; //将u所在的树合并到v所在的树中
//		}
//		return vector<int>{};
//	}
//	//返回i所在树的根节点
//	int findRoot(vector<int>& parent, int i) {
//		return parent[i] == i ? i : findRoot(parent, parent[i]);
//	}
//};


//最长连续序列
//哈希表+跳过枚举
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		//1、将数组中的树放入unordered_set容器中
		unordered_set<int> numSet;
		for (const auto& num : nums) {
			numSet.insert(num);
		}
		//2、枚举最大长度
		int maxLen = 0;
		for (const auto& num : nums) {
			//当数组中不存在num-1时才需要开始枚举，表示num是连续序列的第一个数
			//因为从连续序列的非第一个数开始枚举，得到的连续序列的长度一定比从第一个数开始枚举的长度短
			if (!numSet.count(num - 1)) {
				int curNum = num;
				int curLen = 1;
				//从num开始往后枚举，若后面一个数在数组中则长度加一
				while (numSet.count(curNum + 1)) {
					curNum++;
					curLen++;
				}
				maxLen = max(maxLen, curLen); //更新最大长度
			}
		}
		return maxLen;
	}
};
