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

void solve(int& n, int q){
    vector<multiset<int>> box(n);
    unordered_map<int,set<int>> card;
    string line;
    int i,j;
    int k;
    while(q--){
        cin >> k >> i;
        // cout << k << " " << i << endl;
        if (k==1){
            cin >> j;
            //cout << j << endl;
            box[j].insert(i);
            card[i].insert(j);
        }
        else if (k==2){
            for (auto l : box[i]){
                cout << l << " ";
            }
            cout << endl;
        }
        else {
            for (auto l : card[i]){
                cout << l << " ";
            }
            cout << endl;
        }
    }

}


int main(){
    int n; cin >> n;
    int q; cin >> q;
    solve(n,q);
    return 0;
}