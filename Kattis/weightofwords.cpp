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

string d[41][1001];

char int_to_letter(int num){
    char c  = 'a' + (num - 1);
    return c;
}

void update(int l, int w){
    for (int j = 1; j<=min(26,w) ; j++){
        if (d[l-1][w-j] != "#") {d[l][w]=d[l-1][w-j]+int_to_letter(j); return;}
    }
    d[l][w] = "#";
}

void fill_in(){
    for (int w=1; w<=1000 ; w++){
        d[0][w] = "#";
    }
    for (int l=1; l<=40; l++){
        for (int w=0; w<=1000 ; w++){
            update(l,w);
        }
    }
}

int main(){
    fill_in();
    int l ,w;
    cin >> l >> w;
    cout << (d[l][w]!= "#" ? d[l][w] : "impossible") << endl;
    return 0;
}