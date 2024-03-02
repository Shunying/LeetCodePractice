#include <vector>
#include <iostream>

using namespace std;

int minSubArrayLenNaive(int target, vector<int>& nums) {
    // init min length
    int minlen = nums.size() + 1;
    
    for (int i = 0; i <= nums.size()-1; i++) {
        int cnt = 1;
        int cumsum = nums[i];

        if (cumsum >= target) return 1;

        for (int j = i+1; j <= nums.size()-1; j++) {
            
            cumsum += nums[j];
            cnt += 1;
            // cout << "i: " << i << ", j: " << j << ", cnt: " << cnt << endl;
            if (cumsum >= target) {
                minlen = min(cnt, minlen);
                // cout << "minlen: " << minlen << endl;
                break;
            }
            
        } 
    }

    if (minlen > nums.size()) return 0;

    return minlen;
}


int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0, cumsum = 0, cnt = n+1;

    for (int right = 0; right < n; right++) {
        cumsum += nums[right];
        while (cumsum >= target) {
            cnt = min(cnt, right-left+1);
            cumsum -= nums[left];
            left++;
        }
    }

    return cnt > n ? 0 : cnt;
}


// 713 
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int prod = 1, cnt = 0, left = 0, n = nums.size();
    
    if (k <= 1) return 0;

    for (int right=0; right < n; right++) {
        prod *= nums[right];

        while (prod >= k) {
            prod /= nums[left];
            left++;
        }
        
        cnt += (right - left + 1);
    }

    return cnt;
}


int main() {
    vector<int> nums;
    //nums = {2, 3, 1, 2, 4, 3};
    //int target = 7;

    //nums = {1, 4, 4};
    //int target = 1;

    // nums = {1, 1, 1, 1, 1, 1, 1, 1};
    // int target = 11;

    //nums = {1, 1, 1, 1, 7};
    //int target = 7;

    //int res = minSubArrayLen(target, nums);
    
    //cout << "Min subarray len: " << res << endl;

    //nums = {10, 5, 2, 6};
    //int k = 100;

    nums = {1, 2, 3};
    int k = 0;

    int res = numSubarrayProductLessThanK(nums, k);
    cout << "Number subarray: " << res << endl;
}