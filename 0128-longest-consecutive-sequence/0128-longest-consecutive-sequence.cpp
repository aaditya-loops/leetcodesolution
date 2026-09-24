class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        int count=0;

        for(int i=0;i<n;i++){
            if(mp[nums[i]]>0){
                continue;
            }
            else{
                mp[nums[i]]=1;
            }
            if((mp[nums[i]-1]>0) && (mp[nums[i]+1]>0)){
                mp[nums[i]]=mp[nums[i]-1]+mp[nums[i]+1]+1;
                mp[nums[i]-mp[nums[i]-1]]=mp[nums[i]];
                mp[nums[i]+mp[nums[i]+1]]=mp[nums[i]];
                count=max(count,mp[nums[i]]);
            }
            else if(mp[nums[i]-1]>0){
                   mp[nums[i]]=mp[nums[i]-1]+1;
                   mp[nums[i]-mp[nums[i]-1]]=mp[nums[i]];
                   count=max(count,mp[nums[i]]);
            }
            else if(mp[nums[i]+1]>0){
                  mp[nums[i]]=mp[nums[i]+1]+1; 
                  mp[nums[i]+mp[nums[i]+1]]=mp[nums[i]];
                  count=max(count,mp[nums[i]]);
            }
            else{
                count=max(count,mp[nums[i]]);
            }
        }
        return count;
    }
};