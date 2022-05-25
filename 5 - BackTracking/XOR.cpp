#include <iostream>
#include <vector>

using namespace std;

int recursive_xor(vector<int> nums){

    return 0;
}

int subsetXORSum(vector<int>& nums) {
    int res = 0;
    for (auto i = 1; i < (1 << nums.size()); ++i) {
        int total = 0;
        for (long unsigned int j = 0; j < nums.size(); ++j)
            if (i & (1 << j))
                total ^= nums[j];
        res += total;
    }
    return res;
}


int main(){

    int n;
    cin >> n;
    vector<int> nums;
    int num;
    for(int i = 0; i<n; ++i){
        cin >> num;
        nums.push_back(num);
    }

    //cout << recursive_xor(nums);
    int result = subsetXORSum(nums);

    cout << result << endl;
    return 0 ;
}