#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int> v){
    int len=v.size();
    if(len<0){
        return -1;
    }
    int max = v[0];
    for(auto& i:v){
        if(max<i){max=i;}
    }
    return max;
};
int findMin(vector<int> v){
    int len=v.size();
    if(len<0){
        return -1;
    }
    int min = v[0];
    for(auto& i:v){
        if(min>i){min=i;}
    }
    return min;
};
bool great(int a,int b){
    return a>b;
}
bool great5(int a,int b){
    if(a!=5 && b!=5){
        return a>b;
    }
    if(a!=5){return true;}
    return false;
}
int multi(int a,int b){return a*b;}
void display(vector<int> v){
    cout<<"\nDisplaying Vector: ";
    for(auto i:v){
        cout<<i<<" ";
    }
}

int main(int argc, char const *argv[]){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //Maping the array to vector
    vector<int> v1;
    for(int i=0;i<n;i++){
        v1.push_back(arr[i]);
    }
    cout<<"\nDisplaying Vector: ";
    for(auto i:v1){
        cout<<i<<" ";
    }
    cout<<"\nDisplaying Vector with iterator: ";
    for(vector<int>::iterator it = v1.begin();it != v1.end(); it++){
        cout<<*it<<" ";
    }
    cout<<"\nMax Value = "<<findMax(v1)<<" "<<*max_element(v1.begin(),v1.end());
    cout<<"\nMin Value = "<<findMin(v1)<<" "<<*min_element(v1.begin(),v1.end());
    // vector<int>::iterator it = max_element(v1.begin(),v1.end());
    // *it = 754;
    // cout<<"\nDisplaying Vector: ";
    // for(auto i:v1){
    //     cout<<i<<" ";
    // }
    cout<<"\nSum = "<<accumulate(v1.begin(),v1.end(),0);
    cout<<"\nMultiply = "<<accumulate(v1.begin(),v1.end(),1,multi);

    // sort(v1.begin(),v1.end());
    // display(v1);
    // sort(v1.begin(),v1.end(),great);
    // display(v1);
    sort(v1.begin(),v1.end(),great5);
    display(v1);
    

    return 0;
}