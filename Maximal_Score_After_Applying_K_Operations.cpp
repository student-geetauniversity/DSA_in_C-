#include<bits/stdc++.h>
using namespace std;

long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
    }

    long long score = 0;
    while(k--) {
        int num = pq.top();
        pq.pop();
        score += num;
        if(num % 3 == 0) 
            pq.push(num / 3);
        else 
            pq.push((num / 3) + 1);
    }
    
    return score;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    cout << "Enter the number of operations (k): ";
    cin >> k;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long result = maxKelements(nums, k);

    cout << "The maximum score is: " << result << endl;

    return 0;
}
