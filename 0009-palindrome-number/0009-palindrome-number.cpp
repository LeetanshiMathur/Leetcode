class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int num = x;
        long sum = 0;
        bool ans;
        while(x>0){
            int r = x %10;
            sum = sum*10 + r;
            x = x/10;
        }
        if(sum == num) ans = true;
        else 
            ans = false;
        return ans;
    }
};