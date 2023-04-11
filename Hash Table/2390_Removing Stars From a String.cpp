class Solution {
public:
    string removeStars(string s) {
        string result = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                if(result.size() > 0){
                    result.pop_back();
                }
            }else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
