//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
       int minlen = n+1 , currsum =0;
        // Your code goes here   
       int start = 0, end = 0;
    while (end < n) {
        // Keep adding array elements while current sum
        // is smaller than or equal to x
        while (currsum <= x && end < n)
            currsum += arr[end++];
 
        // If current sum becomes greater than x.
        while (currsum > x && start < n) {
            // Update minimum length if needed
            if (end - start < minlen)
                minlen = end - start;
 
            // remove starting elements
            currsum -= arr[start++];
        }
    }
        return minlen;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends