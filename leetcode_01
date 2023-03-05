class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> record;
        for(int i = 0; i < nums.size(); i++){
            int num = target - nums[i];
            if(record.find(num) != record.end()){
                return{record[num],i};
            }
            else    record[nums[i]] = i;
        }
        return {-1,-1};
    }
};

//普遍的做法有双循环法、双指针法和哈希表法，我使用了哈希表法
//unordered_map<int,string> umap; 第一个值int代表key，第二个string是value，umap是map name
//main函数中的find函数输入参数是key，返回value 判断是否找到的句法 umap.find(key) == umap.end()
//hashmap循环句法 unordered_map<key,value>::iterator p; for(p = umap.begin(); p != umap.end(); p++)
