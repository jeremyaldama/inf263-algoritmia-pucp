//Easy: https://leetcode.com/problems/sum-of-all-subset-xor-totals/

class Solution {
public:

    int GenerateSubsets(vector<int>& nums, int pos, int n, int current_xor){
        if (pos==n){
            return current_xor;
        }
        int xor_total=0;

        for (int i=0; i<2; i++){
            int last_xor;
            if (i==0){
                last_xor = current_xor;
                current_xor ^= nums[pos];
            }
            xor_total += GenerateSubsets(nums, pos+1, n, current_xor);
            if (i==0){
                current_xor = last_xor;
            }
        }
        return xor_total;
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return GenerateSubsets(nums, 0, n, 0);
    }
};
