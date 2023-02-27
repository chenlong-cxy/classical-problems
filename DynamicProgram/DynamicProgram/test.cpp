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


//最小路径之和
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		for (int i = 1; i < m; i++) { //(i,0)只能从(i-1,0)到达
			grid[i][0] += grid[i - 1][0];
		}
		for (int i = 1; i < n; i++) { //(0,i)只能从(0,i-1)到达
			grid[0][i] += grid[0][i - 1];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]); //(i,j)可以从(i-1,j)或(i,j-1)到达，取较小值
			}
		}
		return grid[m - 1][n - 1];
	}
};