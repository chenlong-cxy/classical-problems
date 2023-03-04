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


//计算除法
class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		//建立各个变量与id的映射关系
		int nodeNum = 0;
		unordered_map<string, int> strId;
		for (int i = 0; i < equations.size(); i++) {
			if (!strId.count(equations[i][0])) {
				strId[equations[i][0]] = nodeNum++;
			}
			if (!strId.count(equations[i][1])) {
				strId[equations[i][1]] = nodeNum++;
			}
		}
		//建图（每个点之间的连接关系，及其连边对应的权值）
		vector<vector<pair<int, double>>> edge(nodeNum);
		for (int i = 0; i < equations.size(); i++) {
			int id1 = strId[equations[i][0]], id2 = strId[equations[i][1]];
			edge[id1].emplace_back(id2, values[i]); //a/b
			edge[id2].emplace_back(id1, 1.0 / values[i]); //b/a
		}
		vector<double> ret; //结果
		for (int i = 0; i < queries.size(); i++) {
			string a = queries[i][0], b = queries[i][1];
			if (!strId.count(a) || !strId.count(b)) { //给定的已知条件中没有出现字符串
				ret.push_back(-1.0);
			}
			else {
				int id1 = strId[a], id2 = strId[b];
				//divRet[i]表示id1对应的字符串与i对应的字符串相除的结果
				vector<double> divRet(nodeNum, -1.0); //初始化为-1.0（无法确定的答案用-1.0代替（可能不是连通图））
				divRet[id1] = 1.0; //自己与自己相除结果为1.0
				queue<int> q;
				q.push(id1);
				while (!q.empty() && divRet[id2] < 0) { //divRet[id2]小于0说明还需要继续广搜
					int x = q.front();
					q.pop();
					//将与x相连并且没有遍历过的结点加入队列，并计算id1对应的字符串与其相除的结果
					for (auto[y, val] : edge[x]) {
						if (divRet[y] < 0) {
							divRet[y] = divRet[x] * val; //(a/b) * (b/c) = a/c
							q.push(y);
						}
					}
				}
				ret.push_back(divRet[id2]);
			}
		}
		return ret;
	}
};
//Floyd算法
class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		int nodeNum = 0;
		unordered_map<string, int> strId;
		for (int i = 0; i < equations.size(); i++) {
			if (!strId.count(equations[i][0])) {
				strId[equations[i][0]] = nodeNum++;
			}
			if (!strId.count(equations[i][1])) {
				strId[equations[i][1]] = nodeNum++;
			}
		}
		vector<vector<double>> graph(nodeNum, vector<double>(nodeNum, -1.0));
		for (int i = 0; i < equations.size(); i++) {
			int id1 = strId[equations[i][0]], id2 = strId[equations[i][1]];
			graph[id1][id2] = values[i];
			graph[id2][id1] = 1.0 / values[i];
		}

		//预先计算出任意两点的距离（相除的值）
		for (int k = 0; k < nodeNum; k++) {
			for (int i = 0; i < nodeNum; i++) {
				for (int j = 0; j < nodeNum; j++) {
					if (graph[i][k] > 0 && graph[k][j] > 0) {
						graph[i][j] = graph[i][k] * graph[k][j];
					}
				}
			}
		}
		vector<double> ret;
		for (int i = 0; i < queries.size(); i++) {
			string a = queries[i][0], b = queries[i][1];
			if (!strId.count(a) || !strId.count(b)) {
				ret.push_back(-1.0);
			}
			else {
				int id1 = strId[a], id2 = strId[b];
				ret.push_back(graph[id1][id2]);
			}
		}
		return ret;
	}
};