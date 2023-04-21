#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define cl(x, y) memset(x, y, sizeof(x))
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9+7;
const int N = 1e5 + 5;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        int l,r;
        for (int i = 0; i<n ; ++i){
            if (i && a[i]==a[i-1]) continue;
            l = i+1; r = n-1;
            while (r>l){
                if (a[l]+a[r]+a[i]==0){
                    ans.push_back({a[i],a[l],a[r]});
                    ++l; --r;
                    while (r>l && a[l]==a[l-1] && a[r]==a[r+1]){
                        ++l; --r;
                    }
                }
                else if (a[l]+a[r]+a[i]>0){
                    --r;
                }
                else {
                    ++l;
                }
            }
        }
        return ans;
    }
};