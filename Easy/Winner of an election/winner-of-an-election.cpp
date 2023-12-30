//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
   vector < string > winner(string arr[], int n) {
   unordered_map < string, int > mp;
   int maxi = 0;
   vector < string > ans(2);
   for (int i = 0; i < n; i++) {
     mp[arr[i]]++;
     maxi = max(maxi, mp[arr[i]]);
   }
   for (auto it: mp) {
     if (it.second == maxi) {
       if (ans[0] == "") {
         ans[0] = it.first;;
         ans[1] = to_string(maxi);
       }
       if (ans[0] > it.first)
         ans[0] = it.first;
     }
   }
   return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends