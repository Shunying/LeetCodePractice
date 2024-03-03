#include <vector>
#include <iostream>

using namespace std;

int Partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) high--;  // high elem keep on right, all elem visited > pivot
        swap(arr[low], arr[high]); // high elem should move to left, all elem visited < pivot
        while (low < high && arr[low] <= pivot) low++;  // low elem keep on left
        swap(arr[low], arr[high]);  // low elem move to right
    }
    return low;  // low meets high, pivot pos found
}

void quickSort(vector<int>& arr, int low, int high, int k) {
    if (low < high) {
        int pivot_pos = Partition(arr, low, high);
        if (pivot_pos < k) return quickSort(arr, pivot_pos+1, high, k); 
        if (pivot_pos >= k) return quickSort(arr, low, pivot_pos-1, k);
    }
}

vector<int> smallestK(vector<int>& arr, int k) {
    vector<int> res;
    if (k==0) return res;
    if (k >= arr.size()) return arr;
    quickSort(arr, 0, arr.size()-1, k);
    res.assign(arr.begin(), arr.begin()+k);
    return res;
}


int main() {
    vector<int> arr;
    arr = {1, 3, 5, 7, 2, 4, 6, 8};

    auto res = smallestK(arr, 4);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl; 
    }

    return 0;
}