class Solution1 {
public:

// TIME COMPLEXITY : O(rows * cols),SPACE COMPLEXITY: O(1).
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
};


class Solution2 {
public:
    //TIME COMPLEXITY : O(rows * log(cols)), SPACE COMPLEXITY: O(1).
    bool exists(vector<int>& arr,int target){
        int n=arr.size();
        int low =0;
        int high=n-1;
        if(arr[high]< target) return false;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0;i<rows;i++){
            if(matrix.empty() || matrix[0].empty()) return false;
            bool exist = exists(matrix[i],target);
            if(exist ==true) return true;
        }
        return false;
    }
};



class Solution3 {
public:
// TIME COMPLEXITY: O(rows)+ O(log(cols)) , SPACE COMPLEXITY : O(1).
    bool exists(vector<int>& arr,int target){
        int n=arr.size();
        int low =0;
        int high=n-1;
        if(arr[high]< target) return false;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0;i<rows;i++){
            if(matrix[i][1]<= target && matrix[i][cols-1]>= target){
              // only one time the binary search work.
                return exists(matrix[i],target);
            }
        }
        return false;
    }
};



class Solution4 {
public:

// TIME COMPLEXITY : O(LOG( rows * cols)) , SPACE COMPLEXITY : O(1).
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low=0;int high =cols*rows-1;
        while(low<=high){
            int mid  = low+(high-low)/2;
            int r=mid/cols;int c=mid%cols;
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c]<target){
                low=mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return false;
    }
};
