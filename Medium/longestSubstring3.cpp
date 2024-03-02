#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int ans = 0, left = 0, n = s.length();
    unordered_set<char> cset;
    
    for (int right=0; right < n; right++) {
        char c = s[right];
        // c already in window -> left++, until c out of window
        while (cset.count(c)) {
            cset.erase(s[left]);
            left++;
        }
        // c not in window, insert c into set
        cset.insert(c);
        ans = max(ans, right-left+1);
    }

    return ans;
}


int main() {
    //string s = "abcabcbb";
    string s = "bbbbb";
    int res = lengthOfLongestSubstring(s);
    cout << "Lenght longest: " << res << endl;
}