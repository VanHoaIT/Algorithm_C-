#include <iostream>
using namespace std;

int main() {
    // Read the number of addition problems Tudor needs to do
    int num_problems;
    cin >> num_problems;

    // Iterate through each problem
    for (int i = 0; i < num_problems; ++i) {
        // Read the two integers to add
        int a, b;
        cin >> a >> b;
        
        // Add the two integers and print the result
        int result = a + b;
        cout << result << endl;
    }

    return 0;
}
