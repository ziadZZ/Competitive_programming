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

class DetectSquares {
public:

    vector<complex<double>> points; // Stores the points 
    unordered_map<double, vector<pair<int, int>>> norm; // norm[r] : returns the id of pairs of points for which the norm is equal to r**2;
    int N;
    DetectSquares() : N(0), points(vector<complex<double>>()){
    }
    
    void add(vector<int> point) {
        complex<double> x((double) point[0], (double) point[1]);
        // Update norm
        for (int i = 0; i<N; i++){
            complex<double> y = points[i];
            norm[abs(y-x)].push_back({i, N});
        }
        // Push the point into the vector points
        points.push_back(x);
        // Increment the number of points
        N++;
    }
    
    int count(vector<int> point) {
        complex<double> x((double) point[0], (double) point[1]);
        complex<double> xx(8,9);
        
        complex<double> i(0,1);
        int ans = 0;
        for (auto y : points){
            double r = abs(y-x);
            if (r==0.0) continue;
            for (auto pair_of_point : norm[r]){
                int idx1 = pair_of_point.first;
                int idx2 = pair_of_point.second;
                // verify if the two segments intersects in the middle 
                if (points[idx1]+points[idx2] != y + x){
                    continue;
                }
                // verifiy if the two segments are perpendicular
                if (points[idx1]-points[idx2] == (y-x)*i || points[idx1]-points[idx2] == (y-x)*(-i) ){
                    ans ++;

                    if (x == xx) {
                    cout << x << " "  << y << endl;
                    cout << points[idx1] << " " << points[idx2] << endl;
                    cout << endl;
                    }
                }
            }
        }
        
        return ans;
    }

};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */