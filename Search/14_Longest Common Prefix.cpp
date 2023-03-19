class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        bool flag = true;
        for(int i = 0; i < strs.size(); i++){
            for(auto ch : strs){
                if(ch[i] != strs[0][i]){
                    flag = false;
                    break;
                }
            }
            if(flag)    result.push_back(strs[0][i]);
            else    break;
        }
        return result;
    }
};
