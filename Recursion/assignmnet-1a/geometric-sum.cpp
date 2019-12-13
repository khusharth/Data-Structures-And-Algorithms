#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;



double geometricSum(int k) {
    // Write your code here
    if(k==0) {
        return 1;
    } 
    
	double smallAns =  1/pow(2, k);
    double a = geometricSum(k-1);
    

    return (a + smallAns);

}
int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}

