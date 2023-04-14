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

bool rows[9][9];
bool cols[9][9];
bool squares[9][9];


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // initialization 
        memset(rows,false,sizeof(rows));
        memset(cols,false,sizeof(cols));
        memset(squares,false,sizeof(squares));

        // read inputs
        for (int i = 0; i<9 ; i++){
            for (int j = 0; j<9 ; j++){
                if (board[i][j]=='.') continue;
                rows[i][board[i][j]-'0'-1] = true;
                cols[j][board[i][j]-'0'-1] = true;
                squares[(i/3)*3+(j/3)][board[i][j]-'0'-1] = true;
            }
        }
        solve(board,0,0);
    }

    bool solve(vector<vector<char>>& board, int i, int j){

        if (i==9 && j==8) return true; // when you reach the end
        if (i==9) {return solve(board,0,j+1);} 

        if (board[i][j] != '.') return solve(board,i+1,j); // when the cell is already filled

        for (int k = 1; k<=9 ; k++){
            if (rows[i][k-1] || cols[j][k-1] 
            || squares[(i/3)*3+(j/3)][k-1]) continue; //if it's not a valid choice to put k in the cell i,j
            rows[i][k-1] = true;
            cols[j][k-1] = true;
            squares[(i/3)*3+(j/3)][k-1] = true;
            board[i][j] = '0' + k;
            if (solve(board,i+1,j)) return true; // if the choice is valid, we stop.
            board[i][j] = '.';
            rows[i][k-1] = false;
            cols[j][k-1] = false;
            squares[(i/3)*3+(j/3)][k-1] = false;
        }

        return false;

    }
};