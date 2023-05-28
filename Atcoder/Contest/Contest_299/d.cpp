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

int cur;
int rep;
int p;
int mid;

vector<int> mem;

bool search(int l, int r ,int direction){
    if (r==l) return false;
    cout << l << " " << r << endl;
    mid = l +(r-l)/2;
    if (mem[mid]==-1){
        cout << "? " << mid+1<< endl;
        fflush(stdout); 
        cin >> mem[mid];
    }
    rep = mem[mid];   
    if (r-l <= 2){
        if (rep==cur) return false;
        else {
            if (direction) p = l-1;
            else p = l;
            return true;
        }
    }
    else if (rep == cur){
        if (!search(mid+1,r,1)) return search(l,mid,0);
        else return true;
    }
    else{
        cur = rep;
        if (direction) return search(l,mid,0);
        else return search(mid,l,1);
    }
    return false;
}




int main(){
    int n; cin >> n;
    mem.resize(n,-1);
    cout << "? " << n/2+1 << endl;
    fflush(stdout);
    cin >> cur;
    mem[n/2]=cur;
    if (!search(0,n/2,0)) search(n/2+1,n,1);
    cout << "! " << p+1 <<endl;
    return 0;
}


