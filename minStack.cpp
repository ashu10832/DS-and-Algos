# Program to have a stack which also keeps track of the minimum element in it

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class MinStack{
	public:
		stack<pair<int,int>> s;
	
	void push(int ele){
		if(s.empty()){
			s.push(make_pair(ele,ele));
			return;
		}
		int min;
		pair<int,int> nextPair = s.top();
		if(nextPair.second<ele){
			min = nextPair.second;
		}
		else{
			min = ele;
		}
		s.push(make_pair(ele,min));
		return;
	}
	
	int pop(){
		int ele =  s.top().first;
		s.pop();
		return ele;
	}
	
	int min(){
		return s.top().second;
		
	}

	
};


int main() {
	MinStack ms;
	ms.push(-29);
	ms.push(5);
	ms.push(19);
	ms.push(2);
	ms.push(-5);
	cout<<ms.pop()<<endl;
	cout<<ms.min();
	return 0;
}