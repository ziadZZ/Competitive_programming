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


bool reachingPoints(int sx, int sy, int tx, int ty) {
    if (tx == sx && ty == sy) return true;
    if (tx == 0 || ty == 0) return false;
    if (tx > ty){
        if (ty == sy){
            return (tx > sx && (tx - sx)%ty ==0 );
        }
        return reachingPoints(sx, sy, tx % ty, ty);
    }
    else if (tx < ty){
        if (tx == sx){
            return (ty > sy && (ty - sy)% tx == 0);
        } 
        return reachingPoints(sx, sy, tx, ty % tx);
    }
    return false;
}

int main(){
    return 0;
}