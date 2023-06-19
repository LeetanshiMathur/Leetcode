class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>altitude;
        altitude.push_back(0);
        altitude.push_back(gain[0]);
        for(int i=2; i<n+1; i++){
            int alt = altitude[i-1] + gain[i-1];
            altitude.push_back(alt);
        }
        sort(altitude.begin(), altitude.end());
        return altitude[n];
    }
};