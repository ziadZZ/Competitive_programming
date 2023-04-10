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
#define ALPHABET_SIZE 26

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

void print_deb(set<pii>& s){
  std::cout << endl;
  std::cout << "--" << endl;
  for (auto x :s){
    std::cout << x.first << " " << x.second << endl;
  }
  std::cout << "--" << endl;
}

void print_s(set<int>& s){
  cout << "__" << endl;
  for(auto x : s){
    cout << x << " ";
  }
  cout << endl;
  cout << "__" << endl;

}

void print_q(vector<pii> s){
  std::cout << endl;
  std::cout << "//" << endl;
  for (auto x :s){
    std::cout << x.first << " " << x.second << endl;
  }
  std::cout << "//" << endl;
}

int main(){
  int n,r,c;
  cin >> n >> r >> c;
  vector<pii> q;
  int a,b,s;
  while(n--){
    cin >> a >> b >>s;
    a--;b--;
    q.push_back({min(a+s,r-1),max(a-s,0)});
  }
 
  sort(q.begin(),q.end());
  int ans = 0;

  set<int> free_row;
  for (int i = 0; i<r ; i++) free_row.insert(i);
  vi per_row(r,0);
  print_q(q);
  print_s(free_row);
  for(auto x : q){
    int start = x.second;
    int end = x.first;
    auto row_low = free_row.upper_bound(start);
    if (row_low != free_row.begin()) {
      --row_low; 
      if (*row_low < start) ++row_low;
    }
    if (row_low == free_row.end() || *row_low > end) continue;
    ans++;
    per_row[*row_low]++;
    if (per_row[*row_low] == c) free_row.erase(row_low);
    print_s(free_row);
  }
   std::cout << ans << endl;

  return 0;
}