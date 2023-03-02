////爬楼梯的最少成本
//class Solution {
//public:
//	int minCostClimbingStairs(vector<int>& cost) {
//		int n = cost.size();
//		vector<int> dp(n + 1, 0);
//		dp[0] = dp[1] = 0; //初始条件
//		for (int i = 2; i < n + 1; i++) { //结束条件
//			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); //状态转移方程
//		}
//		return dp[n];
//	}
//};
//class Solution {
//public:
//	int minCostClimbingStairs(vector<int>& cost) {
//		int n = cost.size();
//		//滚动数组
//		int a = 0, b = 0; //初始条件
//		for (int i = 2; i < n + 1; i++) { //结束条件
//			int c = min(a + cost[i - 2], b + cost[i - 1]); //状态转移方程
//			a = b;
//			b = c;
//		}
//		return b;
//	}
//};


////房屋偷盗
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//	int rob(vector<int>& nums) {
//		int n = nums.size();
//		if (n == 0)
//			return  0;
//		if (n == 1)
//			return nums[0];
//		vector<int> dp(n, 0);
//		//初始条件
//		dp[0] = nums[0];
//		dp[1] = max(nums[0], nums[1]);
//		for (int i = 2; i < n; i++) { //结束条件
//			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]); //状态转移方程
//		}
//		return dp[n - 1];
//	}
//};
//class Solution {
//public:
//	int rob(vector<int>& nums) {
//		int n = nums.size();
//		if (n == 0)
//			return  0;
//		if (n == 1)
//			return nums[0];
//		//初始条件
//		int a = nums[0];
//		int b = max(nums[0], nums[1]);
//		for (int i = 2; i < n; i++) { //结束条件
//			int c = max(a + nums[i], b); //状态转移方程
//			a = b;
//			b = c;
//		}
//		return b;
//	}
//};
//int main()
//{
//	vector<int> v = { 1, 2, 3, 1 };
//	cout << Solution().rob(v) << endl;
//	return 0;
//}


////环形房屋偷盗
//class Solution {
//public:
//	int rob(vector<int>& nums) {
//		int n = nums.size();
//		if (n == 0)
//			return 0;
//		if (n == 1)
//			return nums[0];
//		if (n == 2)
//			return max(nums[0], nums[1]);
//		//0~n-2和1~n-1最大偷盗金额的较大值
//		return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
//	}
//	int robRange(vector<int>& nums, int start, int end) {
//		int n = end - start + 1;
//		vector<int> dp(n, 0);
//		//初始条件
//		dp[0] = nums[start];
//		dp[1] = max(nums[start], nums[start + 1]);
//		for (int i = 2; i < n; i++) { //结束条件
//			dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]); //状态转移方程
//		}
//		return dp[n - 1];
//	}
//};
//class Solution {
//public:
//	int rob(vector<int>& nums) {
//		int n = nums.size();
//		if (n == 0)
//			return 0;
//		if (n == 1)
//			return nums[0];
//		if (n == 2)
//			return max(nums[0], nums[1]);
//		//0~n-2和1~n-1最大偷盗金额的较大值
//		return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
//	}
//	int robRange(vector<int>& nums, int start, int end) {
//		int n = end - start + 1;
//		//初始条件
//		int a = nums[start];
//		int b = max(nums[start], nums[start + 1]);
//		for (int i = 2; i < n; i++) { //结束条件
//			int c = max(a + nums[start + i], b); //状态转移方程
//			a = b;
//			b = c;
//		}
//		return b;
//	}
//};


