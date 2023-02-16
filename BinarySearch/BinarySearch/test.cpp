#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] > target) {
				right = mid - 1;
			}
			else if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				return mid;
			}
		}
		return right + 1;
	}
};

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		int ans = nums.size(); //防止数组中所有数都小于target
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] >= target) { //找到第一个大于等于target的位置
				right = mid - 1;
				ans = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return ans;
	}
};
//山峰数组的顶部
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		int left = 0, right = arr.size() - 1;
		int ans = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] < arr[mid + 1]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
				ans = mid;
			}
		}
		return ans;
	}
};
//在排序数组中找只出现一次的数字
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right) / 2;
			if (nums[mid] == nums[mid ^ 1])
				left = mid + 1;
			else
				right = mid;
		}
		return nums[right];
	}
};
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right) / 2;
			mid -= mid & 1;
			if (nums[mid] == nums[mid + 1])
				left = mid + 2;
			else
				right = mid;
		}
		return nums[left];
	}
};