#include<bits/stdc++.h> 
using namespace std;
#define ll long long 


void qsort(vector<int> &a,int l=0, int r=-1){
    if (r<0)r=size(a)-1;
    if (l>=r)return;
    int mid= a[(l+r)>>1],i=l-1,j=r+1;
    while(1){
        while(a[++i]<mid);
        while(a[--j]>mid);
        if (i>=j)break;
        swap(a[i],a[j]);
    }
    qsort(a,l,mid),qsort(a,mid+1,r);
}