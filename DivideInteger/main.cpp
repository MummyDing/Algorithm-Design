/*
Author:MummyDing
Date:25/10/2015
Algorithm:Divide Integer
*/
#include<iostream>
#include<cstdio>
#define N 100+5
using namespace std;
int ans[N],num,cnt=0;
void divide(int n,int p){
      if(!n){
        for(int i=0;i<p;i++)
        printf(i== p -1 ? "%d\n":"%d ",ans[i]);
        cnt++;
        return;
      }
      for(int i=n;i>0;i--)
        if(p==0||i<=ans[p-1]){
        ans[p]=i;
        divide(n-i,p+1);
      }
}
int main()
{
    cout<<"Input n:"<<endl;
    cin>>num;
    divide(num,0);
    cout<<"Total Cases: "<<cnt<<endl;
}
