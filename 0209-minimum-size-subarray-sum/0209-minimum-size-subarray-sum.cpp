class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minlen = n+1 , currsum =0;
        // Your code goes here   
       int start = 0, end = 0;
    while (end < n) {
        // Keep adding array elements while current sum
        // is smaller than or equal to x
        while (currsum < target && end < n)
            currsum += nums[end++];
 
        // If current sum becomes greater than x.
        while (currsum >= target && start < n) {
            // Update minimum length if needed
            if (end - start < minlen)
                minlen = end - start;
 
            // remove starting elements
            currsum -= nums[start++];
        }
        
    }
        if(minlen == n+1) return 0;
        return minlen;
    }
};