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

int is_winning_pos[100001];
int n;

int dp(vector<int>& a, int k){
    if (is_winning_pos[k] !=-1) return is_winning_pos[k];
    if (k<a[0]){is_winning_pos[k]=0; return 0;}

    is_winning_pos[k] = 0;
    for (int i = 0; i<n ;i++){
        if (k>=a[i] && !dp(a,k-a[i])){
            is_winning_pos[k] = 1;
            break;
        }
    }
    return is_winning_pos[k];
}

int main (){

    cl(is_winning_pos,-1);
    int k; cin >> n >> k;
    cout << is_winning_pos[k] << endl;
    vector<int> a(n);
    for (int i=0; i<n ; i++){
        cin >> a[i];
    }

    cout << (dp(a,k) ? "First" : "Second") << endl;
    
    return 0;
}