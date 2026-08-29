class Solution1 {
  public:
// TIME COMPLEXITY: O(a+b) , SPACE COMPLEXITY : O(a+b). 
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int a1 =a.size();
        int b1 =b.size();
        vector<int> sorted;
        int left=0;int right=0;
        while(left < a1 && right <b1){
            if(a[left]<b[right]){
                sorted.push_back(a[left]);
                left++;
            }
            else{
                sorted.push_back(b[right]);
                right++;
            }
        }
        while(left<a1){
            sorted.push_back(a[left]);
            left++;
        }
        while(right<b1){
            sorted.push_back(b[right]);
            right++;
        }
        return sorted[k-1];
    }
};

class Solution2 {
  public:
// TIME COMPLEXITY: O(a+b) , SPACE COMPLEXITY: O(1).
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int a1 =a.size();
        int b1 =b.size();
        int cnt=0;
        int left=0;int right=0;
        // find the kth element in array a and b.
        while(left<a1 && right<b1){
            if(a[left]<=b[right]){
                cnt++;
                if(cnt == k){
                    return a[left];
                }
                left++;
            }
            else{
                cnt++;
                if(cnt==k){
                    return b[right];
                }
                right++;
            }
        }
        // find the kth element in remaining array a.
        while(left <a1){
            cnt++;
            if(cnt == k){
                return a[left];
            }
            left++;
        }
        // find the kth element in remaining array b.
        while(right < b1){
            cnt++;
            if(cnt == k){
              return b[right];
            } 
            
            right++;
        }
        return -1;
    }
};

class Solution3 {
  public:
// TIME COMPLEXITY : O(MIN(a,b) , SPACE COMPLEXITY : O(1).
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int a1 =a.size();
        int b1 =b.size();
        // ensure a is smaller array.
        if(a1>b1){
            return kthElement(b,a,k);
        }
        // length of the left half
        int left =k;
        
        int low =max(0,k-b1),high=min(k,a1);
        while(low<=high){
            int mid1 =low+(high-low)/2;
            int mid2 =left - mid1;
            
            int l1 = (mid1>0) ? a[mid1-1] : INT_MIN;
            int l2 = (mid2>0) ? b[mid2-1] : INT_MIN;
            int r1 = (mid1<a1)? a[mid1] : INT_MAX;
            int r2 = (mid2 < b1)? b[mid2] : INT_MAX;
            // we found the answer.
            if(l1 <=r2 && l2 <= r1){
                return max(l1,l2);
            }
            // eliminate right half.
            else if(l1 >r2){
                high = mid1-1;
            }
            // eliminate left half.
            else{
                low=mid1+1;
            }
        }
        return -1;
    }
};
