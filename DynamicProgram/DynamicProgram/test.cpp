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


////����͵��
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
//		//��ʼ����
//		dp[0] = nums[0];
//		dp[1] = max(nums[0], nums[1]);
//		for (int i = 2; i < n; i++) { //��������
//			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]); //״̬ת�Ʒ���
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
//		//��ʼ����
//		int a = nums[0];
//		int b = max(nums[0], nums[1]);
//		for (int i = 2; i < n; i++) { //��������
//			int c = max(a + nums[i], b); //״̬ת�Ʒ���
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


////���η���͵��
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
//		//0~n-2��1~n-1���͵�����Ľϴ�ֵ
//		return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
//	}
//	int robRange(vector<int>& nums, int start, int end) {
//		int n = end - start + 1;
//		vector<int> dp(n, 0);
//		//��ʼ����
//		dp[0] = nums[start];
//		dp[1] = max(nums[start], nums[start + 1]);
//		for (int i = 2; i < n; i++) { //��������
//			dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]); //״̬ת�Ʒ���
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
//		//0~n-2��1~n-1���͵�����Ľϴ�ֵ
//		return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
//	}
//	int robRange(vector<int>& nums, int start, int end) {
//		int n = end - start + 1;
//		//��ʼ����
//		int a = nums[start];
//		int b = max(nums[start], nums[start + 1]);
//		for (int i = 2; i < n; i++) { //��������
//			int c = max(a + nums[start + i], b); //״̬ת�Ʒ���
//			a = b;
//			b = c;
//		}
//		return b;
//	}
//};


////��ˢ����
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//	int minCost(vector<vector<int>>& costs) {
//		int n = costs.size();
//		//dp[i][j]��ʾ�Ե�i������ˢj����ɫ��β�����ٻ��ѳɱ�
//		vector<vector<int>> dp(n, vector<int>(3, 0));
//		//��ʼ����
//		for (int i = 0; i < 3; i++) {
//			dp[0][i] = costs[0][i];
//		}
//		for (int i = 1; i < n; i++) { //��������
//			//״̬ת�Ʒ���
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
//		//minCost[i]��ʾ�Ե�ǰ����ˢi����ɫΪ��β�����ٻ��ѳɱ�
//		vector<int> minCost(3);
//		//��ʼ����
//		for (int i = 0; i < 3; i++) {
//			minCost[i] = costs[0][i];
//		}
//		for (int i = 1; i < n; i++) { //��������
//			//״̬ת�Ʒ���
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
//			//ֱ����ԭ���������޸�
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


////��ת�ַ�
//class Solution {
//public:
//	int minFlipsMonoIncr(string s) {
//		int n = s.size();
//		//dp[i][j]��ʾ��i��λ��Ϊj�������С��ת����
//		vector<vector<int>> dp(n, vector<int>(2, 0));
//		//��ʼ����
//		dp[0][0] = (s[0] == '1');
//		dp[0][1] = (s[0] == '0');
//		for (int i = 1; i < n; i++) { //��������
//			//״̬ת�Ʒ���
//			dp[i][0] = dp[i - 1][0] + (s[i] == '1'); //0ǰ��ֻ����0
//			dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (s[i] == '0'); //1ǰ�������0Ҳ������1
//		}
//		return min(dp[n - 1][0], dp[n - 1][1]);
//	}
//};
//class Solution {
//public:
//	int minFlipsMonoIncr(string s) {
//		int n = s.size();
//		//��ʼ����
//		int end0 = (s[0] == '1');
//		int end1 = (s[0] == '0');
//		for (int i = 1; i < n; i++) { //��������
//			//״̬ת�Ʒ���
//			int curEnd0 = end0 + (s[i] == '1'); //0��ǰ��ֻ����0
//			int curEnd1 = min(end0, end1) + (s[i] == '0'); //1��ǰ�������0Ҳ������1
//			//��������
//			end0 = curEnd0;
//			end1 = curEnd1;
//		}
//		return min(end0, end1); //���һ��λ����0����1�Ľ�С��ת����
//	}
//};


