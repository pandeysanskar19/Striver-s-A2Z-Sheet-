class Solution {
public:

    // Find the index of the max element of particular column.
    int maxElement(vector<vector<int>>& mat , int cols){
       int no_rows = mat.size();
       int max_el = INT_MIN;
       int maxRow_idx = -1;

       for(int i=0;i<no_rows;i++){
            if(mat[i][cols]> max_el){
                max_el = mat[i][cols];
                maxRow_idx = i;  
            }
       }
       return maxRow_idx;
    }

// TIME COMPLEXITY : O(no_rows * LOG(no_cols)) , SPACE COMPLEXITY : O(1). 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int no_rows = mat.size();
        int no_cols = mat[0].size();
        // Binarysearch on columns.
        int low = 0;int high = no_cols-1;
        while(low<=high){
            int mid = low+(high-low)/2; // Find column index
            int row = maxElement(mat,mid); // find row index.

            // left element of max element of the column.
            int left = mid-1>=0 ? mat[row][mid-1] : -1; 
            // right element of max element of the row.  
            int right = mid+1 < no_cols ? mat[row][mid+1] : -1;


            // found peak element.
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }
            // trim right space of a matrix.
            else if(mat[row][mid] < left){
                high = mid-1;
            }
            // trim left space of a matrix.
            else{
                low =mid+1;
            }
        }
        return {-1,-1};
    }
};
