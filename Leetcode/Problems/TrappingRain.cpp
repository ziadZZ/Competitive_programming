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
    int trap(vector<int>& h) {
        int n = h.size();
        int ans = 0;
        vector<int> l(n);
        vector<int> r(n);
        l[0]=h[0];
        r[n-1]=h[n-1];
        for (int i = 0; i<n-1 ; i++){
            l[i+1] = max(l[i], h[i+1]);
        }
        for (int j = n-2; j>=0 ; j--){
            r[j] = max(r[j+1], h[j]);
        }
        for (int i = 1; i<n-1 ; i++){
            ans += min(l[i],r[i])-h[i];
        }
        return ans;
    }
}