#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    long int n;
    int sum = 0;
    int i = 0;

    cout << "Enter the Number in the form of binary " << endl;
    cin >> n;

    while (n != 0) {
        if (n & 1) {   
            int k = pow(2, i); // Using int instead of float
            sum = sum + k;
        }
        n = n / 10;
        i++;
    }
    cout << "Decimal Equivalent: " << sum << endl;

    return 0;
}

