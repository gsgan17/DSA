// class Solution {
// public:
//     long long c(long long n){
//         return n*(n-1)/2;
//     }
//     int countTrapezoids(vector<vector<int>>& points) {
//         int mod = 1e9 + 7;
//         int n = points.size();
//         map<int, int> levelPoints;

//         for(int i=0; i<n; i++){
//             levelPoints[points[i][1]]++;
//         }

//         long long soln = 0;
//         long long edges = 0;

//         for(auto it: levelPoints){
//             long long numEdge = c(it.second);
//             soln += numEdge*edges;
//             edges+=numEdge;
//             soln%=mod;
//         }
//         soln%=mod;

//         return soln;

//     }
// };

// Optimized
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> pointNum;
        const int mod = 1e9 + 7;
        long long ans = 0, sum = 0;
        for (auto& point : points) {
            pointNum[point[1]]++;
        }
        for (auto& [_, pNum] : pointNum) {
            long long edge = (long long)pNum * (pNum - 1) / 2;
            ans += edge * sum;
            sum += edge;
        }
        return ans % mod;
    }
};