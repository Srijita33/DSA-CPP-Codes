#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
}
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        
        if(l==r) return;
        int mid=(l+r)/2;
        //cout<<mid<<endl;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
    }
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n;
    
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    //cout<<"[";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //cout<<"]";
    
    return 0;
}
