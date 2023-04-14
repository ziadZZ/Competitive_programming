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
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        for (int i = n-1; i>=0 ; i--){
            for (int j = m-1; j>=0 ; j--){
                if (i+1==n && j+1 == m) dp[i][j] = grid[i][j];
                else if (j+1 == m) dp[i][j] = grid[i][j]+dp[i+1][j];
                else if (i+1 == n) dp[i][j] = grid[i][j]+dp[i][j+1];
                else dp[i][j] = grid[i][j]+min(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};