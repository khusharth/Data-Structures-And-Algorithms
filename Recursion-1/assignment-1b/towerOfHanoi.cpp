#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Write your code here
    if(n==0) {
        return;
    }

    
    towerOfHanoi(n-1, source, destination, auxiliary);
    
    cout<<source<<" "<<destination<<endl; //Source to Destination 
    
    towerOfHanoi(n-1, auxiliary, source, destination);
    
}

int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}

