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
    vector<int> c(n);
    for (int i = 0; i<n ; i++){
        cin >> c[i];
    }
    vector<int> minimum(c[n-1]+c[n-2]+1);
    for (int i = 0 ; i<=c[n-1]+c[n-2]; i++) minimum[i] = i;

    for (int i = 1; i<n ; i++){
        for (int p = c[n-1]+c[n-2]; p>=0 ; p--){
            /*
            for (int j = 1; j<= (int)(p/c[i]) ; j++){
                minimum[p] = min(minimum[p], minimum[p- j*c[i]]+j);
            }
            */
            int j = (int) (p/c[i]);
            minimum[p] = min(minimum[p], minimum[p- j*c[i]]+j);
        }
    }

    // for (int i = 0 ; i<=c[n-1]+c[n-2]; i++) cout << i << " " << minimum[i] << endl;

    bool valid = true;

    vector<int> gready(c[n-1]+c[n-2]+1); 
    gready[0] = 0;

    for (int p = 1  ; p<= c[n-1]+c[n-2] ; p++){
        int count = 0;
        int min_count = minimum[p];
        for (int i = n-1; i>=0 ; i--){
           if (p >= c[i]){
            count =  1 + gready[p-c[i]];
            break;
           }
        }
        gready[p] =  count;
        if (count > min_count) {valid = false; break;}
    }

    cout << ((valid) ? "canonical" : "non-canonical") << endl;
    return 0;
}