////粉刷房子
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//	int minCost(vector<vector<int>>& costs) {
//		int n = costs.size();
//		//dp[i][j]表示以第i个房子刷j号颜色结尾的最少花费成本
//		vector<vector<int>> dp(n, vector<int>(3, 0));
//		//初始条件
//		for (int i = 0; i < 3; i++) {
//			dp[0][i] = costs[0][i];
//		}
//		for (int i = 1; i < n; i++) { //结束条件
//			//状态转移方程
//			for (int j = 0; j < 3; j++) {
//				dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + costs[i][j];
//			}
//		}
//		return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
//	}
//};
//class Solution {
//public:
//	int minCost(vector<vector<int>>& costs) {
//		int n = costs.size();
//		//minCost[i]表示以当前房子刷i号颜色为结尾的最少花费成本
//		vector<int> minCost(3);
//		//初始条件
//		for (int i = 0; i < 3; i++) {
//			minCost[i] = costs[0][i];
//		}
//		for (int i = 1; i < n; i++) { //结束条件
//			//状态转移方程
//			vector<int> tmp(3);
//			for (int j = 0; j < 3; j++) {
//				tmp[j] = min(minCost[(j + 1) % 3], minCost[(j + 2) % 3]) + costs[i][j];
//			}
//			minCost = tmp;
//		}
//		return min(minCost[0], min(minCost[1], minCost[2]));
//	}
//};
//class Solution {
//public:
//	int minCost(vector<vector<int>>& costs) {
//		int n = costs.size();
//		for (int i = 1; i < n; i++) {
//			//直接在原数组上面修改
//			costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
//			costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
//			costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
//		}
//		return min(costs[n - 1][0], min(costs[n - 1][1], costs[n - 1][2]));
//	}
//};
//int main()
//{
//	vector<vector<int>> vv = { { 5, 8, 6 }, { 19, 14, 13 }, { 7, 5, 12 }, { 14, 15, 17 }, { 3, 20, 10 } };
//	cout << Solution().minCost(vv) << endl;
//	return 0;
//}


////翻转字符
//class Solution {
//public:
//	int minFlipsMonoIncr(string s) {
//		int n = s.size();
//		//dp[i][j]表示第i个位置为j所需的最小翻转次数
//		vector<vector<int>> dp(n, vector<int>(2, 0));
//		//初始条件
//		dp[0][0] = (s[0] == '1');
//		dp[0][1] = (s[0] == '0');
//		for (int i = 1; i < n; i++) { //结束条件
//			//状态转移方程
//			dp[i][0] = dp[i - 1][0] + (s[i] == '1'); //0前面只能是0
//			dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (s[i] == '0'); //1前面可以是0也可以是1
//		}
//		return min(dp[n - 1][0], dp[n - 1][1]);
//	}
//};
//class Solution {
//public:
//	int minFlipsMonoIncr(string s) {
//		int n = s.size();
//		//初始条件
//		int end0 = (s[0] == '1');
//		int end1 = (s[0] == '0');
//		for (int i = 1; i < n; i++) { //结束条件
//			//状态转移方程
//			int curEnd0 = end0 + (s[i] == '1'); //0的前面只能是0
//			int curEnd1 = min(end0, end1) + (s[i] == '0'); //1的前面可以是0也可以是1
//			//滚动数组
//			end0 = curEnd0;
//			end1 = curEnd1;
//		}
//		return min(end0, end1); //最后一个位置是0或是1的较小翻转次数
//	}
//};


////最长斐波那契数列
//class Solution {
//public:
//	int lenLongestFibSubseq(vector<int>& arr) {
//		int n = arr.size();
//		//记录数组中每个元素与其下标的对应关系
//		unordered_map<int, int> valToIndex;
//		for (int i = 0; i < n; i++) {
//			valToIndex[arr[i]] = i;
//		}
//		//dp[j][i]表示以arr[j]和arr[i]作为最后两个数字的斐波那契数列的长度
//		vector<vector<int>> dp(n, vector<int>(n, 0));
//		int ans = 0;
//		for (int i = 0; i < n; i++) { //枚举斐波那契数列的最后一个数字
//			for (int j = i - 1; j >= 0 && 2 * arr[j] > arr[i]; j--) { //枚举斐波那契数列的倒数第二个数字
//				//k为倒数第三个斐波那契数在数组中的下标
//				int k = -1;
//				if (valToIndex.count(arr[i] - arr[j])) { //第三个斐波那契数存在于数组中
//					k = valToIndex[arr[i] - arr[j]];
//				}
//				if (k >= 0) {
//					//以arr[j]和arr[i]作为最后两个数字的斐波那契数列的长度
//					//等于以arr[k]和arr[j]作为最后两个数字的斐波那契数列的长度+1
//					//如果以arr[k]和arr[j]作为最后两个数字的斐波那契数列不存在
//					//则arr[k]、arr[j]和arr[i]组成一个斐波那契数列，长度为3
//					dp[j][i] = max(dp[k][j] + 1, 3);
//				}
//				ans = max(ans, dp[j][i]); //更新最长斐波那契数列的长度
//			}
//		}
//		return ans;
//	}
//};


