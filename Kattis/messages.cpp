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

string line;

//implementing the data structure of 


struct TrieNode {
  struct TrieNode* children[ALPHABET_SIZE];
  int is_end_of_word;
};


struct TrieNode* create_node() {
  struct TrieNode* node = (struct TrieNode*) malloc(sizeof(struct TrieNode));
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    node->children[i] = NULL;
  }
  node->is_end_of_word = 0;
  return node;
}

void insert(struct TrieNode* root, string key) {
  struct TrieNode* node = root;
  for (int i = 0; key[i] != '\0'; i++) {
    int index = key[i] - 'a';
    if (node->children[index] == NULL) {
      node->children[index] = create_node();
    }
    node = node->children[index];
  }
  node->is_end_of_word = 1;
}

int search(struct TrieNode* root, string line , int i, int j) {
  struct TrieNode* node = root;
  for (int k = i; k<=j ; k++) {
    int index = line[k] - 'a';
    if (node->children[index] == NULL) {
      return 0;
    }
    node = node->children[index];
  }
  return node != NULL && node->is_end_of_word;
}


void solve(TrieNode* t, string line, int n){
  vector<pii> q; // will contain the intervals
  for (int i=0; i<n ; i++){
    for(int j=i; j < min(i+10,n); j++ ){
      if (search(t,line,i,j)) q.push_back({j,i});
    }
  }
  sort(q.begin(),q.end());

  // algorithm of interval scheduling
  int ans = 0;
  int last_finish = -1;
  for (auto x : q){
    if (last_finish >= x.second) continue;
    ans++;
    last_finish = x.first;
  }
  cout << ans << endl;
}


int main(){
  struct TrieNode* t = create_node();
  while (cin >> line && line!="#"){
    insert(t,line);
  }
  string msg;
  int n = 0;
  while (cin >> line && line!="#"){
    msg += line;
    n += line.length();
    if (msg[n-1]!='|') continue;
    solve(t,msg,--n);
    msg.clear(); n=0;
  }
  return 0;
}