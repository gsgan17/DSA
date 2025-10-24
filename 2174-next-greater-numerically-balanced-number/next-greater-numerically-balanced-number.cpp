class Solution {
private:
    bool isBeautiful(int n){
        vector<int> f(10, 0);
        while(n>0){
            f[n%10]++;
            n/=10;
        }

        bool soln = true;
        for(int i=0; i<10; i++){
            if(f[i]!=0 && f[i]!=i){
                soln = false;
            }
        }
        return soln;
    }
public:
    int nextBeautifulNumber(int n) {
        if(isBeautiful(n+1)){
            return n+1;
        } else{
            return nextBeautifulNumber(n+1);
        }
    }
};