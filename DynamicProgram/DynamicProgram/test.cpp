////��¥�ݵ����ٳɱ�
//class Solution {
//public:
//	int minCostClimbingStairs(vector<int>& cost) {
//		int n = cost.size();
//		vector<int> dp(n + 1, 0);
//		dp[0] = dp[1] = 0; //��ʼ����
//		for (int i = 2; i < n + 1; i++) { //��������
//			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); //״̬ת�Ʒ���
//		}
//		return dp[n];
//	}
//};
//class Solution {
//public:
//	int minCostClimbingStairs(vector<int>& cost) {
//		int n = cost.size();
//		//��������
//		int a = 0, b = 0; //��ʼ����
//		for (int i = 2; i < n + 1; i++) { //��������
//			int c = min(a + cost[i - 2], b + cost[i - 1]); //״̬ת�Ʒ���
//			a = b;
//			b = c;
//		}
//		return b;
//	}
//};