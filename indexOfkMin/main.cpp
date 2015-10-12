#include<iostream>
#define N 50+5
using namespace std;
int n,k;
struct Array{
	int num[N];
	int size;
	Array(){
        size=0;
	}
	void addNum(int p){
		num[size++]=p;
	}
	int getNum(int p){
		return num[p];
	}
	int getSize(){
		return size;
	}
}Num;
int indexOfkMin(Array num,int pos){
	Array leftArray,rightArray;
	int posNum = num.getNum(0);
	if(num.getSize() == 1)return posNum;
	for(int i = 1; i < num.getSize(); i++){
		int tmpNum = num.getNum(i);
		if(posNum>tmpNum) leftArray.addNum(tmpNum),pos++;
		else rightArray.addNum(tmpNum);
	}
	if(pos == k) return posNum;
	if(pos > k) return indexOfkMin(leftArray,1);
	else return indexOfkMin(rightArray,pos+1);
}
int main()
{
	cout<<"请输入元素个数以及k的值";
	cin>>n>>k;
	if(k>n) return 0;
	cout<<"请输入"<<n<<"个数"<<endl;
	int tmp;
	for(int i=0 ;i<n ;i++) {
		cin>>tmp; Num.addNum(tmp);
	}
	cout<<indexOfkMin(Num,1)<<endl;
}
