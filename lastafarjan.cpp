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

int n, l;
int cars[200];
int ferry[4];
uint8_t d[61][61][61][61];

void solve(){
    for(int i=n-1; i>=0; i--){
        
        for(int l1=l; l1>=0 ; l1--){
            for(int l2=l; l2>=0 ; l2--){
                for(int l3=l; l3>=0 ; l3--){
                    for(int l4=l; l4>=0 ; l4--){
                        ferry[0]=l1; ferry[1]=l2; ferry[2]=l3;ferry[3]=l4;
                        uint8_t m = 0;
                        bool impossible = true;
                        for (int j = 0; j<4; j++){
                            if (ferry[j]!=l && ferry[j] >= cars[i] + 1){
                                impossible = false;
                                ferry[j] -= cars[i]+1;
                                m = max(d[ferry[0]][ferry[1]][ferry[2]][ferry[3]],m);
                                ferry[j] += cars[i]+1;
                            }
                            else if (ferry[j]==l && ferry[j] >= cars[i]){
                                impossible = false;
                                ferry[j] -= cars[i];
                                m = max(d[ferry[0]][ferry[1]][ferry[2]][ferry[3]],m);
                                ferry[j] += cars[i];
                            }
                        }
                        if (impossible) {d[ferry[0]][ferry[1]][ferry[2]][ferry[3]]=0;}
                        else {d[ferry[0]][ferry[1]][ferry[2]][ferry[3]]=m+1;}

                    }
                }
            }
        }
    }

    std::cout << static_cast<int>(d[l][l][l][l]) << endl;
}



/*int dp(int i){
    if (i==n) return 0;
    int m = 0;
    bool impossible = true;
    for (int j = 0; j<4; j++){
        if (ferry[j]!=l && ferry[j] >= cars[i] + 1){
            impossible = false;
            ferry[j] -= cars[i]+1;
            m = max(dp(i+1),m);
            ferry[j] += cars[i]+1;
        }
        else if (ferry[j]==l && ferry[j] >= cars[i]){
            impossible = false;
            ferry[j] -= cars[i];
            m = max(dp(i+1),m);
            ferry[j] += cars[i];
        }
    }
    if (impossible) return 0;
    return m+1;
}*/


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);

    cin >> n;
    cin >> l;
    
    for(int l1=l; l1>=0 ; l1--){
        for(int l2=l; l2>=0 ; l2--){
            for(int l3=l; l3>=0 ; l3--){
                for(int l4=l; l4>=0 ; l4--){
                    d[l1][l2][l3][l4] = 0;
                }
            }
        }
    }
    
    
    for (int i=0; i<n ;i++) cin >> cars[i];

    solve();

    return 0;
}