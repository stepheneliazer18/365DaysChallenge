class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        for(int i=0 ; i<names.size() ; i++){
            for(int j=0 ; j<names.size() ; j++){
                if(heights[i]>heights[j]){
                    swap(heights[i],heights[j]);
                    swap(names[i],names[j]);
                }
            }
        }
        return names ;
    }
};