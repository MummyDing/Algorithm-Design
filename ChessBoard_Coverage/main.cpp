/*
Author:MummyDing
Date:18/10/2015
Algorithm:ChessBoard Coverage
*/
#include<iostream>
#include<stdio.h>
#define N 500
using namespace std;
int chess[N][N]={0};
int n;
int dir[4][3][2]={
    {{0,1},{1,0},{1,1}},{{0,-1},{1,-1},{1,0}},
    {{-1,0},{-1,1},{0,1}},{{-1,-1},{-1,0},{0,-1}}
};
void print(){
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    printf(j== n-1 ? "%d\n":"%d ",chess[i][j]);
}
int calcType(int sx,int sy,int halfX,int halfY){
    int type = 0;
    if(sx > halfX) type+=2;
    if(sy > halfY) type++;
    return type;
}
void getXY(int &px,int &py,int type){
    if(type == 1) py++;
    else if(type==2)px++;
    else if(type==3)px++,py++;
}
void fillBoard(int x,int y,int sx,int sy,int width){

    if(width == 1) return;
    int midX = width/2 + x -1;
    int midY = width/2 + y -1;
    int type = calcType(sx,sy,midX,midY);
    int px = midX, py = midY;
    getXY(px,py,type);
    for(int i=0;i<3;i++){
        int tmpX = px+dir[type][i][0];
        int tmpY = py+dir[type][i][1];
        chess[tmpX][tmpY] = type+1;
    }
    if(width == 2) {return;
    }

    for(int i =0 ;i<4;i++){
        if(i==0){
            if(i==type) fillBoard(x,y,sx,sy,width/2);
            else fillBoard(x,y,midX,midY,width/2);
        }else if(i==1){
            if(i==type) fillBoard(x,width/2+y,sx,sy,width/2);
            else fillBoard(x,width/2+y,midX,midY+1,width/2);
        }else if(i==2){
            if(i==type) fillBoard(width/2+x,y,sx,sy,width/2);
            else fillBoard(width/2+x,y,midX+1,midY,width/2);
        }else{
            if(i==type) fillBoard(width/2+x,width/2+y,sx,sy,width/2);
            else fillBoard(width/2+x,width/2+y,midX+1,midY+1,width/2);
        }
    }
}
int main(){
    cout<<"Input the width"<<endl;
    cin>>n;
    cout<<"Input x and y:"<<endl;
    int x,y;
    cin>> x>>y;
    x--,y--;
    chess[x][y]=5;
    fillBoard(0,0,x,y,n);
    print();
    return 0;
}
