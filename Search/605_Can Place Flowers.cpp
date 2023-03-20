class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int max = 0;
        if(flowerbed.size() == 1){
            if(flowerbed[0] == 0 && n <= 1) return true;
            else if(flowerbed[0] == 1 && n == 0)    return true;
            else    return false;
        }
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 1){
                i+=1;
                if(i >= flowerbed.size())   break;
            }

            else{
                if(i == 0){
                    if(flowerbed[i+1] == 1) continue;
                    else{
                        flowerbed[i] = 1;
                        max++;
                    }
                }
                else if(i == flowerbed.size()-1){
                    if(flowerbed[i-1] == 1) continue;
                    else{
                        flowerbed[i] = 1;
                        max++;
                    }
                }
                else{
                    if(flowerbed[i-1] == 1 || flowerbed[i+1] == 1)  continue;
                    else{
                        flowerbed[i] = 1;
                        max++;
                    }
                }

            }
        }
        if(max >= n)    return true;
        else    return false;
    }
};

//很没意思的一题，写了一坨shit mountain
