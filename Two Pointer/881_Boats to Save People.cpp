class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count = 0;
        int lo = 0;
        int hi = people.size() - 1;
        while(lo < hi){
            if(people[lo] + people[hi] <= limit){
                lo++;
                hi--;
                count++;
            }
            else{
                hi--;
                count++;
            }
        }
        return lo > hi? count:count+1;
    }
};
