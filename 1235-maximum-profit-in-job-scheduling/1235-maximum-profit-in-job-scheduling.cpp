class Solution {
public:
    struct Job{ 
        int start;	 // Job Id 
        int end; // Deadline of job 
        int profit; // Profit if job is over before or on deadline 
    };
    struct{
        bool operator()(Job j1, Job j2)const{
            return j1.end < j2.end;
        }
    }cmp;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        
        struct Job job[n];
        for(int i=0;i<n;i++){
            job[i].start = startTime[i];
            job[i].end = endTime[i];
            job[i].profit = profit[i];
        }
        sort(job,job+n,cmp);
        vector<int> vec;
        int maxi = 0;
        for(int i=0;i<n;i++)vec.push_back(job[i].profit);
        for(int i=1;i<n;i++){
            vec[i] = max(vec[i],vec[i-1]);
            for(int j=i-1;j>=0;j--){
                if(job[j].end<=job[i].start){
                    vec[i] = max(vec[i],vec[j] + job[i].profit);
                    break;
                }
            }
            maxi = max(maxi,vec[i]);
        }
        return maxi;
    }
};