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
const int N = 1e5 ;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& a) {
        int n = a.size();
        vector<ll> ans(n,0);
        vector<int>  max_pref(n);
        max_pref[0]=a[0]
        for (int i=1; i<n ;i++){
            max_pref[i] = max(max_pref[i-1],a[i]);
        }
        ans[0] = a[0]+a[0];
        for (int i =1; i<n ;i++){
            ans[i]=ans[i-1]+a[i]+max_pref[i];
        }
        return ans;
    }
};