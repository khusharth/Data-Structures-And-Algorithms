#include <iostream>
using namespace std;
#include <stack> 

bool checkBalanced(string expr) 
{ 
    stack<char> s; 
    char x; 
  
    // Traversing the Expression 
    for (int i=0; expr[i] != '\0'; i++) 
    { 
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
        { 
            // Push the element in the stack 
            s.push(expr[i]); 
            continue; 
        } 
  
        
        if(expr[i] == ')') {
            // Store the top element in x
            if(s.empty())
                return false;
            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='[') 
                return false; 
        }
        
        else if (expr[i] == '}') {
            // Store the top element in x 
            if(s.empty())
                return false;
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='[') 
                return false;
        }
  
        else if (expr[i] == ']') {
            // Store the top element in x 
            if(s.empty())
                return false;
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{') 
                return false; 
        }
        
    
    }  
  
    // Check Empty Stack 
    return (s.empty()); 
} 

int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

