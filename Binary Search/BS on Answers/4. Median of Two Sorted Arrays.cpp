class Solution1 {
public:    // Naive approach (simulation)

    double median(vector<int>& arr){
        int n=arr.size();
        double mid=0;
        if(n%2!=0){
            int n1=(n/2);
            mid=arr[n1];
        }
        else{
            int n1 =n/2 ;
            int n2 =(n/2)-1;
            mid = (arr[n1]+arr[n2])/2.0;
        }
        return mid;
    }
    vector<int> merge(vector<int>& nums1,vector<int>& nums2){
        vector<int> ans;
        int n1=nums1.size();
        int n2=nums2.size();
        int left=0;
        int right=0;
        while(left<n1 && right<n2){
            if(nums1[left]<nums2[right]){
                ans.push_back(nums1[left]);
                left++;
            }
            else{
                ans.push_back(nums2[right]);
                right++;
            }
        }
        while(left<n1){
            ans.push_back(nums1[left]);
            left++;
        }
        while(right<n2){
            ans.push_back(nums2[right]);
            right++;
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>sorted= merge(nums1,nums2);
        double medi= median(sorted);
        return medi; 
    }
};


class Solution2 {
public:   // better optimised space.

    double median(vector<int>& arr1,vector<int>& arr2){
        int n1=arr1.size();
        int n2=arr2.size();
        int i=0,j=0;
        int n=(n1+n2);
        int idx2=n/2;
        int idx1=idx1-1;
        int cnt=0;
        int idx1el =-1,idx2el=-1;
        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j]){
                if(cnt==idx1) idx1el=arr1[i];
                if(cnt==idx2) idx2el=arr1[i];
                cnt++;i++;
            }
            else{
                if(cnt==idx2) idx2el =arr2[j];
                if(cnt==idx2) idx2el =arr2[j];
                cnt++;j++;
            }
        }
        while(i<n1){
            if(cnt==idx1) idx1el=arr1[i];
            if(cnt==idx2) idx2el=arr1[i];
            cnt++;i++;
        }
        while(j<n2){
            if(cnt==idx1) idx1el =arr2[j];
            if(cnt==idx2) idx2el =arr2[j];
            cnt++;j++;   
        }
        if(n%2==1) return idx2el;

        return (double)((double) (idx1el+idx2el))/2.0;

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double medi= median(nums1,nums2);
        return medi; 
    }
};

class Solution3 {
public:
// optimal by binary search on answers.
// TIME COMPLEXITY : O(log(min(n1,n2))).
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2=nums2.size();
        // find the smaller array.
        if(n1>n2) findMedianSortedArrays(nums2,nums1);
        int low =0; int high= n1;
        int n=n1+n2;// total size
        while(low<=high){
            int mid1 =low+(high-low)/2; // mid of nums1.
            int mid2 =((n1+n2+1)/2)-mid1; // left element from nums2.
            int l1 =INT_MIN; int r1 =INT_MAX;
            int l2 =INT_MIN; int r2 =INT_MAX;
            
            // safe from runtime (edge)issues.
            if(mid1 <n1) l1 =nums1[mid1-1];
            if(mid2 <n2) l2 =nums2[mid2-1];
            if(mid1 >=0) r1 =nums1[mid1];
            if(mid2 >=0) r2 =nums2[mid2];

            if(l1 <= r2 && l2<=r1){
                // // median for odd numbers.
                if(n%2==1) return max(l1,l2);
                // median for even numbers.
                else{
                    return (double)((max(l1,l2)+min(r1,r2))/2.0);
                }
            }
            else if(l1>r2) high=mid1-1;
            else{
                low= mid1+1;
            }
            
        }
        return 0;
    }
};
