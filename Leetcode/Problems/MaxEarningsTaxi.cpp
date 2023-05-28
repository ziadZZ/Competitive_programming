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


const int MAX = 1e5+1;
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& r) {
        vector<vector<vector<int>>> ride_bystart(MAX);
        for (auto& x : r){
            x[0]--;
            x[1]--;
            ride_bystart[x[0]].push_back(x);
        }
        vector<long long> m(MAX,0);
        for (int i = MAX-2; i>=0; i--){
            for (auto& x : ride_bystart[i]){
                m[i]=max(m[i], m[x[1]]+x[1]-i+x[2]);
            }
            m[i]=max(m[i],m[i+1]);
        }
        return m[0];
    }
};