////�쳲���������
//class Solution {
//public:
//	int lenLongestFibSubseq(vector<int>& arr) {
//		int n = arr.size();
//		//��¼������ÿ��Ԫ�������±�Ķ�Ӧ��ϵ
//		unordered_map<int, int> valToIndex;
//		for (int i = 0; i < n; i++) {
//			valToIndex[arr[i]] = i;
//		}
//		//dp[j][i]��ʾ��arr[j]��arr[i]��Ϊ����������ֵ�쳲��������еĳ���
//		vector<vector<int>> dp(n, vector<int>(n, 0));
//		int ans = 0;
//		for (int i = 0; i < n; i++) { //ö��쳲��������е����һ������
//			for (int j = i - 1; j >= 0 && 2 * arr[j] > arr[i]; j--) { //ö��쳲��������еĵ����ڶ�������
//				//kΪ����������쳲��������������е��±�
//				int k = -1;
//				if (valToIndex.count(arr[i] - arr[j])) { //������쳲�������������������
//					k = valToIndex[arr[i] - arr[j]];
//				}
//				if (k >= 0) {
//					//��arr[j]��arr[i]��Ϊ����������ֵ�쳲��������еĳ���
//					//������arr[k]��arr[j]��Ϊ����������ֵ�쳲��������еĳ���+1
//					//�����arr[k]��arr[j]��Ϊ����������ֵ�쳲��������в�����
//					//��arr[k]��arr[j]��arr[i]���һ��쳲��������У�����Ϊ3
//					dp[j][i] = max(dp[k][j] + 1, 3);
//				}
//				ans = max(ans, dp[j][i]); //�����쳲��������еĳ���
//			}
//		}
//		return ans;
//	}
//};


////���ٻ��ķָ�
//class Solution {
//public:
//	int minCut(string s) {
//		int n = s.size();
//		//��¼���±�i��ʼj���������ַ����Ƿ��ǻ��Ĵ�
//		vector<vector<bool>> dp(n, vector<bool>(n, true));
//		for (int i = n - 1; i >= 0; i--) {
//			for (int j = i + 1; j < n; j++) {
//				dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
//			}
//		}
//		//f[i]��ʾ���±�iΪ��β���ַ������ٻ��ķָ�Ĵ���
//		vector<int> f(n, INT_MAX);
//		for (int i = 0; i < n; i++) {
//			if (dp[0][i]) { //���±�i��β���ַ���������ǻ��Ĵ�������ָ�
//				f[i] = 0;
//			}
//			else {
//				for (int j = 0; j < i; j++) { //���԰ѵ�i��λ�õ��ַ�������j+1λ�ÿ�ʼ���ַ�����
//					if (dp[j + 1][i]) { //���±�j+1��ʼi�������ַ����ǻ��Ĵ�
//						f[i] = min(f[i], f[j] + 1);
//					} //һ�����ٻ����ifһ�Σ���Ϊdp[i][i]һ��Ϊtrue
//				}
//			}
//		}
//		return f[n - 1];
//	}
//};


////�����������
//class Solution {
//public:
//	int longestCommonSubsequence(string text1, string text2) {
//		int m = text1.size(), n = text2.size();
//		//dp[i][j]��ʾtext1�г���Ϊi��ǰ׺�ַ�����text2�г���Ϊj��ǰ׺�ַ���������������еĳ���
//		//��ʼ������һ������Ϊ0���ַ����������ַ���û�й���������
//		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//		for (int i = 1; i < m + 1; i++) {
//			for (int j = 1; j < n + 1; j++) {
//				if (text1[i - 1] == text2[j - 1]) //�����ַ��������ַ���ͬ
//					dp[i][j] = dp[i - 1][j - 1] + 1;
//				else
//					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//			}
//		}
//		return dp[m][n];
//	}
//};


////�ַ�����֯
//#include <iostream>
//#include <string>
//using namespace std;
////����+˫ָ��
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
////��̬�滮
//class Solution {
//public:
//	bool isInterleave(string s1, string s2, string s3) {
//		int m = s1.size(), n = s2.size();
//		if (m + n != s3.size())
//			return false;
//		//dp[i][j]��ʾs1��ǰi���ַ���s2��ǰj���ַ��ܷ�֯���s3��ǰi+j���ַ�
//		vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
//		dp[0][0] = true; //��ʼ����
//		for (int i = 0; i <= m; i++) { //��������
//			for (int j = 0; j <= n; j++) { //��������
//				//״̬ת�Ʒ��̣�ע��|=������ڶ��ε�false���ǵ�һ�ε�true��
//				if (i > 0 )
//					dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
//				if (j > 0)
//					dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
//			}
//		}
//		return dp[m][n];
//	}
//};
////��������
//class Solution {
//public:
//	bool isInterleave(string s1, string s2, string s3) {
//		int m = s1.size(), n = s2.size();
//		if (m + n != s3.size())
//			return false;
//		//dp[i][j]��ʾs1��ǰi���ַ���s2��ǰj���ַ��ܷ�֯���s3��ǰi+j���ַ�
//		vector<int> f(n + 1, false);
//		f[0] = true; //��ʼ����
//		for (int i = 0; i <= m; i++) { //��������
//			for (int j = 0; j <= n; j++) { //��������
//				//״̬ת�Ʒ��̣�ע��|=������ڶ��ε�false���ǵ�һ�ε�true��
//				if (i > 0)
//					f[j] &= (s1[i - 1] == s3[i + j - 1]); //���s1[i-1] != s3[i+j-1]���൱�ڽ�f[j]����Ϊfalse
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


