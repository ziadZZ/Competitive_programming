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

// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//

using namespace std;

int r = 0;
int A = 10*10*10*10;

stack<int> to_stack(ListNode<int> * a){
    stack<int> s;
    ListNode<int>* cur = a;
    while (cur){
        s.push(cur->value);
        cur = cur->next;
    }
}

ListNode<int> * solution(ListNode<int> * a, ListNode<int> * b) {
   stack<int> s1 = to_stack(a);
   stack<int> s2 = to_stack(b);
   queue<int> q;
   while (!(s1.empty() && s2.empty())){
       int x = 0;
       int y = 0;
       if (!s1.empty()) {x = s1.top(); s1.pop();}
       if (!s2.empty()) {y = s2.top(); s2.pop();}
       q.push((x+y+r)%A);
       r = (x+y+r)/A;
   }
   if (r!=0){
       q.push(r);
   }
   ListNode<int>* c ;
   ListNode<int>* cur = c;
   while (!q.empty()){
       cur = new ListNode(q.front());
       q.pop();
       cur = cur -> next;
   }
   return c;
}
int main(){

    int n = 5;
    int s = 0;
    
    for (int i = 1; i<=n ; i++){
        for (int j = i+1; j<=n; j++){
            s += (j-i);
        }
    }
    cout << s << endl; 
    return 0;

}