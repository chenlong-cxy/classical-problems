////nums的所有子集
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		dfs(nums, 0);
//		return ans;
//	}
//	void dfs(vector<int>& nums, int n) {
//		if (n == nums.size()) {
//			ans.push_back(tmp);
//			return;
//		}
//		tmp.push_back(nums[n]);
//		dfs(nums, n + 1);
//		tmp.pop_back(); //回溯
//		dfs(nums, n + 1);
//	}
//private:
//	vector<vector<int>> ans;
//	vector<int> tmp;
//};
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<vector<int>> ans;
//		int n = nums.size();
//		for (int i = 0; i < (1 << n); i++) {
//			vector<int> tmp;
//			for (int j = 0; j < n; j++) {
//				if (i&(1 << j))
//					tmp.push_back(nums[j]);
//			}
//			ans.push_back(tmp);
//		}
//		return ans;
//	}
//};


////含有k个元素的组合
//class Solution {
//public:
//	vector<vector<int>> combine(int n, int k) {
//		dfs(n, 1, k);
//		return ans;
//	}
//	void dfs(int n, int cur, int k) {
//		if (tmp.size() == k) { //递归结束条件
//			ans.push_back(tmp);
//			return;
//		}
//		if (tmp.size() + (n - cur + 1) < k) //说明把剩下的数都放入tmp也不够k个（剪枝）
//			return;
//		tmp.push_back(cur);
//		dfs(n, cur + 1, k);
//		tmp.pop_back(); //回溯
//		dfs(n, cur + 1, k);
//	}
//private:
//	vector<vector<int>> ans;
//	vector<int> tmp;
//};
//class Solution {
//public:
//	vector<vector<int>> combine(int n, int k) {
//		vector<vector<int>> ans;
//		vector<int> arr;
//		for (int i = 1; i <= k; i++) {
//			arr.push_back(i);
//		}
//		arr.push_back(n + 1); //最后一个n+1用于后面结束循环
//		int j = 0;
//		while (j < k) {
//			ans.emplace_back(arr.begin(), arr.begin() + k);
//			j = 0;
//			while (j < k&&arr[j] + 1 == arr[j + 1]) {
//				arr[j] = j + 1; //将1依次移到低位
//				j++;
//			}
//			arr[j]++; //例如将0111变为1011
//		}
//		return ans;
//	}
//};


////允许重复选择元素的组合
//class Solution {
//public:
//	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		dfs(candidates, 0, target);
//		return ans;
//	}
//	void dfs(vector<int>& candidates, int index, int target) {
//		if (target == 0) { //已经组成目标数
//			ans.push_back(tmp);
//			return;
//		}
//		if (index == candidates.size()) //数组中的元素已被用完
//			return;
//		if (candidates[index] <= target) { //考虑当前元素
//			tmp.push_back(candidates[index]);
//			dfs(candidates, index, target - candidates[index]); //可以重复使用，因此传入的下标还是index
//			tmp.pop_back(); //回溯
//		}
//		dfs(candidates, index + 1, target); //不考虑当前元素
//	}
//private:
//	vector<vector<int>> ans;
//	vector<int> tmp;
//};


////含有重复元素集合的组合
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//		//统计candidates中每个元素出现的次数
//		sort(candidates.begin(), candidates.end());
//		for (int num : candidates) {
//			if (freq.size() != 0 && num == freq.back().first)
//				freq.back().second++;
//			else
//				freq.emplace_back(num, 1);
//		}
//		dfs(0, target);
//		return ans;
//	}
//	void dfs(int index, int target) {
//		if (target == 0) { //目标数组成完毕
//			ans.push_back(tmp);
//			return;
//		}
//		if (index == freq.size() || freq[index].first > target) //数已经用完，或当前数已经大于target（后续的更大）
//			return;
//		int times = min(target / freq[index].first, freq[index].second); //当前数最多可以用几次
//		for (int i = 1; i <= times; i++) {
//			tmp.push_back(freq[index].first);
//			dfs(index + 1, target - i*(freq[index].first)); //考虑i个当前数
//		}
//		for (int i = 1; i <= times; i++) {
//			tmp.pop_back(); //回溯
//		}
//		dfs(index + 1, target); //不考虑当前数
//	}
//private:
//	vector<pair<int, int>> freq;
//	vector<vector<int>> ans;
//	vector<int> tmp;
//};
//int main()
//{
//	vector<int> v = { 10, 1, 2, 7, 6, 1, 5 };
//	vector<vector<int>> ans = Solution().combinationSum2(v, 8);
//	for (auto arr : ans) {
//		for (auto e : arr)
//			cout << e << " ";
//		cout << endl;
//	}
//	return 0;
//}


////没有重复元素集合的全排列
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//	vector<vector<int>> permute(vector<int>& nums) {
//		dfs(nums, 0);
//		return ans;
//	}
//	void dfs(vector<int> nums, int cur) {
//		if (cur == nums.size()) { //位置已经全部确定
//			ans.push_back(nums);
//			return;
//		}
//		for (int i = cur; i < nums.size(); i++) {
//			swap(nums[cur], nums[i]); //将第i个数填到cur位置
//			dfs(nums, cur + 1);
//			swap(nums[cur], nums[i]); //回溯
//		}
//	}
//private:
//	vector<vector<int>> ans;
//};
//int main()
//{
//	vector<int> v = { 2, 3, 1, 8};
//	//sort(v.begin(), v.end());
//	vector<vector<int>> ans = Solution().permute(v); //输出不是字典序
//	for (auto arr : ans) {
//		for (auto e : arr)
//			cout << e << " ";
//		cout << endl;
//	}
//	return 0;
//}


