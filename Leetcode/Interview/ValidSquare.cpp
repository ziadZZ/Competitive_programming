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

bool perpendicular(complex<double> a, complex<double> b){
        complex<double> i(0,1);
        return (a == b*i || b == a * i);
    }
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    complex<double> i(0,1);
    complex<double> x1 = (double)p1[0]+i*(double)p1[1];
    complex<double> x2 = (double)p2[0]+i*(double)p2[1]; 
    complex<double> x3 = (double)p3[0]+i*(double)p3[1];
    complex<double> x4 = (double)p4[0]+i*(double)p4[1];

    
    if ((abs(x1-x2) == abs(x3-x4)) && (perpendicular(x1-x2, x3-x4)) && (x1+x2 == x3+x4) && (x1!=x2)){
        return true;
    }
    if ((abs(x1-x3) == abs(x2-x4)) && (perpendicular(x1-x3, x2-x4))  && (x3+x1 == x2+x4) && (x1!=x3)){
        return true;
    }
    if ((abs(x1-x4) == abs(x2-x3)) && (perpendicular(x1-x4, x2-x3)) && (x1+x4 == x3+x2) && (x1!=x4)){
        return true;
    }
    return false;
}


int main(){
    vector<int> p1 = {-658,-2922};
    vector<int> p2 = {-965,-4209};
    vector<int> p3 = {-2252,-3902};
    vector<int> p4 = {-1945,-2615};
    cout << validSquare(p1, p2, p3, p4)<< endl;
    cout << arg(complex<int> (0,1)) << endl;
    return 0;
}
