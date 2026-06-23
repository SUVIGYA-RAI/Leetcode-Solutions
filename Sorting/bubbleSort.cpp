#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={5,8,2,4,9};
    int n=5;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]<arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
    for(int x:arr){
        cout<<x<<" ";
    }
}