#include <vector>
#include <iostream>

using namespace std;

int triangleNumber(vector<int>& nums) {
    int res = 0, n = nums.size();

    if (n < 3) return 0;

    // sort
    sort(nums.begin(), nums.end());

    for (int i = 2; i < n; i++) {
        int left = 0, right = i-1;
        while (left < right) {
            if (nums[left] + nums[right] > nums[i]) {
                res += right - left;
                right--;
            }
            else {
                left++;
            }
        }
    }

    return res;
}


int main() {
    vector<int> nums;
    nums = {4, 2, 3, 4};

    int res = triangleNumber(nums);

    cout << "Number of triangles: " << res << endl;

    return 0;
}