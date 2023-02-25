////nums�������Ӽ�
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
//		tmp.pop_back(); //����
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


////����k��Ԫ�ص����
//class Solution {
//public:
//	vector<vector<int>> combine(int n, int k) {
//		dfs(n, 1, k);
//		return ans;
//	}
//	void dfs(int n, int cur, int k) {
//		if (tmp.size() == k) { //�ݹ��������
//			ans.push_back(tmp);
//			return;
//		}
//		if (tmp.size() + (n - cur + 1) < k) //˵����ʣ�µ���������tmpҲ����k������֦��
//			return;
//		tmp.push_back(cur);
//		dfs(n, cur + 1, k);
//		tmp.pop_back(); //����
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
//		arr.push_back(n + 1); //���һ��n+1���ں������ѭ��
//		int j = 0;
//		while (j < k) {
//			ans.emplace_back(arr.begin(), arr.begin() + k);
//			j = 0;
//			while (j < k&&arr[j] + 1 == arr[j + 1]) {
//				arr[j] = j + 1; //��1�����Ƶ���λ
//				j++;
//			}
//			arr[j]++; //���罫0111��Ϊ1011
//		}
//		return ans;
//	}
//};


////�����ظ�ѡ��Ԫ�ص����
//class Solution {
//public:
//	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		dfs(candidates, 0, target);
//		return ans;
//	}
//	void dfs(vector<int>& candidates, int index, int target) {
//		if (target == 0) { //�Ѿ����Ŀ����
//			ans.push_back(tmp);
//			return;
//		}
//		if (index == candidates.size()) //�����е�Ԫ���ѱ�����
//			return;
//		if (candidates[index] <= target) { //���ǵ�ǰԪ��
//			tmp.push_back(candidates[index]);
//			dfs(candidates, index, target - candidates[index]); //�����ظ�ʹ�ã���˴�����±껹��index
//			tmp.pop_back(); //����
//		}
//		dfs(candidates, index + 1, target); //�����ǵ�ǰԪ��
//	}
//private:
//	vector<vector<int>> ans;
//	vector<int> tmp;
//};


////�����ظ�Ԫ�ؼ��ϵ����
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//		//ͳ��candidates��ÿ��Ԫ�س��ֵĴ���
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
//		if (target == 0) { //Ŀ����������
//			ans.push_back(tmp);
//			return;
//		}
//		if (index == freq.size() || freq[index].first > target) //���Ѿ����꣬��ǰ���Ѿ�����target�������ĸ���
//			return;
//		int times = min(target / freq[index].first, freq[index].second); //��ǰ���������ü���
//		for (int i = 1; i <= times; i++) {
//			tmp.push_back(freq[index].first);
//			dfs(index + 1, target - i*(freq[index].first)); //����i����ǰ��
//		}
//		for (int i = 1; i <= times; i++) {
//			tmp.pop_back(); //����
//		}
//		dfs(index + 1, target); //�����ǵ�ǰ��
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


////û���ظ�Ԫ�ؼ��ϵ�ȫ����
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
//		if (cur == nums.size()) { //λ���Ѿ�ȫ��ȷ��
//			ans.push_back(nums);
//			return;
//		}
//		for (int i = cur; i < nums.size(); i++) {
//			swap(nums[cur], nums[i]); //����i�����curλ��
//			dfs(nums, cur + 1);
//			swap(nums[cur], nums[i]); //����
//		}
//	}
//private:
//	vector<vector<int>> ans;
//};
//int main()
//{
//	vector<int> v = { 2, 3, 1, 8};
//	//sort(v.begin(), v.end());
//	vector<vector<int>> ans = Solution().permute(v); //��������ֵ���
//	for (auto arr : ans) {
//		for (auto e : arr)
//			cout << e << " ";
//		cout << endl;
//	}
//	return 0;
//}


////�����ظ�Ԫ�ؼ��ϵ�ȫ����
//class Solution {
//public:
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//		dfs(nums, 0);
//		return ans;
//	}
//	void dfs(vector<int> nums, int cur) {
//		if (cur == nums.size()) { //ȫ��λ����ȷ��
//			ans.push_back(nums);
//			return;
//		}
//		set<int> used; //��¼curλ��ʹ�ù�����
//		for (int i = cur; i < nums.size(); i++) {
//			if (used.count(nums[i])) //ʹ�ù���������ʹ��
//				continue;
//			swap(nums[cur], nums[i]); //����i�����ŵ�curλ��
//			dfs(nums, cur + 1);
//			swap(nums[cur], nums[i]); //����
//			used.insert(nums[i]); //��¼������ʹ�ù�
//		}
//	}
//private:
//	vector<vector<int>> ans;
//};


////����ƥ�������
//class Solution {
//public:
//	vector<string> generateParenthesis(int n) {
//		string tmp;
//		generate_all(tmp, 2 * n);
//		return ans;
//	}
//	void generate_all(string& tmp, int n) {
//		if (tmp.size() == n) {
//			if (valid(tmp)) //�ж����ɵ��ַ����Ƿ���Ч
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
//		if (tmp.size() == 2 * n) { //��������������
//			ans.push_back(tmp);
//			return;
//		}
//		if (leftCount < n) { //�����ŵ�����С��n�����Գ��Է�������
//			tmp += '(';
//			dfs(tmp, leftCount + 1, rightCount, n);
//			tmp.pop_back(); //����
//		}
//		if (rightCount < leftCount) { //�����ŵ�����С�������ŵ����������Գ��Է�������
//			tmp += ')';
//			dfs(tmp, leftCount, rightCount + 1, n);
//			tmp.pop_back(); //����
//		}
//	}
//private:
//	vector<string> ans;
//};


////�ָ�������ַ���
//class Solution {
//public:
//	vector<vector<string>> partition(string s) {
//		//��¼�����Ӵ��Ƿ��ǻ����Ӵ�����̬�滮��
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
//		if (start == s.size()) { //�ַ����ָ����
//			ans.push_back(tmp);
//			return;
//		}
//		for (int end = start; end < s.size(); end++) {
//			if (dp[start][end]) { //���ַ����ǻ��Ĵ�
//				string sub = s.substr(start, end - start + 1);
//				tmp.push_back(sub); //�����и�������ַ���
//				dfs(s, end + 1);
//				tmp.pop_back(); //����
//			}
//		}
//	}
//private:
//	vector<vector<string>> ans;
//	vector<vector<bool>> dp;
//	vector<string> tmp;
//};


//��ԭIP
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		dfs(s, 0, 0);
		return ans;
	}
	void dfs(const string& s, int start, int cutCount) {
		if (cutCount == 4 && start == s.size()) { //�ɹ��и����
			//���и������4���ַ�����.Ϊ�ָ���ƴ������
			string str = tmp[0];
			for (int i = 1; i < 4; i++) {
				str += ".";
				str += tmp[i];
			}
			ans.push_back(str);
			return;
		}
		if (cutCount == 4 || start == s.size()) //�����и�
			return;
		for (int end = start; end < min((int)s.size(), start + 3); end++) {
			string sub = s.substr(start, end - start + 1);
			if (valid(sub)) { //�����ַ����Ƿ������ΪIP��ַ�е�����
				tmp.push_back(sub);
				dfs(s, end + 1, cutCount + 1);
				tmp.pop_back(); //����
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