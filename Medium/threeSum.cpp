#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> mp;
    vector<int> res;
    for (int i=0; i<nums.size(); i++) {
        mp[nums[i]] = i;
    }
    for (int i=0; i<nums.size(); i++) {
        if (mp.count(target-nums[i])){
            if (mp[target-nums[i]]==i) {
                continue;
            }
            res.push_back(i);
            res.push_back(mp[target-nums[i]]);
            break;
        }
    }
    return res;
}


vector<int> twoSumSorted(vector<int>& nums, int target) {
    vector<int> res;
    int l, r;
    l = 0;
    r = nums.size()-1;
    while (l < r) {
        if (nums[l] + nums[r] < target){
            l+=1;
        }
        else if (nums[l] + nums[r] > target) {
            r-=1;
        } else if (nums[l] + nums[r] == target) {
            res.push_back(l);
            res.push_back(r);
            break;
        }
        
    }
    return res;
}


vector<vector<int>> threeSum(vector<int>& nums, int target) {
    vector<vector<int>> res;

    if (nums.size() < 3) {return res;}

    if (nums.size() == 3) {
        int s = nums[0] + nums[1] + nums[2];
        if (s == target) {
            res.push_back(nums);
            return res;    
        }
        else {
            return res;
        }
    }

    // sort
    sort(nums.begin(), nums.end());

    // loop
    int n = nums.size();
    for (int i = 0; i < n-2; i++) {
        int x = nums[i];

        if (i > 0 && x == nums[i-1]) {
            continue;  // x as the 1st elem already checked
        } 

        cout << "x: " << x << endl;

        // early stop
        if (x+nums[n-2]+nums[n-1] < target) {
            continue;
        }
        if (x+nums[i+1]+nums[i+2] > target) {
            break;
        }

        // two sum sorted
        int l = i+1;
        //cout << "num[l]: " << nums[l] << endl;
        int r = n-1;
        while (l < r) {
            int s = x + nums[l] + nums[r];
            if (s < target) {
                l++;
            }
            else if (s > target) {
                r--;
            }
            else if (s == target) {
                vector<int> tmp;
                tmp.push_back(x);
                tmp.push_back(nums[l]);
                tmp.push_back(nums[r]);
                res.push_back(tmp);
                l++;
                while (l<r && nums[l] == nums[l-1]) {
                    l++; // skip repeated num from left
                }
                r--;
                
                while (l<r && nums[r] == nums[r+1]) {
                    r--;  // skip repeated num from right
                }
            }
        }
    }

    return res;
}


int main() {
    vector<int> vals;
    //vals = {2, 7, 11, 15};
    //int target = 9;

    //vals = {-1, 0, 1, 2, -1, -4};
    //vals = {0, 1, 1};
    vals = {0, 0, 0, 0};
    int target = 0;

    //auto res = twoSumSorted(vals, target);
    auto res = threeSum(vals, target);

    cout << "List index: " << endl;

    // for two sum
    /*
    if (res.size() < 2) {
        cout << "[]" << endl;
        return 0;
    }

    cout << "[" <<res[0] << "," << res[1] << "]" << endl;
    */

    // for three sum
    if (res.size() < 1) {
        cout << "[]" << endl;
        return 0;
    }
    for (int i = 0; i < res.size(); i++) {
        vector<int> tmp = res[i];
        cout << i << ":" << endl;
        cout << "[" << tmp[0] << "," << tmp[1] << "," << tmp[2] << "]" << endl;
    }
    
    return 0;

}