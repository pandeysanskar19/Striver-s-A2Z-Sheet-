class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
//APPROACH 1: TIME COMPLEXITY: O(N),SPACE COMPLEXITY:O(1).
        // auto it = unique(nums.begin(),nums.end());
        // return it-nums.begin();
//APPROACH 2: TIME COMPLEXITY: O(N),SPACE COMPLEXITY:O(1).
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!= nums[j]){
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;
    }
};
