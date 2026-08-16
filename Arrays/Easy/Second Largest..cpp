class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n=arr.size();
        
        // code here
//APPROACH 1:TIME COMPLEXITY O(N) , SPACE COMPLEXITY: O(1).
        int largest=arr[0];
        int slargest=-1;
        for(int i=1;i<n;i++){
            if(arr[i]>largest){
                slargest=largest;
                largest=arr[i];
                
            }
            else if(arr[i]>slargest && arr[i]<largest){
                slargest=arr[i];
            }
        }
        return slargest;
    }
};
