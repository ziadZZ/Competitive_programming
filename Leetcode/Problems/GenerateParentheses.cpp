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

vector<vector<string>> generate_par(9);
class Solution {
public:

    void fill(){
        generate_par[0].push_back("");
        for (int n = 1; n<=8; n++){
            for (int m = 0; m<=n-1 ; m++){
                for (auto p : generate_par[m]){
                    for (auto q : generate_par[n-1-m]){
                        generate_par[n].push_back("("+p+")"+q);
                    }
                }
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        if(generate_par[n].empty()) fill();
        return generate_par[n];
        
    }
};