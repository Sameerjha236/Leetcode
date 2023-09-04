//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    int kthSmallest(int arr[], int l, int r, int k) {
        while (l < r) {
            int mid = partition(arr, l, r);
            int pos = mid - l + 1;

            if (pos == k) {
                return arr[mid];
            } else if (pos < k) {
                l = mid + 1;
                k -= pos;
            } else {
                r = mid - 1;
            }
        }

        return arr[l];
    }

private:
    int partition(int arr[], int l, int r) {
        int pivot = arr[r];
        int i = l;

        for (int j = l; j < r; j++) {
            if (arr[j] <= pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }

        swap(arr[i], arr[r]);
        return i;
    }
};


//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends