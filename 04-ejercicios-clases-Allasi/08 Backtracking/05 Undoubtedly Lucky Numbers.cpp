//no me sale con backtracking :c
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int IsLuckyNumber(int n){
            set<int> no_rep;
            while(n>0){
                no_rep.insert(n%10);
                n/=10;
            }
            return no_rep.size()<=2;
        }

        int CantidadNoLuckyNumbers(int n){
            int cantidad = 0;
            for (int i=0; i<=n; i++){
                if (!IsLuckyNumber(i)){
                    cantidad++;
                }
            }
            return cantidad;
        }
};

int main(){
    Solution sol;
    int n = 123;
    cout<<"Hay "<<sol.CantidadNoLuckyNumbers(n)<<" que no son lucky numbers"
        <<endl;
    return 0;
}