////�����е���Ŀ
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
//		tmp.pop_back(); //����
//		dfs(s, t, tmp, cur + 1, count);
//	}
//};
////�Ӻ���ǰ����ƥ��
//class Solution {
//public:
//	int numDistinct(string s, string t) {
//		int m = s.size(), n = t.size();
//		if (m < n) //s�ĳ��ȱ�tС
//			return 0;
//		//dp[i][j]��ʾ��s[i:]����������t[j:]���ֵĸ���
//		vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
//		//��ʼ����
//		for (int i = 0; i < m + 1; i++) //���ַ���t���κ��ַ���s��������
//			dp[i][n] = 1;
//		for (int i = 0; i < n; i++) //�ǿ��ַ���t���ǿ��ַ���s��������
//			dp[m][i] = 0;
//		for (int i = m - 1; i >= 0; i--) { //��������
//			for (int j = n - 1; j >= 0; j--) { //��������
//				if (s[i] == t[j]) //s[i]��t[j]ƥ��
//					dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j]; //dp[i+1][j+1]��ʾ��s[i]��t[j]ƥ��ķ�������dp[i+1][j]��ʾ����s[i]��t[j]ƥ��ķ�����
//				else
//					dp[i][j] = dp[i + 1][j]; //ֻ�ܿ���dp[i+1][j]
//			}
//		}
//		return dp[0][0]; //��s[0:]����������t[0:]���ֵĸ���
//	}
//};
////��ǰ�������ƥ��
//class Solution {
//public:
//	int numDistinct(string s, string t) {
//		int m = s.size(), n = t.size();
//		if (m < n)
//			return 0;
//		//dp[i][j]��ʾs��ǰi���ַ���ɵ��ַ�������������(t��ǰj���ַ���ɵ��ַ���)���ֵĸ���
//		vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
//		//��ʼ����
//		for (int i = 0; i < m + 1; i++) //���ַ���t���κ��ַ���s��������
//			dp[i][0] = 1;
//		for (int i = 1; i < n + 1; i++) //�ǿ��ַ���t���ǿ��ַ���s��������
//			dp[0][i] = 0;
//		for (int i = 1; i < m + 1; i++) {
//			for (int j = 1; j < n + 1; j++) {
//				if (s[i - 1] == t[j - 1]) //s�ĵ�i-1���ַ���t�ĵ�j-1���ַ�ƥ��
//					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; //��s�ĵ�i-1���ַ�ƥ�����
//				else
//					dp[i][j] = dp[i - 1][j]; //ֻ�ܲ���s�ĵ�i-1���ַ�ƥ��
//			}
//		}
//		return dp[m][n];
//	}
//};


////·������Ŀ
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		//dp[i][j]��ʾ��(0,0)����(i,j)λ�õ�·����Ŀ
//		vector<vector<int>> dp(m, vector<int>(n, 1)); //(0,x)��(x,0)λ�õķ�����������Ϊ1
//		for (int i = 1; i < m; i++) {
//			for (int j = 1; j < n; j++) {
//				dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; //(i,j)λ��ֻ�ܴ�(i-1,j)��(i,j-1)λ�õ���
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
//			ans = ans * x / y; //�����ѧ
//		}
//		return ans;
//	}
//};
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		//��������
//		vector<int> dp(n, 1);
//		for (int i = 1; i < m; i++) {
//			for (int j = 1; j < n; j++) {
//				dp[j] = dp[j - 1] + dp[j];
//			}
//		}
//		return dp[n - 1];
//	}
//};


//��С·��֮��
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		for (int i = 1; i < m; i++) { //(i,0)ֻ�ܴ�(i-1,0)����
			grid[i][0] += grid[i - 1][0];
		}
		for (int i = 1; i < n; i++) { //(0,i)ֻ�ܴ�(0,i-1)����
			grid[0][i] += grid[0][i - 1];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]); //(i,j)���Դ�(i-1,j)��(i,j-1)���ȡ��Сֵ
			}
		}
		return grid[m - 1][n - 1];
	}
};