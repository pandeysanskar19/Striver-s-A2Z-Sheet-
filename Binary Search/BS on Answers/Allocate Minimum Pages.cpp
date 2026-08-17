class Solution {
    
  private:
    long long studentAllocated(vector<int>& arr,long long pg){
        int stud=1;long long studpages =0;
        for(int i=0;i<arr.size();i++){
            if(studpages + arr[i]<=pg){
                studpages+=arr[i];
            }
            else{
                stud++;
                studpages=arr[i];
            }
        }
        return stud;
    }
    
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        
        if(k>n) return -1;
        long long cntstud=0;
        long long high=accumulate(arr.begin(),arr.end(),0LL);
        long long low=*max_element(arr.begin(),arr.end());
// APPROACH 1: TIME COMPLEXITY: O(N^2),SPACE COMPLEXITY:0(1).
      
        // for(int pg = low;pg<high;pg++){
        //     cntstud=studentAllocated(arr,pg);
        //     if(cntstud == k){
        //         return pg;
        //     }
        // }

// APPROACH 2: TIME COMPLEXITY:O(N*LOGN) , SPACE COMPLEXITY:O(1).
        while(low<=high){
            long long mid=low+(high-low)/2;
            cntstud=studentAllocated(arr,mid);
            if(cntstud>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return (int)low;
    }
};
