// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    struct{
        bool operator()(Job j1, Job j2)const{
            return j1.profit > j2.profit;
        }
    }cmp;
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int max_dead = 0;
        for(int i=0;i<n;i++){
            max_dead = max(max_dead,arr[i].dead);
        }
        vector<int> vec(max_dead+1,-1);
        int cnt = 0;
        int res = 0;
        for(int i=0;i<n;i++){
            int x = arr[i].dead;
            if(vec[x]!=-1){
                while(x>0){
                    if(vec[x]==-1){
                        vec[x] = arr[i].profit;
                        res+=vec[x];
                        cnt++;
                        break;
                    }
                    x--;
                }
            }
            else{
                vec[x] = arr[i].profit;
                res+=vec[x];
                cnt++;
            }
        }
        vector<int> ans({cnt,res});
        return ans;
    } 
};

//5
//1 2 100 2 1 19 3 2 27 4 1 25 5 1 15

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends