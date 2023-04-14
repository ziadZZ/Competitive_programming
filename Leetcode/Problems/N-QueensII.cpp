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
    int ans;
    int totalNQueens(int n) {
        vector<int> rows(n);
        ans = 0;
        solve(rows, 0, n);
        return ans;
    }
    bool valid;
    void solve(vector<int> &rows, int i, int& n){
        if (i==n) ans++;
        for (int j = 0 ; j<n ; j++){
            valid = true;
            for (int k = 0; k<i ; k++){
                if (rows[k]==j || rows[k]+k == j+i || rows[k]-k == j-i) 
                {valid = false; break;}
            }
            if (!valid) continue;
            rows[i]=j;
            solve(rows,i+1,n);
            string s;
        }
    }
};