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

vector<vector<string>> ans;
vector<string> cur ;
string s;
bool valid;

class Solution {
public:

    vector<vector<string>> solveNQueens(int n) {
        vector<int> rows(n);
        ans.clear(); cur.clear();
        // initialize the string s
        s = string(n,'.');
        solve(rows, 0, n);
        return ans;
    }


    void solve(vector<int> &rows, int i, int& n){
        if (i==n) {ans.push_back(cur); return;}

        for (int j = 0 ; j<n ; j++){
            valid = true;
            for (int k = 0; k<i ; k++){
                if (rows[k]==j || rows[k]+k == j+i || rows[k]-k == j-i) {valid = false; break;}
            }

            if (!valid) continue;

            rows[i]=j;
            s[rows[i]]='Q';
            for (int k =0; k<n ; k++){
                if (k!=rows[i]) s[k] = '.';
            }
            
            cur.push_back(s);
            solve(rows,i+1,n);
            cur.pop_back();
        }

    }
};