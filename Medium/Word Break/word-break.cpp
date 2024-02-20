//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings
class Solution
{
public:
    unordered_set<string> st;
    bool solve(int idx, int n, string s,  vector<string> &dictionary)
    {
        if(idx==n)
        {
            return true;
        }
        
        if(st.find(s)!=st.end())
        {
            return true;
        }
        
        for(int l=0; l<n; l++)
        {
            string temp=s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(idx+l, n, s, dictionary))
            {
                return true;
            }
        }
        return false;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        int size=s.length();
        for(auto word: dictionary)
        {
            st.insert(word);
        }
        return solve(0,size, s, dictionary);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends