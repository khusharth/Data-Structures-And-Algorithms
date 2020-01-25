#include <iostream>
using namespace std;
#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra) {
	// Write your code here
    if (input.empty()) {
        return;    
    }
    
    int top = input.top();
	input.pop();
    
    reverseStack(input, extra);
    
    int topInput, topExtra;
    while(!input.empty()) {
        
        topInput = input.top();
		input.pop();
        extra.push(topInput);
    }
    
    input.push(top);
    
    while(!extra.empty()) {
        
       	topExtra = extra.top();
		extra.pop();
        input.push(topExtra);
    }
    

}

int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	s1.push(val);
    }
    reverseStack(s1, s2);
    while(!s1.empty()) {
    	cout << s1.top() << " ";
    	s1.pop();
    }
}

