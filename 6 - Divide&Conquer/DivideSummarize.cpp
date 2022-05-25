#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
typedef long long ll;

using namespace std;


void getSums(const vector<ll> &a, set<ll> &sums, ll start, ll end){
    if(start >= end){return;}

    ll cs(0); for(ll p = start; p < end; p++){cs += a[p];}
    sums.insert(cs);

    if(a[start] == a[end - 1]){return;}

    ll mid = (a[start] + a[end - 1]) / 2;
    ll idx(start); while(a[idx] <= mid){++idx;}

    getSums(a, sums, start, idx);
    getSums(a, sums, idx, end);

    return;
}


int main(){
    int input;

    cin >> input;
    for(int i=0; i<input; ++i){
        ll n, q;
        cin >> n >> q;

        vector<ll> a(n);
        for(ll j =0; j<n; ++j){
            cin >> a[j];
        }

        sort(a.begin(),a.end());
        set<ll> s; 

        getSums(a, s, 0, n);

        while(q--){
            ll x; scanf("%lld", &x);
            puts(s.count(x) ? "Yes" : "No");
        }
    }
    return 0;
}