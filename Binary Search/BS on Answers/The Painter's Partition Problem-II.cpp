class Solution {
  public:
    int time_taken(vector<int>& arr,int maxitime){
        int timee=0;int painter=1;
        for(int i=0;i<arr.size();i++){
            if(timee+arr[i]<=maxitime){
                timee += arr[i];
            }
            else{
                timee = arr[i];
                painter++;
            }
        }
        return painter;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int low =*max_element(arr.begin(),arr.end());
        int high= accumulate(arr.begin(),arr.end(),0);
//APROACH 1: TIME COMPLEXITY: O(N^2),SPACE COMPLEXITY:O(1).
        // for(int i=low;i<high;i++){
        //     int painter = time_taken(arr,i);
        //     if(painter==k) return i;
        // }

// APPROACH 2: TIME COMPLEXITY: O(N * LOGN),SPACE COMPLEXITY:O(1).
        while(low<=high){
            int mid=low+(high-low)/2;
            int painter = time_taken(arr,mid);
            if(painter <= k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};
