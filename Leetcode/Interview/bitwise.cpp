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

// The link https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

const int N = 24;
int largestCombination(vector<int>& candidates) {
    int n = candidates.size();
    vector<int> bit (N,0);
    for (int i = 0; i<n ; i++){
        for (int j = 0; j<N; j++){
            if (candidates[i] & (1<<j)){
                bit[j]++;
            }
        }
    }
    int ans = 1;
    for (int i = 0; i<N; ++i){
        ans = max(ans , bit[i]);
    }
    return ans;
}

int main(){
    return 0;
}

