//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        int strt=1;
        long long int end= x;
        long long int mid = strt + (end-strt)/2;
        long long int ans =-1;
        while(strt<=end){
            if(mid*mid == x){
                return mid;
            }
            if(mid*mid < x){
                ans = mid;
                strt=mid+1;
            }
            if(mid*mid > x){
                end=mid-1;
            }
           mid = strt +(end-strt)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends