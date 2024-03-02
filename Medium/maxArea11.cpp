#include <vector>
#include <iostream>

using namespace std;

int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size();
    int max_area = 0;
    while (l < r) {
        int area = (r-l) * min(height[l], height[r]);
        max_area = max(area, max_area);
        if (height[l] < height[r]){
            l++;
        }
        else {
            r--;
        }
    }
    return max_area;
}


int main() {
    vector<int> heights;
    heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int res = maxArea(heights);

    cout << "Max area: " << res << endl;

}