////最少回文分割
//class Solution {
//public:
//	int minCut(string s) {
//		int n = s.size();
//		//记录以下标i开始j结束的子字符串是否是回文串
//		vector<vector<bool>> dp(n, vector<bool>(n, true));
//		for (int i = n - 1; i >= 0; i--) {
//			for (int j = i + 1; j < n; j++) {
//				dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
//			}
//		}
//		//f[i]表示以下标i为结尾的字符串最少回文分割的次数
//		vector<int> f(n, INT_MAX);
//		for (int i = 0; i < n; i++) {
//			if (dp[0][i]) { //以下标i结尾的字符串本身就是回文串，无需分割
//				f[i] = 0;
//			}
//			else {
//				for (int j = 0; j < i; j++) { //尝试把第i个位置的字符放入以j+1位置开始的字符串中
//					if (dp[j + 1][i]) { //以下标j+1开始i结束的字符串是回文串
//						f[i] = min(f[i], f[j] + 1);
//					} //一定至少会进入if一次，因为dp[i][i]一定为true
//				}
//			}
//		}
//		return f[n - 1];
//	}
//};


////最长公共子序列
//class Solution {
//public:
//	int longestCommonSubsequence(string text1, string text2) {
//		int m = text1.size(), n = text2.size();
//		//dp[i][j]表示text1中长度为i的前缀字符串于text2中长度为j的前缀字符串的最长公共子序列的长度
//		//初始条件：一个长度为0的字符串与其他字符串没有公共子序列
//		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//		for (int i = 1; i < m + 1; i++) {
//			for (int j = 1; j < n + 1; j++) {
//				if (text1[i - 1] == text2[j - 1]) //两个字符串最后的字符相同
//					dp[i][j] = dp[i - 1][j - 1] + 1;
//				else
//					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//			}
//		}
//		return dp[m][n];
//	}
//};


////字符串交织
//#include <iostream>
//#include <string>
//using namespace std;
////回溯+双指针
//class Solution {
//public:
//	bool isInterleave(string s1, string s2, string s3) {
//		if (s1.size() + s2.size() != s3.size())
//			return false;
//		return dfs(s1, s2, s3, 0, 0, 0);
//	}
//	bool dfs(const string& s1, const string& s2, const string& s3, int idx1, int idx2, int idx3) {
//		if (idx3 == s3.size())
//			return true;
//		if (idx1 == s1.size() && s2[idx2] != s3[idx3])
//			return false;
//		if (idx2 == s2.size() && s1[idx1] != s3[idx3])
//			return false;
//		if (idx1 < s1.size() && s1[idx1] == s3[idx3] && dfs(s1, s2, s3, idx1 + 1, idx2, idx3 + 1))
//			return true;
//		if (idx2 < s2.size() && s2[idx2] == s3[idx3] && dfs(s1, s2, s3, idx1, idx2 + 1, idx3 + 1))
//			return true;
//		return false;
//	}
//};
////动态规划
//class Solution {
//public:
//	bool isInterleave(string s1, string s2, string s3) {
//		int m = s1.size(), n = s2.size();
//		if (m + n != s3.size())
//			return false;
//		//dp[i][j]表示s1的前i个字符和s2的前j个字符能否交织组成s3的前i+j个字符
//		vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
//		dp[0][0] = true; //初始条件
//		for (int i = 0; i <= m; i++) { //结束条件
//			for (int j = 0; j <= n; j++) { //结束条件
//				//状态转移方程（注意|=，避免第二次的false覆盖第一次的true）
//				if (i > 0 )
//					dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
//				if (j > 0)
//					dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
//			}
//		}
//		return dp[m][n];
//	}
//};
////滚动数组
//class Solution {
//public:
//	bool isInterleave(string s1, string s2, string s3) {
//		int m = s1.size(), n = s2.size();
//		if (m + n != s3.size())
//			return false;
//		//dp[i][j]表示s1的前i个字符和s2的前j个字符能否交织组成s3的前i+j个字符
//		vector<int> f(n + 1, false);
//		f[0] = true; //初始条件
//		for (int i = 0; i <= m; i++) { //结束条件
//			for (int j = 0; j <= n; j++) { //结束条件
//				//状态转移方程（注意|=，避免第二次的false覆盖第一次的true）
//				if (i > 0)
//					f[j] &= (s1[i - 1] == s3[i + j - 1]); //如果s1[i-1] != s3[i+j-1]则相当于将f[j]设置为false
//				if (j > 0)
//					f[j] |= (f[j - 1] && s2[j - 1] == s3[i + j - 1]);
//			}
//		}
//		return f[n];
//	}
//};
//int main()
//{
//	cout << Solution().isInterleave("", "b", "b") << endl;
//	return 0;
//}


