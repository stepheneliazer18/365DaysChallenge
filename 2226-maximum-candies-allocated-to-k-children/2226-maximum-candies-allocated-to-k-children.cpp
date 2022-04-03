class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long l = 1;
        long long r = *max_element(candies.begin(),candies.end());
        
        int maxi = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            

            long long ans = 0;
            for(auto &it: candies) ans += it/mid;
            
            if(ans >= k){
                maxi = max(maxi,mid);
            }
            
            if(ans < k) r = mid-1;
            else l = mid+1;
        }
        return maxi;
    }
};