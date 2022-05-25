#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;


void populate_psum(vector<int> &A, unordered_set<long long> &psum) {
  long long sum = 0;
  int asize = A.size();
  for(int i = 0;i < asize;i++) {
    sum += A[i];
  }
  psum.insert(sum);

  int minm = *min_element(A.begin(), A.end());
  int maxm = *max_element(A.begin(), A.end());

  if(minm == maxm) return;

  int avg = (minm + maxm)/2;

  vector<int> lthan, gthan;
  for(int i = 0;i < asize;i++) {
    if(A[i] <= avg) lthan.push_back(A[i]);
    else gthan.push_back(A[i]);
  }

  populate_psum(lthan, psum);
  populate_psum(gthan, psum);
}


int main(){
    int input;

    cin >> input;
    for(int i=0; i<input; ++i){
        int n, q;
        cin >> n >> q;

        vector<int> A(n), Q(q);
        for(int j =0; j<n; ++j){
            cin >> A[i];
        }

        for(int k =0; k<q; ++k){
            cin >> Q[k];
        }

        unordered_set<long long> psum;
        populate_psum(A, psum);

        for(int i = 0;i < q;i++) {
            if(psum.count(Q[i]) == 1) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}