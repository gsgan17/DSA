class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();

        int l= 0;
        int r= n-1;
        int soln = -1e9;

        while(l<r){
            int distance = r-l;
            int h = min(height[l], height[r]);
            soln = max(soln, distance*h);
            if(height[l]<height[r]){
                l++;
            } else{
                r--;
            }
        }

        return soln;
    }
};