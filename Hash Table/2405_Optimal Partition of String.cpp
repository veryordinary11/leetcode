class Solution {
public:
    int partitionString(string s) {
        int count = 0;
        vector<int> v(26,0);

        for(int i = 0; i < s.size(); i++){
            if(v[s[i] - 'a'] == 1){
                count++;
                std::fill(v.begin(),v.end(),0);
                v[s[i] - 'a'] = 1;
            }
            else    v[s[i] - 'a'] = 1;
        }
        return count+1;
    }
};
