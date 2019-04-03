## Program to create a DS which could store multiple stacks with a fixed threshold

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class SetOfStacks{
	public:
		vector<stack<int>> stacks;
		int currStack;
		int threshold;
		SetOfStacks(){
			currStack = 0;
			threshold  = 3;
		}
		
		int pop(){
			if(stacks.empty()){
				return -1;
			}
			if(stacks[currStack].empty()){
				stacks.pop_back();
				if(stacks.empty()){
					return -1;
				}
				currStack--;
			}
			int val = stacks[currStack].top();
			stacks[currStack].pop();
			return val;
			
		}
		
		void push(int element){
			if(stacks.empty()){
				stack<int> s;
				s.push(element);
				stacks.push_back(s);
				return;
			}
			if(stacks[currStack].size()>=threshold){
				stack<int> newStack;
				newStack.push(element);
				stacks.push_back(newStack);
				currStack++;
				return;
			}
			stacks[currStack].push(element);
			return;
			
		}
		

	
};


int main() {
	SetOfStacks ss;
	for(int i = 0;i<10;i++){
		ss.push(i);
	}
	for(int i = 0;i<10;i++){
		cout<<ss.pop()<<endl;
	}
	return 0;
}