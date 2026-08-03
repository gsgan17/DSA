class Solution {
public:
    bool equalFrequency(string word) {
        int n= word.size();
        map<char, int> f;

        for(char ch: word){
            f[ch]++;
        }

        vector<int> fv;
        for(auto it: f){
            fv.push_back(it.second);
        }

        sort(fv.begin(), fv.end());

        if(fv.size()==1){
            return true;
        }

        bool b1, b2;

        // for(auto it: fv){
        //     cout << it << " ";
        // }
        // cout << endl;

        b1 = ((accumulate(fv.begin(), fv.end(), 0) - (fv.size()*fv[0]))==1);

        b2= true;
        int temp = fv[1];
        for(int i=2; i<fv.size(); i++){
            if(fv[i]==temp){
                continue;
            } else{
                b2= false;
                break;
            }
        }
        if(fv[0]!=1){
            b2= false;
        }

        return b1 | b2;
    }
};