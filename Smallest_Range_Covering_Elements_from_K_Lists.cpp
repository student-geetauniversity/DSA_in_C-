#include<bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<pair<int, int>> element;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            element.push_back({nums[i][j], i});
        }
    }
    sort(element.begin(), element.end());

    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> mp;
    int left = 0;
    int right = 1e9;
    int l = 0;
    
    for (int r = 0; r < element.size(); r++) {
        mp[element[r].second]++;
        while (mp.size() == n) {
            if ((element[r].first - element[l].first) < (right - left)) {
                right = element[r].first;
                left = element[l].first;
            }
            mp[element[l].second]--;
            if (mp[element[l].second] == 0)
                mp.erase(element[l].second);
            l++;
        }
    }
    
    ans = {left, right};
    return ans;
}

int main() {
    int k;
    cout << "Enter the number of lists: ";
    cin >> k;
    
    vector<vector<int>> nums(k);
    
    for (int i = 0; i < k; i++) {
        int size;
        cout << "Enter the number of elements in list " << i + 1 << ": ";
        cin >> size;
        
        nums[i].resize(size);
        cout << "Enter the elements for list " << i + 1 << ": ";
        for (int j = 0; j < size; j++) {
            cin >> nums[i][j];
        }
    }
    
    vector<int> result = smallestRange(nums);
    cout << "Smallest range: [" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}
