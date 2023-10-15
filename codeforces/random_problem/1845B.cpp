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
typedef long double ld;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9+7;
const int N = 1e5 + 5;

void subtract(pii& p, pii& q){
    p.first -= q.first;
    p.second -= q.second;
}

int main(){
    int t; cin >> t;
    while (t--){
        pii a,b,c;
        cin >> a.first >> a.second ;
        cin >> b.first >> b.second ;
        cin >> c.first >> c.second ;
        subtract(b,a);
        subtract(c,a);
        int x,y,i,j;
        x = b.first;
        y = b.second;
        i = c.first;
        j = c.second;

        if (i*x<0 && j*y<0){
            cout << 0 << endl;
        }
        else if (i*x>=0 && j*y >=0){
            cout << min(abs(x), abs(i)) + min(abs(y), abs(j))+1 << endl;
        }
        else if (i*x>=0 && j*y <0){
            cout << min(abs(x), abs(i))+1<< endl;
        }
        else{
            cout << min(abs(y), abs(j))+1 << endl;
        }
    }
    return 0;
}