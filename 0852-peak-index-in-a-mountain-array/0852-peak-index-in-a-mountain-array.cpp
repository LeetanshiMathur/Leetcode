class Solution {
public:
    // int peakIndexInMountainArray(vector<int>& arr) {
    //     vector<int>vect = arr;
    //     int ans;
    //     sort(vect.begin(), vect.end());
    //     int a = vect[vect.size()-1];
    //     int idx;
    //     for(int i=0; i<arr.size(); i++){
    //         if(arr[i]==a)
    //             idx = i;
    //     }
    //     int flag1 = 0 , flag2 = 0;
    //     int i = idx;
    //    while(i>=0){
    //        if(arr[i]>arr[i-1]){
    //            i--;
    //        }
    //        flag1 = 1;
    //    }
    //     i = idx;
    //     while(i<arr.size()){
    //         if(arr[i]>arr[i-1]){
    //             i++;
    //         }
    //         flag2 = 1;
    //     }
    //     if(flag1 == 1 && flag2 == 1){
    //         return idx;
    //     }
    //         return idx;
    // }
   int peakIndexInMountainArray(vector<int>& arr) {
    int ans;
    int idx = -1;
    int a = INT_MIN; // Set a very small value as the initial maximum

    // Find the peak element and its index in the original array
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > a) {
            a = arr[i];
            idx = i;
        }
    }

    // Check if the peak index is valid and satisfies the conditions of a mountain
    if (idx > 0 && idx < arr.size() - 1 && arr[idx - 1] < arr[idx] && arr[idx] > arr[idx + 1]) {
        ans = idx;
    } else {
        ans = -1; // Peak index is not valid or does not satisfy mountain conditions
    }

    return ans;
}

 };
