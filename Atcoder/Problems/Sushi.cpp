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

int n;


double dp[301][301][301];


double expected_value(int x1, int x2, int x3){
    if (x1==-1 || x2 == -1 || x3 == -1) return 0.0;
    if (dp[x1][x2][x3] !=-1) return dp[x1][x2][x3];

    dp[x1][x2][x3] = expected_value(x1-1,x2,x3)*x1;
    dp[x1][x2][x3] += expected_value(x1+1,x2-1,x3)*x2;
    dp[x1][x2][x3] += expected_value(x1,x2+1,x3-1)*x3;
    dp[x1][x2][x3] /= n;
    dp[x1][x2][x3] += 1.0;
    dp[x1][x2][x3] *=  (double) n/(x1+x2+x3);

    return dp[x1][x2][x3];
}

int main (){
    
    //initialize the dp matrix with -1;
    for (int i=0; i<= 300 ; i++){
        for (int j=0 ; j<= 300 ; j++){
            for (int k=0 ; k<= 300 ; k++){
                dp[i][j][k] = -1.0;
            }
        }
    }
    dp[0][0][0] = 0.0; // when all a_i=0;

    // reading inputs
    cin >> n;
    int a;
    int Numbers_of_1, Numbers_of_2, Numbers_of_3;
    Numbers_of_1 = 0; Numbers_of_2 = 0; Numbers_of_3 = 0;
    for (int i = 0 ; i<n ; i++){
        cin >> a;
        if (a==1) Numbers_of_1++;
        if (a==2) Numbers_of_2++;
        if (a==3) Numbers_of_3++;
    }
    cout <<fixed << setprecision(10)<<
    expected_value(Numbers_of_1, Numbers_of_2, Numbers_of_3) << endl;

    return 0;
}