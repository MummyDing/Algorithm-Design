/*
Author: MummyDing
Date: 16/11/2015
Algorithm:DP-MaterixChain
*/
#include <iostream>
#define N 50+5
int M[N],s[N][N];
using namespace std;
void init(int n){
    for(int i = 0 ; i < n ;i++)
    for(int j = 0 ; j< n ;j++){
        if(i<j) s[i][j]=-2;
    }
}
void print(int x,int y){
    cout<<x+1<<" * "<<y+1<<endl;
}
int solve(int x,int y){
    if(x>=y)return -1;
    if(s[x][y] != -2) return s[x][y];
     if(x == y-1){
        s[x][y] = M[x]*M[y];
        print(x,y);
        return s[x][y];
     }
     int minx = M[x]*solve(x+1,y);
     int miny = solve(x,y-1)*M[y];
     if(minx < miny){
        s[x][y] = minx;
     }else {
        s[x][y] = miny;
     }
     return s[x][y];
}
int main()
{
    int n;
    cout<<"Input numbers of matrix "<<endl;
    while(cin>>n){
     cout<<"size of matrix "<<endl;
    for(int i = 0 ; i< n;i++)cin>>M[i];
    init(n);
    solve(0,n-1);
    cout<<"Input numbers of matrix "<<endl;
    }
    return 0;
}
