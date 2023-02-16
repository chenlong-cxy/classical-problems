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
		int ans = nums.size(); //��ֹ��������������С��target
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] >= target) { //�ҵ���һ�����ڵ���target��λ��
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
//ɽ������Ķ���
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
//��������������ֻ����һ�ε�����
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