class Solution {
public:
    int smallestIndex(vector<int>& nums) {
 
        for(int i=0;i<nums.size() && i<28;i++){
            int x=0;
            while(nums[i]!=0){
                x=x+nums[i]%10;
                nums[i]=nums[i]/10;

            }
            if(x==i){
                return i;
            }
        }
        return -1;
    }
};