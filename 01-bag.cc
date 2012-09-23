#include <list>
#include <iostream>

using namespace std;

list<int> list1;
void find_factor(int sum,int n){
	if(n < 0 || sum <= 0)
		return;
	
	if(sum == n){
		list1.reverse();
		list<int>::iterator iter;
		for(iter = list1.begin();iter != list1.end();iter++){
			cout<< *iter <<" + ";
		}
		cout<< n << endl;
		list1.reverse();
	}
	
	list1.push_front(n);
	find_factor(sum-n,n-1);
	list1.pop_front();
	find_factor(sum,n-1);
}

int main(){
	int sum,n;
	cout<<"请输入你要等于多少的数值：";
	cin>>sum;
	cout<<"请输入你要从1......n数列的n：";
	cin>>n;
	cout<<"所有可能的序列为：";
	find_factor(sum,n);
	return 0;
}
