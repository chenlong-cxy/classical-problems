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