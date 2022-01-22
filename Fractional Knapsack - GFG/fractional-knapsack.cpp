// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    struct{
        bool operator()(Item i1, Item i2)const{
            double vi1 = (double)i1.value/(double)i1.weight;
            double vi2 = (double)i2.value/(double)i2.weight;
            
            return vi1 > vi2;
        }
    }cmp;
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        
        double res = 0.0;
        for(int i=0;i<n;i++){
            if(arr[i].weight>W){
                res += (double)W*((double)arr[i].value/(double)arr[i].weight);
                W = 0;
                break;
            }
            else{
                W-=arr[i].weight;
                res+=arr[i].value;
            }
        }
        return res;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends