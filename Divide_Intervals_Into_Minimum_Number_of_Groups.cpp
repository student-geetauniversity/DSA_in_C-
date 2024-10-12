#include<bits/stdc++.h>
using namespace std;

int minGroups(vector<vector<int>>& intervals) {
    vector<pair<int, int>> events;
    for(int i = 0; i < intervals.size(); i++) {
        events.push_back({intervals[i][0], 1});   
        events.push_back({intervals[i][1] + 1, -1}); 
    }

    sort(events.begin(), events.end());

    int maxGroups = 1;
    int count = 0;
    for(auto event : events) {
        count += event.second;  
        maxGroups = max(maxGroups, count);  
    }

    return maxGroups;
}

int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals (start end): " << endl;
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    int result = minGroups(intervals);
    cout << "Minimum number of groups required: " << result << endl;

    return 0;
}
