/**
* StableMatch C++
* Author: MummyDing
* Date: 2015.9
**/
#include<iostream>
using namespace std;
#define MAX_SIZE 100
#define SIZE 5
int pa[SIZE][SIZE],oPa[SIZE][SIZE];
int pb[SIZE][SIZE],oPb[SIZE][SIZE];
struct Set{
    public:
    int set[MAX_SIZE];
    int size,real_size;
    void init(int _size){
        for(int i = 0 ;i < _size;i++) set[i]=i;
        real_size=size=_size;
    }
    int getData(){
        for(int i = 0; i<size; i++){
            if(~set[i])return set[i];
        }
    }
    void addData(int num){
        set[size++]=num;
        real_size++;
    }
    void removeData(int num){
        for(int i = 0; i<size; i++){
            if(num == set[i]){
                set[i] = -1;
                real_size--;
                return ;
            }
        }
    }
    bool findData(int num){
        for(int i = 0; i<size; i++){
            if(num == set[i]) return true;
        }
        return false;
    }
    int getSize(){
        return real_size;
    }
   
}a,b;
void printXName(int i){
    switch(i){
    case 0:
        cout<<"吕布 ";
        break;
    case 1:
        cout<<"刘备 ";
        break;
    case 2:
        cout<<"孔明 ";
        break;
    case 3:
        cout<<"周瑜 ";
        break;
    case 4:
        cout<<"曹操 ";
        break;
    }
}
void printYName(int i){
    switch(i){
    case 0:
        cout<<"貂蝉 ";
        break;
    case 1:
        cout<<"大乔 ";
        break;
    case 2:
        cout<<"小乔 ";
        break;
    case 3:
        cout<<"尚香 ";
        break;
    case 4:
        cout<<"阿丑 ";
        break;
    }
}
struct ResultSet{
    int pair[MAX_SIZE][2];
    int size;
    void init(){
        size=0;
    }
    void addPair(int x,int y){
        pair[size][0]=x;
        pair[size++][1]=y;
    }
    void removePair(int x,int y){
        for(int i =0 ;i<size; i++){
            if(pair[i][0]==x && pair[i][1]==y){
                pair[i][0]=pair[i][1]=-1;
		break;
            }
        }
    }
    int findX(int Y){
        for(int i =0; i<size; i++){
            if(pair[i][1]== Y){
                return pair[i][0];
            }
        }
        return -1;
    }
    void print(){
        for(int i=0;i<size; i++){
            if(~pair[i][0]){
                printXName(pair[i][0]);
                printYName(pair[i][1]);
                cout<<endl;
            }
        }
    }
}resultSet;
void StableMatch(){
    int size = a.getSize();
    int p=0;
    while(a.getSize()){
        int numA = a.getData();
        for(int i = 0 ; i<SIZE; i++){
            int numB=pa[numA][i];
            if(b.findData(numB)){
                resultSet.addPair(numA,numB);
                a.removeData(numA);
                b.removeData(numB);
                break;
            }
            else{
                int _numOA=resultSet.findX(numB); 
                if(oPb[numB][numA] <  oPb[numB][_numOA]){
                    a.removeData(numA);
                    a.addData(_numOA);
                    resultSet.removePair(_numOA,numB);
                    resultSet.addPair(numA,numB);
		    break;
                }              
            }
        }
    }
       
}
int main()
{
    int tmpPos;
    cout<<"偏好矩阵A"<<endl;
    for(int i =0 ;i<SIZE; i++)
        for(int j=0; j<SIZE; j++){
	    cin>>tmpPos;
	    pa[i][j]=tmpPos;
            oPa[i][tmpPos]=j;
        }
    cout<<"偏好矩阵B"<<endl;
    for(int i=0 ;i<SIZE; i++)
        for(int j=0 ;j<SIZE; j++){
            cin>>tmpPos;
            pb[i][j]=tmpPos;
            oPb[i][tmpPos]=j;
        }
    int tmp[SIZE];
    a.init(SIZE);
    b.init(SIZE);
    resultSet.init();
    StableMatch();
    resultSet.print();
    return 0;
}
