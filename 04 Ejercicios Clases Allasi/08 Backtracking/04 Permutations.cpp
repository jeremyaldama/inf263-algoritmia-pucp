#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void Backtrack(vector<int>& nums, int pos, int n, 
                       vector<vector<int>>& permutations,
                       vector<int>& permutation, vector<bool>& used){
            if (pos==n){
                permutations.push_back(permutation);
                return;
            }

            for (int i=0; i<n; i++){
                if (used[i]) continue;

                permutation[i] = nums[pos];
                used[i] = true;
 
                Backtrack(nums, pos+1, n, permutations, permutation, used);

                used[i] = false;

            }
        }

        vector<vector<int>> permute(vector<int>& nums) {
            int n = (int)nums.size();
            vector<int> permutation(n);
            vector<bool> used(n, false);
            vector<vector<int>> permutations;

            Backtrack(nums, 0, n, permutations, permutation, used);

            return permutations;
        }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> sub = sol.permute(nums);
    
    for (int i=0; i<sub.size(); i++){
        for (int j=0; j<sub[i].size(); j++){
            cout<<sub[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
