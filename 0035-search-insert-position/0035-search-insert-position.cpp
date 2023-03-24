class Solution {
public:
    
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int end = nums.size()-1;
        
        while(lo <= end){
        int mid = end - lo / 2 + lo;
            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid]) 
                lo = mid +1;
            else 
                 end = mid-1;
        }
        return end+1;
  
    }
};