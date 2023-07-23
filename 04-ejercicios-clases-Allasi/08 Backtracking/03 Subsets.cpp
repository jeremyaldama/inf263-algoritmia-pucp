#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Subconjunto que voy formando conforme recorro el grafo de estados
    vector<int> subset;
    // Vector con todos los subconjuntos que he formado
    vector<vector<int>> all_subsets;
    
    void Backtrack(const vector<int>& nums, int pos, int n) {
        // Tras terminar de recorrer el arreglo, guardamos el subconjunto formado
        if (pos == n) {
            all_subsets.push_back(subset);
            return;
        }
        // Decidimos entre colocar o no colocar el elemento actual
        for (int i = 0; i < 2; i++) {
            if (i == 1) {
                subset.push_back(nums[pos]);
            }
            Backtrack(nums, pos + 1, n);
            if (i == 1) {
                subset.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int)nums.size();
        Backtrack(nums, 0, n);
        return all_subsets;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> sub = sol.subsets(nums);
    
    for (int i=0; i<sub.size(); i++){
        for (int j=0; j<sub[i].size(); j++){
            cout<<sub[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}