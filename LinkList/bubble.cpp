#include<iostream>
using namespace std;
void bubble(int * a, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
int main(){
    int arr[] = {1,4,3,5,6,7,4,3,11,0,-1,4,6};
    bubble(arr,13);
    for(int j = 0;j<13;j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}