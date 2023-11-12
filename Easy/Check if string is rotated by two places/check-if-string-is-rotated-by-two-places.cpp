//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
   bool isRotated(string str1, string str2)
    {
         if(str2.size()!=str1.size())  return false;
        string copy = str1;
        int n = str1.size();
        string temp;
            temp ="";
            temp.push_back(str1[n - 2]);
            temp.push_back(str1[n - 1]);
            str1.pop_back();
            str1.pop_back();
            
            temp+=str1;
            // cout<<temp<<" ";
            if(temp == str2) return true;
            
            temp ="";
            char first = copy[0];
            char second = copy[1];
            
            temp+=copy.substr(2,copy.size() - 2);
            temp.push_back(first);
            temp.push_back(second);
            // cout<<temp<<" ";
            if(temp == str2)  return true;
            
        return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends