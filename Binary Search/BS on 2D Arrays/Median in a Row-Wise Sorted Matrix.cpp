class Solution1 {
  public:
  // TIME COMPLEXITY : O(np_rows*no_cols ) + O(no_rows*no_cols*log(no_rows*no_cols)),
  //SPACE COMPLEXITY: O(no_rows* no_cols).
    int median(vector<vector<int>> &mat) {
        // code here
        int no_rows=mat.size();
        int no_cols = mat[0].size();
        vector<int> arr; // 1D list.
        for(int i=0;i<no_rows;i++){
            for(int j=0;j<no_cols;j++){
                arr.push_back(mat[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int t = arr.size();
        for(int i=0;i<arr.size();i++){
            if(t%2 != 0){
                int num = t /2;
                return arr[num];
            }
        }
        return 0;
    }
};


class Solution2 {
  public:
  // time compelxity: O(log (no_cols)).
    int upper_bound(vector<int>& arr,int k){
        int low =0;
        int high = arr.size()-1;
        int ans=arr.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] > k){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
  // time complexity : O(now_rows * log(no_cols)).
    int counts(vector<vector<int>>& mat,int cols){
        int no_rows = mat.size();
        int cnt =0;
        for(int i=0;i<no_rows;i++){
            cnt += upper_bound(mat[i],cols);
        }
        return cnt;
    }
  // TIME COMPLEXITY:O( LOG(max_el - min_el) *(no_rows* LOG(no_cols))
  // SPACE COMLEXITY : O(1).
    int median(vector<vector<int>> &mat) {
        // code here
        int no_rows= mat.size();
        int no_cols= mat[0].size();
        int min_el=mat[0][0];
        for(int i=0;i<no_rows;i++){
            if(mat[i][0]<min_el){
                min_el = mat[i][0];
            }
        }
        int low = min_el;
        int max_el =0;
        for(int i=0;i<no_rows;i++){
            if(mat[i][no_cols-1]>=max_el){
                max_el = mat[i][no_cols-1];
            }
        }
        int high = max_el;
        int required = (no_cols*no_rows)/2;
        while(low<=high){
            int mid =low+(high-low)/2;
            int smaller_equals = counts(mat,mid);
            if(smaller_equals <= required){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};



