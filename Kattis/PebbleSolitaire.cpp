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

    int n; cin >> n;
    const int N = 23;
    unordered_map<bitset<N>,vector<bitset<N>>> g;
    for (ll i = 0; i < (1<<N) ; ++i){
        bitset<N> bits(i);
        for (int j = 0; j<N-1; j++){
            if (bits[j] && bits[j+1]){
                if (j>0 && !bits[j-1]){
                    bitset<N> copy = bits;
                    bits[j-1] = 1;
                    bits[j+1] = 0;
                    bits[j] = 0;
                    g[copy].pb(bits);
                    bits = copy;
                }
                if (j<N-2 && !bits[j+2]){
                    bitset<N> copy = bits;
                    bits[j+2] = 1;
                    bits[j+1] = 0;
                    bits[j] = 0;
                    g[copy].pb(bits);
                    bits = copy;
                }
            }
        }
    }
    while (n--){
        string line;
        cin >> line;
        bitset<N> bits(0);
        for (int j = 0; j<N ; ++j){
            if (line[j]=='o'){
                bits[j] = 1;
            }
        }
        queue<bitset<N>> q;
        q.push(bits);
        while (!q.empty()){
            bits = q.front();
            q.pop();
            for (auto x : g[bits]) q.push(x);
        }
        cout << bits.count() << endl;
    }   

    return 0;
}