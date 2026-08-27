class Solution1 {
  public:
// TIME COMPLEXITY: O(rows * cols). SPACE COMPLEXITY : 0(1).
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int rows = arr.size();
        int cols=arr[0].size();
        int index =-1;
        int maxcnt = -1;
        for(int i=0;i<rows;i++){
            int cntrow =0;
            for(int j=0;j<cols;j++){
                cntrow += arr[i][j];
                if(cntrow > maxcnt){
                    maxcnt = cntrow;
                    index =i;
                }
            }
        }
        return index;
    }
}


class Solution2 {
  public:
  // TIME COMPLEXITY : O(rows *LOG cols), SPACE COMPLEXITY : O(1).
    int first_occurence(vector<int>& arr){
        int n=arr.size();
        int low=0;
        int high= n-1;
        int ans =n;
        while(low<= high){
            int mid =low+(high-low)/2;
            // Look for smallest index .
            if(arr[mid]>=1){
                ans= mid;
                high = mid-1;
            }
            // find the index is next half.
            else if(arr[mid]<1){
                low =mid+1;
            }
        }
        return ans;
    }
  
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int rows = arr.size();
        int cols=arr[0].size();
        int index =-1;
        
        int maxcnt = 0;
        for(int i=0;i<rows;i++){
            int cntrow =0;
            cntrow = cols-first_occurence(arr[i]);
            if(cntrow>maxcnt){
                maxcnt =cntrow;
                index = i;
            }
        }
        return index;
    }
};
