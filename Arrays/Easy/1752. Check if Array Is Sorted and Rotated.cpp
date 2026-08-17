class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
         int cnt = 0; 
  //TIME COMPLEXITY: O(N),SPACE COMPLEXITY:O(1).
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]) cnt++;
        }
        return cnt<=1;
    }
};
