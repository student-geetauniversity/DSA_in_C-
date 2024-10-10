#include<bits/stdc++.h>
using namespace std;

int maxWidthRamp(vector<int>& nums) {
    const int n = nums.size();
    vector<unsigned> numsIdx(n);
    
    for (int i = 0; i < n; i++)
        numsIdx[i] = ((unsigned)nums[i] << 16) + i;

    sort(numsIdx.begin(), numsIdx.end());
    int min_i = n, width = 0;
    
    for (auto x : numsIdx) {
        int i = x & ((1 << 16) - 1);
        width = max(width, i - min_i);
        min_i = min(min_i, i);
    }
    
    return width;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = maxWidthRamp(nums);
    cout << "The maximum width ramp is: " << result << endl;
    
    return 0;
}