////含有重复元素集合的全排列
//class Solution {
//public:
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//		dfs(nums, 0);
//		return ans;
//	}
//	void dfs(vector<int> nums, int cur) {
//		if (cur == nums.size()) { //全部位置已确定
//			ans.push_back(nums);
//			return;
//		}
//		set<int> used; //记录cur位置使用过的数
//		for (int i = cur; i < nums.size(); i++) {
//			if (used.count(nums[i])) //使用过该数则不再使用
//				continue;
//			swap(nums[cur], nums[i]); //将第i个数放到cur位置
//			dfs(nums, cur + 1);
//			swap(nums[cur], nums[i]); //回溯
//			used.insert(nums[i]); //记录该数被使用过
//		}
//	}
//private:
//	vector<vector<int>> ans;
//};


////生成匹配的括号
//class Solution {
//public:
//	vector<string> generateParenthesis(int n) {
//		string tmp;
//		generate_all(tmp, 2 * n);
//		return ans;
//	}
//	void generate_all(string& tmp, int n) {
//		if (tmp.size() == n) {
//			if (valid(tmp)) //判断生成的字符串是否有效
//				ans.push_back(tmp);
//			return;
//		}
//		tmp += '(';
//		generate_all(tmp, n);
//		tmp.pop_back();
//		tmp += ')';
//		generate_all(tmp, n);
//		tmp.pop_back();
//	}
//	bool valid(const string& s) {
//		int balance = 0;
//		for (const char& ch : s) {
//			if (ch == '(')
//				balance++;
//			else
//				balance--;
//			if (balance < 0)
//				return false;
//		}
//		return balance == 0;
//	}
//private:
//	vector<string> ans;
//};
//class Solution {
//public:
//	vector<string> generateParenthesis(int n) {
//		string tmp;
//		dfs(tmp, 0, 0, n);
//		return ans;
//	}
//	void dfs(string& tmp, int leftCount, int rightCount, int n) {
//		if (tmp.size() == 2 * n) { //括号组合生成完毕
//			ans.push_back(tmp);
//			return;
//		}
//		if (leftCount < n) { //左括号的数量小于n，可以尝试放左括号
//			tmp += '(';
//			dfs(tmp, leftCount + 1, rightCount, n);
//			tmp.pop_back(); //回溯
//		}
//		if (rightCount < leftCount) { //右括号的数量小于左括号的数量，可以尝试放右括号
//			tmp += ')';
//			dfs(tmp, leftCount, rightCount + 1, n);
//			tmp.pop_back(); //回溯
//		}
//	}
//private:
//	vector<string> ans;
//};


////分割回文子字符串
//class Solution {
//public:
//	vector<vector<string>> partition(string s) {
//		//记录各个子串是否是回文子串（动态规划）
//		int n = s.size();
//		dp.resize(n, vector<bool>(n, true));
//		for (int i = n - 1; i >= 0; i--) {
//			for (int j = i + 1; j < n; j++) {
//				dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
//			}
//		}
//		dfs(s, 0);
//		return ans;
//	}
//	void dfs(const string& s, int start) {
//		if (start == s.size()) { //字符串分割完毕
//			ans.push_back(tmp);
//			return;
//		}
//		for (int end = start; end < s.size(); end++) {
//			if (dp[start][end]) { //该字符串是回文串
//				string sub = s.substr(start, end - start + 1);
//				tmp.push_back(sub); //尝试切割出该子字符串
//				dfs(s, end + 1);
//				tmp.pop_back(); //回溯
//			}
//		}
//	}
//private:
//	vector<vector<string>> ans;
//	vector<vector<bool>> dp;
//	vector<string> tmp;
//};


//复原IP
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		dfs(s, 0, 0);
		return ans;
	}
	void dfs(const string& s, int start, int cutCount) {
		if (cutCount == 4 && start == s.size()) { //成功切割完毕
			//将切割出来的4个字符串以.为分隔符拼接起来
			string str = tmp[0];
			for (int i = 1; i < 4; i++) {
				str += ".";
				str += tmp[i];
			}
			ans.push_back(str);
			return;
		}
		if (cutCount == 4 || start == s.size()) //错误切割
			return;
		for (int end = start; end < min((int)s.size(), start + 3); end++) {
			string sub = s.substr(start, end - start + 1);
			if (valid(sub)) { //该子字符串是否可以作为IP地址中的整数
				tmp.push_back(sub);
				dfs(s, end + 1, cutCount + 1);
				tmp.pop_back(); //回溯
			}
		}
	}
	bool valid(const string& s) {
		if (s.size() == 1)
			return true;
		int num = atoi(s.c_str());
		if (s[0] != '0'&&num >= 0 && num <= 255)
			return true;
		return false;
	}
private:
	vector<string> ans;
	vector<string> tmp;
};