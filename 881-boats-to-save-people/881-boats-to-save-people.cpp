class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int boat = 0;
        
        int l = 0;
        int r = n-1;
        
        while(l<=r){
            if(l == r){
                boat++;
                break;
            }
            else if(people[r] > limit - people[l]){
                r--;
            }
            else{
                l++;r--;
            }
            boat++;
        }
        
        return boat;
    }
};


/*

[3,2,3,2,2]
6
[2,2]
6
[3,5,3,4]
5
[3,2,2,1]
3
[1,2]
3
[3,1,7]
7
[44,10,29,12,49,41,23,5,17,26]
50

*/