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
    vector<int> parent(101);
    int k; cin >> k;
    cin.ignore();
    string line;
    int p; int f;
    
    while(getline(cin,line) && line != "-1" ){
        stringstream ss(line);
        ss >> p;
        while (ss >> f){
            parent[f] = p;
        }
        cout << endl;
    }
    
    int u = k;
    while(parent[u]){
        cout << u << " ";
        u = parent[u];
    }
    cout << u << endl;

    return 0;
}