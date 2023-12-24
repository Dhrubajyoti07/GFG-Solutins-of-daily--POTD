//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int, int>> v;
        int cnt=0, tmp;
        for(int i=0; i<n; i++){
            v.push_back(make_pair(price[i], i));
        }
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++){
            tmp=v[i].second;
            while(tmp>=0){
                if(k<v[i].first) return cnt;
                k-=v[i].first;
                tmp--;
                cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends