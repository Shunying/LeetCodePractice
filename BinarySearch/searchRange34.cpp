#include <vector>
#include <iostream>

using namespace std;


// incorrect
int binarySerach(vector<int>& arr, int target, int start, int end) {
    int l = start, r = end;
    
    while (l < r) {
        int mid = l + (r-l) / 2;
        if (arr[mid] > target) r = mid;
        if (arr[mid] < target) l = mid+1;
        if (arr[mid] == target) return mid;  // 不知道是该元素第几次出现
    }
    return 0;
}


int lower_bound(vector<int>& arr, int target, int start) {
    int l = start, r = arr.size()-1;
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (arr[mid] >= target){
            r = mid-1;  // lower bound on leftside
        } else{
            l = mid+1;  // lower bound on rightside
        }
    }
    return l;
}


// 34
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    res = {-1, -1};

    if (nums.size() < 1) return res;

    int start = lower_bound(nums, target, 0);
    if (start == nums.size()-1 || nums[start+1] != target) return res;
    int end = lower_bound(nums, target+1, start)-1;

    res[0] = start;
    res[1] = end;

    return res;
}

// 2529
int maximumCount(vector<int>& nums) {
    int zero_start = lower_bound(nums, 0, 0);
    // 所有数都小于0 -> 返回数组长度
    if (zero_start == nums.size()-1 && nums[zero_start] < 0) return nums.size();
    // 所有数都大于0 -> 返回数组长度
    if (zero_start == 0 && nums[zero_start] > 0) return nums.size();
    int pos_start = lower_bound(nums, 1, zero_start);
    int neg_cnt = zero_start;
    int pos_cnt = nums.size()-pos_start;
    return neg_cnt >= pos_cnt ? neg_cnt : pos_cnt;
}


int main() {
    vector<int> nums;
    //nums = {5, 7, 7, 8, 8, 10};
    //int target = 8;

    nums = {5,20,66,1314};

    int cnt = maximumCount(nums);

    cout << cnt << endl;

}

/*
int main() {
    vector<int> nums;
    //nums = {5, 7, 7, 8, 8, 10};
    //int target = 8;

    nums = {2, 2};
    int target = 2;

    vector<int> res = searchRange(nums, target);

    cout << "[" << res[0] << "," << res[1] << "]" << endl;
}
*/