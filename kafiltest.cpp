

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
    vector<string> mails;
    string mail;
    while(cin>> mail && mail !="#"){
        mail[0]=tolower(mail[0]);
        mails.pb(mail);
    }
    cout << mails.size() << endl;

    vector<string> missing;
    while(cin >> mail && mail != "#"){
        mail[0]=tolower(mail[0]);
        auto it = find(mails.begin(),mails.end(),mail);
        if (it == mails.end()) missing.pb(mail);
    }

    for (auto miss : missing) cout << miss << endl;
    cout << missing.size() << endl;
    /* string university;
    unordered_map<string,string> universities;
    int i = -1;

    while(getline(cin, university) && university != "#"){
        universities[mails[i]] = university;
        i++;
        cout << i << endl;
    } 
    int cnt = 0;
    vector<string> ans;
    while(cin >> mail && mail != "#"){
        mail[0]=tolower(mail[0]);
        auto it = universities.find(mail);
        if (it == universities.end()){
            ans.push_back("Exception");
            ++cnt;
            continue;
        }
        ans.push_back(it->second);
    }
    for (auto univ : ans ) cout << univ << endl;
    cout << cnt << endl;*/
}