////子序列的数目
//class Solution {
//public:
//	int numDistinct(string s, string t) {
//		int count = 0;
//		string tmp;
//		dfs(s, t, tmp, 0, count);
//		return count;
//	}
//	void dfs(const string& s, const string& t, string& tmp, int cur, int& count) {
//		if (cur == s.size()) {
//			if (tmp == t)
//				count++;
//			return;
//		}
//		tmp += s[cur];
//		dfs(s, t, tmp, cur + 1, count);
//		tmp.pop_back(); //回溯
//		dfs(s, t, tmp, cur + 1, count);
//	}
//};
////从后往前进行匹配
//class Solution {
//public:
//	int numDistinct(string s, string t) {
//		int m = s.size(), n = t.size();
//		if (m < n) //s的长度比t小
//			return 0;
//		//dp[i][j]表示在s[i:]的子序列中t[j:]出现的个数
//		vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
//		//初始条件
//		for (int i = 0; i < m + 1; i++) //空字符串t是任何字符串s的子序列
//			dp[i][n] = 1;
//		for (int i = 0; i < n; i++) //非空字符串t不是空字符串s的子序列
//			dp[m][i] = 0;
//		for (int i = m - 1; i >= 0; i--) { //结束条件
//			for (int j = n - 1; j >= 0; j--) { //结束条件
//				if (s[i] == t[j]) //s[i]与t[j]匹配
//					dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j]; //dp[i+1][j+1]表示让s[i]和t[j]匹配的方案数，dp[i+1][j]表示不让s[i]和t[j]匹配的方案数
//				else
//					dp[i][j] = dp[i + 1][j]; //只能考虑dp[i+1][j]
//			}
//		}
//		return dp[0][0]; //在s[0:]的子序列中t[0:]出现的个数
//	}
//};
////从前往后进行匹配
//class Solution {
//public:
//	int numDistinct(string s, string t) {
//		int m = s.size(), n = t.size();
//		if (m < n)
//			return 0;
//		//dp[i][j]表示s的前i个字符组成的字符串的子序列中(t的前j个字符组成的字符串)出现的个数
//		vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
//		//初始条件
//		for (int i = 0; i < m + 1; i++) //空字符串t是任何字符串s的子序列
//			dp[i][0] = 1;
//		for (int i = 1; i < n + 1; i++) //非空字符串t不是空字符串s的子序列
//			dp[0][i] = 0;
//		for (int i = 1; i < m + 1; i++) {
//			for (int j = 1; j < n + 1; j++) {
//				if (s[i - 1] == t[j - 1]) //s的第i-1个字符和t的第j-1个字符匹配
//					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; //让s的第i-1个字符匹配或不让
//				else
//					dp[i][j] = dp[i - 1][j]; //只能不让s的第i-1个字符匹配
//			}
//		}
//		return dp[m][n];
//	}
//};


