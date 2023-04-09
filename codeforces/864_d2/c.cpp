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

int n,m;

int dist(pii x, pii y){
    return max(abs(x.first-y.first),abs(x.second-y.second));
}


int main(){
    int t; cin >> t;
    pii x;
    pii y;
    int d1,d2,d3;
    while(t--){
        cin >> n >> m;
        if (n<m){

        x = {0,0};
        cout << "? " << x.first+1<< " " << x.second+1 << endl;
        fflush(stdout);
        cin >> d1;

        x={min(d1,n-1), d1};
        cout << "? " << x.first+1<< " " << x.second+1 << endl;
        fflush(stdout);
        cin >> d2;

        x.first-=d2;
        cout << "? " << x.first+1<< " " << x.second+1 << endl;
        fflush(stdout);
        cin >> d3;

        if (d3==0) cout << "! "<< x.first+1<< " " << x.second+1 << endl;
        else cout << "! "<< x.first+d2+1<< " " << x.second-d2+1 << endl;
        }

        else{
            x = {0,0};
            cout << "? " << x.first+1<< " " << x.second+1 << endl;
            fflush(stdout);
            cin >> d1;

            x={d1,min(m-1,d1)};
            cout << "? " << x.first+1<< " " << x.second+1 << endl;
            fflush(stdout);
            cin >> d2;

            x.second-=d2;
            cout << "? " << x.first+1<< " " << x.second+1 << endl;
            fflush(stdout);
            cin >> d3;

            if (d3==0) cout << "! "<< x.first+1<< " " << x.second+1 << endl;
            else cout << "! "<< x.first-d2+1<< " " << x.second+d2+1 << endl;
        }
    }
    return 0;
}