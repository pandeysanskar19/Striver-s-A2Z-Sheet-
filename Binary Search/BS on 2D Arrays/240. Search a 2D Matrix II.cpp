class Solution1 {
public:

    // TIME COMPLEXITY : O(rows * cols), SPACE COMPLEXITY: O(1).
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows= matrix.size();
        int cols= matrix[0].size();
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
    // TIME COMPLEXITY: O(rows * log(cols)), SPACE COMPLEXITY: O(1). 
    bool binary_search(vector<int> arr,int target){
        int low=0;
        int high= arr.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid]== target) return true;
            else if(arr[mid]>target){
                high=mid-1;
            }
            else{
                low =mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows= matrix.size();
        int cols= matrix[0].size();
        for(int i=0;i<rows;i++){
            bool res = binary_search(matrix[i],target);
            if(res ==true){
                return true;
            }
        }
        return false;
    }
};


class Solution3 {
public:

    // TIME COMPLEXITY : O(rows + cols), SPACE COMPLEXITY: O(1).
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows= matrix.size();
        int cols= matrix[0].size();
        int r=0,c=cols-1;
        while(r < rows && c >=0){
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]<target) {
                r++;
            }
            else{
                c--;
            }
        }
        return false;
    }
};
