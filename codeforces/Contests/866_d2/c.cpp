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


bool solve(int n){
    vi a(n);
    vi copy_a(n);
    for (int i = 0; i<n; i++){
        cin >> a[i];
        copy_a[i] = a[i];
    }
    sort(a.begin(), a.end());
    int mex = 0;
    for (int i =0; i<n ;i++){
        if (a[i]==mex) mex++; 
        if (a[i]>mex) break;
    }
    //cout << "mex = " << mex << endl;
    if (!binary_search(a.begin(),a.end(),mex+1)){
        unordered_map<int,int> ocr;
        for (int i =0; i<n ;i++){
            if (a[i] > mex){return true;}
            auto it = ocr.find(a[i]);
            if (it == ocr.end()) ocr[a[i]] =1;
            else{
                return true;
            }
        }
        return false;
    }
    else{
        int i = 0;
        int j = n-1;  
        for (int k = 0; k<n ; k++){
            if (copy_a[k]==mex+1) break;
            i++;
        }
        for (int k = n-1; k>=0 ; --k){
            //cout << " k " << k << endl;
            if (copy_a[k]==mex+1) break;
            j--;
        }
        // cout << "i = " << i << " j = "<< j << endl;
        unordered_map<int,bool> ocr;
        for (int k = 0; k<i ; k++){
            if (copy_a[k]<mex+1);
            ocr[copy_a[k]]= true;
        }
        for (int k = n-1; k>j ; k--){
            if (copy_a[k]<mex+1);
            ocr[copy_a[k]]= true;
        }
        for (int k = i; k<=j ; k++){
            if(copy_a[k]<mex+1 && (!ocr[copy_a[k]])){
                return false;
            }
        }
        return true;
    }

}
int main(){
    int t; cin >> t; int n;
    while (t--){
        cin >> n;
        cout << (solve(n) ? "YES" : "NO")<< endl;
    }
    return 0;
}