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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int n,m;
    cin >> n >> m;
    vvi matrix(n,vi(m));
    string digits;
    for (int i = 0; i<n ; i++){
        cin >> digits;
        for (int j = 0; j<m ; j++){
            matrix[i][j] = digits[j] - '0';
        }
    }


    vvi d(n,vi(m,-1));
    d[0][0] = 0;
    queue<pii> q;
    q.push({0,0});
    pii u;
    int i;
    int j;
    int k;
    while (!q.empty()){
        u = q.front();
        q.pop();
        i = u.first;
        j = u.second;
        //cout << i << " " << j << endl;
        k = matrix[i][j];
        if (i >= k && d[i-k][j] == -1){
            d[i-k][j] = d[i][j] + 1;
            q.push({i-k , j});
        }
        if (j >= k && d[i][j-k] == -1){
            d[i][j-k] = d[i][j] + 1;
            q.push({i, j-k});
        }
        if (i+k< n && d[i+k][j] == -1){
            d[i+k][j] = d[i][j] + 1;
            q.push({i+k , j});
        }
        if (j+k< m && d[i][j+k] == -1){
            d[i][j+k] = d[i][j] + 1;
            q.push({i , j+k});
        }
    }
    cout << d[n-1][m-1] << endl;
}