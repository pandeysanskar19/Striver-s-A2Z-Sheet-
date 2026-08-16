class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
// APPROACH 1: TIME COMPLEXITY:O(N),SPACE COMPLEXITY: O(1).
         int largest = arr[0];
         for(int x:arr){
             if(x>largest){
                 largest =x;
             }
         }
         return largest;
// APPROACH 2(STL): TIME COMPLEXITY:O(N),SPACE COMPLEXITY: O(1).        
        //int largest = *max_element(arr.begin(),arr.end());
        //return largest;
    }
};
