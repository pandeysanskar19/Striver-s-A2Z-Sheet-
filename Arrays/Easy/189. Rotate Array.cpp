class Solution {
public:

     vector<int> reverse(vector<int>& arr,int low,int high){
         while(low<high){
             swap(arr[low],arr[high]);
             low++;
             high--;
         }
         return arr;

     }
    void rotate(vector<int>& nums, int k) {
// APPROACH 2: TIME COMPLEXITY: O(N),space complexity: o(1)
         int n=nums.size();
         int low=0;
         int high=n-1;
         if(k==0) return ;
         k%=n;
         reverse(nums,low,n-k-1);
         reverse(nums,n-k,high);
        reverse(nums,low,high);
// APPROACH 1: TIME COMPLEXITY :O(N) SPACE COMPLEXITY:O(N) AUXILARY SPACE.
   /* int n=nums.size();
    vector<int> temp(n);
    k=k%n;
    for(int i=0;i<n;i++){
        temp[(i+k)%n]=nums[i];
    }
    for(int i=0;i<n;i++){
        nums[i]=temp[i];
    }
    }*/
};
