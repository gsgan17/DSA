class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int continuous = 0;
        int collisions = 0;
        
        string dir = directions;

        for(int i=0; i<n; i++){
            if(dir[i]=='L'){
                continue;
            } else if(dir[i]=='S'){
                if(i!=n-1){
                    if(dir[i+1]=='L'){
                        collisions += 1;
                        dir[i+1]='S';
                        // continuous = 0;
                    }
                }
            } else{
                continuous++;
                if(i!=n-1){
                    if(dir[i+1]=='L'){
                        dir[i]='S';
                        dir[i+1]='S';
                        collisions += continuous+1;
                        continuous = 0;
                    } else if(dir[i+1]=='S'){
                        dir[i]='S';
                        dir[i+1]='S';
                        collisions+= continuous;
                        continuous = 0;
                    } 
                }
            }
        }

        return collisions;
    }
};