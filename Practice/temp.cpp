//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        //Your code here
        vector<int> vec;
        vector<int>::iterator it;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(A2[i]==A1[j]){
                    vec.push_back(A2[i]);
                    it=A1.begin()+j;
                    A1.erase(it);
                }
            }
        }
        sort(A1.begin(),A1.end());
        for(int i=0;i<A1.size();i++){
            vec.push_back(A1[i]);
        }
        return vec;
    } 
};

//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    n=11;
      	m=4;
	    vector<int> a1={2,1,2,5,7,1,9,3,6,8,8};
	    vector<int> a2={2, 1, 8, 3};
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 

// } Driver Code Ends