////路径的数目
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		//dp[i][j]表示从(0,0)到达(i,j)位置的路径数目
//		vector<vector<int>> dp(m, vector<int>(n, 1)); //(0,x)和(x,0)位置的方案数都设置为1
//		for (int i = 1; i < m; i++) {
//			for (int j = 1; j < n; j++) {
//				dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; //(i,j)位置只能从(i-1,j)或(i,j-1)位置到达
//			}
//		}
//		return dp[m - 1][n - 1];
//	}
//};
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		long long ans = 1;
//		for (int x = n, y = 1; y < m; x++, y++) {
//			ans = ans * x / y; //组合数学
//		}
//		return ans;
//	}
//};
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		//滚动数组
//		vector<int> dp(n, 1);
//		for (int i = 1; i < m; i++) {
//			for (int j = 1; j < n; j++) {
//				dp[j] = dp[j - 1] + dp[j];
//			}
//		}
//		return dp[n - 1];
//	}
//};


////最小路径之和
//class Solution {
//public:
//	int minPathSum(vector<vector<int>>& grid) {
//		int m = grid.size(), n = grid[0].size();
//		for (int i = 1; i < m; i++) { //(i,0)只能从(i-1,0)到达
//			grid[i][0] += grid[i - 1][0];
//		}
//		for (int i = 1; i < n; i++) { //(0,i)只能从(0,i-1)到达
//			grid[0][i] += grid[0][i - 1];
//		}
//		for (int i = 1; i < m; i++) {
//			for (int j = 1; j < n; j++) {
//				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]); //(i,j)可以从(i-1,j)或(i,j-1)到达，取较小值
//			}
//		}
//		return grid[m - 1][n - 1];
//	}
//};


////三角形中最小路径之和
//class Solution {
//public:
//	int minimumTotal(vector<vector<int>>& triangle) {
//		int n = triangle.size();
//		//dp[i][j]表示从顶部到(i,j)位置的最小路径和
//		vector<vector<int>> dp(n, vector<int>(n, 0));
//		dp[0][0] = triangle[0][0]; //初始条件
//		for (int i = 1; i < n; i++) {
//			dp[i][0] = dp[i - 1][0] + triangle[i][0]; //(i,0)只能从(i-1,0)到达
//			for (int j = 1; j < i; j++) {
//				//(i,j)选择(i-1,j-1)和(i-1,j)中路径和较小的位置到达
//				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
//			}
//			dp[i][i] = dp[i - 1][i - 1] + triangle[i][i]; //(i,i)只能从(i-1,i-1)到达
//		}
//		//选择最后一行中较小的路径和
//		int minSum = INT_MAX;
//		for (int i = 0; i < n; i++) {
//			minSum = min(minSum, dp[n - 1][i]);
//		}
//		return minSum;
//	}
//};
////滚动数组
//class Solution {
//public:
//	int minimumTotal(vector<vector<int>>& triangle) {
//		int n = triangle.size();
//		vector<int> arr;
//		arr.push_back(triangle[0][0]);
//		for (int i = 1; i < n; i++) {
//			vector<int> tmp(i + 1, 0);
//			tmp[0] = arr[0] + triangle[i][0];
//			for (int j = 1; j < i; j++) {
//				tmp[j] = min(arr[j - 1], arr[j]) + triangle[i][j];
//			}
//			tmp[i] = arr[i - 1] + triangle[i][i];
//			arr = tmp;
//		}
//		int minSum = INT_MAX;
//		for (const auto& e : arr) {
//			minSum = min(minSum, e);
//		}
//		return minSum;
//	}
//};
////一维数组
//class Solution {
//public:
//	int minimumTotal(vector<vector<int>>& triangle) {
//		int n = triangle.size();
//		vector<int> dp(n, 0);
//		dp[0] = triangle[0][0];
//		for (int i = 1; i < n; i++) {
//			dp[i] = dp[i - 1] + triangle[i][i];
//			for (int j = i - 1; j >= 1; j--) {
//				dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
//			}
//			dp[0] = dp[0] + triangle[i][0];
//		}
//		int minSum = INT_MAX;
//		for (const auto& e : dp) {
//			minSum = min(minSum, e);
//		}
//		return minSum;
//	}
//};


////分割等和子集
//class Solution {
//public:
//	bool canPartition(vector<int>& nums) {
//		int n = nums.size();
//		if (n < 2) //数组无法进行分割
//			return false;
//		int sum = 0, maxNum = INT_MIN;
//		for (const auto& num : nums) {
//			maxNum = max(maxNum, num);
//			sum += num;
//		}
//		int target = sum / 2;
//		if (sum % 2 == 1 || maxNum > target) //数组中的元素和为奇数或数组中的最大元素大于元素和的一半
//			return false;
//		//dp[i][j]表示nums中下标从0到i的的元素能否组成j
//		vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
//		dp[0][nums[0]] = true;
//		for (int i = 1; i < n; i++) {
//			for (int j = 0; j <= target; j++) {
//				if (j == 0) { //任何序列不选取任何数即可组成0
//					dp[i][j] = true;
//				}
//				else if (nums[i] > j) { //只能看0到i-1的数能否组成j
//					dp[i][j] = dp[i - 1][j];
//				}
//				else { //0到i-1的数能组成j或0到i-1的数能组成j-当前数
//					dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
//				}
//			}
//		}
//		return dp[n - 1][target]; //0到n-1的数能否组成target
//	}
//};
////降为一维数组
//class Solution {
//public:
//	bool canPartition(vector<int>& nums) {
//		int n = nums.size();
//		if (n < 2)
//			return false;
//		int sum = 0, maxNum = INT_MIN;
//		for (const auto& num : nums) {
//			sum += num;
//			maxNum = max(maxNum, num);
//		}
//		int target = sum / 2;
//		if (sum & 1 == 1 || maxNum > target)
//			return false;
//		vector<bool> dp(target + 1, false);
//		dp[0] = true;
//		dp[nums[0]] = true; //nums[0]不会大于target
//		for (int i = 1; i < n; i++) {
//			for (int j = target; j >= 1; j--) { //需要从后往前进行计算，避免dp[j]之前的值在使用之前被更新
//				if (nums[i] > j)
//					dp[j] = dp[j];
//				else
//					dp[j] = dp[j] | dp[j - nums[i]];
//			}
//		}
//		return dp[target];
//	}
//};


////加减的目标值
////回溯
//class Solution {
//public:
//	int findTargetSumWays(vector<int>& nums, int target) {
//		int count = 0;
//		dfs(nums, 0, target, 0, count);
//		return count;
//	}
//	void dfs(const vector<int>& nums, int cur, int target, int tmp, int& count) {
//		if (cur == nums.size()) {
//			if (tmp == target)
//				count++;
//			return;
//		}
//		dfs(nums, cur + 1, target, tmp + nums[cur], count); //当前数前加+
//		dfs(nums, cur + 1, target, tmp - nums[cur], count); //当前数前加-
//	}
//};
//class Solution {
//public:
//	//设在前面添加-的元素的元素和为neg，则在前面添加+的元素的元素和为sum-neg
//	//-neg+(sum-neg)=sum-2*neg=target
//	//neg=(sum-target)/2
//	int findTargetSumWays(vector<int>& nums, int target) {
//		int sum = 0;
//		for (const auto& num : nums) {
//			sum += num;
//		}
//		if (sum - target < 0 || (sum - target) & 1) //因为nums是一个正整数数组，因此sum-target必须为非负偶数
//			return 0;
//		int neg = (sum - target) / 2;
//		int n = nums.size();
//		//dp[i][j]表示数组中前i个数能够构造出j的数目
//		vector<vector<int>> dp(n + 1, vector<int>(neg + 1, 0));
//		dp[0][0] = 1; //前0个数能构造出0，但不能构造出其他数
//		for (int i = 1; i <= n; i++) {
//			for (int j = 0; j <= neg; j++) {
//				if (nums[i - 1] > j) //前i个数的最后一个数的下标是i-1
//					dp[i][j] = dp[i - 1][j];
//				else
//					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
//			}
//		}
//		return dp[n][neg];
//	}
//};
//class Solution {
//public:
//	int findTargetSumWays(vector<int>& nums, int target) {
//		int sum = 0;
//		for (const auto& num : nums) {
//			sum += num;
//		}
//		int diff = sum - target;
//		if (diff < 0 || diff & 1)
//			return 0;
//		int neg = diff / 2;
//		int n = nums.size();
//		vector<int> dp(neg + 1, 0); //滚动数组
//		dp[0] = 1;
//		// for(int i = 1;i <= n;i++) {
//		//     for(int j = neg;j >= 0;j--) {
//		//         if(nums[i-1] > j)
//		//             dp[j] = dp[j];
//		//         else
//		//             dp[j] = dp[j] + dp[j-nums[i-1]];
//		//     }
//		// }
//		for (const auto& num : nums) {
//			for (int j = neg; j >= num; j--) { //注意内循环倒序
//				dp[j] = dp[j] + dp[j - num];
//			}
//		}
//		return dp[neg];
//	}
//};


////最少硬币的数目
////回溯
//class Solution {
//public:
//	int coinChange(vector<int>& coins, int amount) {
//		dfs(coins, 0, amount, 0);
//		if (minCount == INT_MAX) //没有任何一种硬币组合能组成总金额
//			return -1;
//		else
//			return minCount;
//	}
//	void dfs(vector<int>& coins, int cur, int target, int count) {
//		if (target == 0) { //总金额组成完毕
//			minCount = min(minCount, count);
//			return;
//		}
//		if (cur == coins.size()) //所有面额的硬币均已被使用
//			return;
//		if (target - coins[cur] >= 0)
//			dfs(coins, cur, target - coins[cur], count + 1); //考虑当前面额硬币
//		dfs(coins, cur + 1, target, count); //不考虑当前面额硬币
//	}
//private:
//	int minCount = INT_MAX;
//};
////动规+记忆化搜索（自顶向下）
//class Solution {
//public:
//	int coinChange(vector<int>& coins, int amount) {
//		vector<int> count(amount, 0); //记忆化搜索
//		return dp(coins, amount, count);
//	}
//	//返回可以凑成amount所需的最少的硬币个数dp[amount-1]
//	int dp(vector<int>& coins, int amount, vector<int>& count) {
//		if (amount < 0) //无法组成
//			return -1;
//		if (amount == 0) //需要0个硬币
//			return 0;
//		if (count[amount - 1] != 0) //该值已经被计算过，直接返回
//			return count[amount - 1];
//		int minCount = INT_MAX;
//		//f(amount) = f(amount-某个硬币值) + 1
//		//枚举各个硬币值，找到dp[amount-某个硬币值]的最小值
//		for (const auto& coin : coins) {
//			int n = dp(coins, amount - coin, count);
//			if (n != -1 && n + 1 < minCount)
//				minCount = n + 1;
//		}
//		count[amount - 1] = minCount == INT_MAX ? -1 : minCount; //记录凑成amount所需的最少硬币个数
//		return count[amount - 1];
//	}
//};
////动规（自底向上）
//class Solution {
//public:
//	int coinChange(vector<int>& coins, int amount) {
//		//dp[i]表示凑成总金额i所需的最少硬币个数
//		vector<int> dp(amount + 1, INT_MAX - 1); //避免INT_MAX+1溢出
//		dp[0] = 0; //初始条件
//		for (int i = 1; i <= amount; i++) {
//			for (int j = 0; j < coins.size(); j++) {
//				if (coins[j] <= i) //硬币的面额不大于要凑成的总金额，可以尝试使用
//					dp[i] = min(dp[i], dp[i - coins[j]] + 1); //状态转移方程
//			}
//		}
//		return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
//	}
//};


//排列的数目
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v = { 1, 2, 3 };
	cout << Solution().combinationSum4(v, 4) << endl;

	return 0;
}
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		//dp[i]表示组成i的元素组合的个数
		vector<int> dp(target + 1, 0);
		dp[0] = 1; //初始条件
		for (int i = 1; i <= target; i++) {
			//状态转移方程
			for (const auto& num : nums) {
				if (num <= i&&dp[i] < INT_MAX - dp[i - num]) //中间结果可能会越界
					dp[i] += dp[i - num];
			}
		}
		return dp[target];
	}
};