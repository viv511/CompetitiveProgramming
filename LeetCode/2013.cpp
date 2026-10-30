#include <vector>
#include <map>
using namespace std;

class DetectSquares {
public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        pts[{x,y}]++;
    }
    
    int count(vector<int> point) {
        // 0 <= x, y <= 1000
        int x = point[0], y = point[1];

        int ans = 0;

        for (auto& s : pts) {
            int px = s.first.first;
            int py = s.first.second;

            if (px == x || py == y) continue;
            if (abs(px - x) != abs(py - y)) continue;

            ans += (pts[{px,py}] * pts[{px,y}] * pts[{x,py}]);
        }
        
        return ans;
    }

private:
    map<pair<int, int>, int> pts;
};