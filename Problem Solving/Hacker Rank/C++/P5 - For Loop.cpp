#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int start, end;
    
    cin >> start >> end;
    
    char englishNumbers[9][10] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" }; 
    
    for (int i = start ; i <= end; i++) {
        if (i < 10) cout << englishNumbers[i - 1] << endl;
        else cout << (i % 2 ? "odd" : "even") << endl;
    }
    
    return 0;
}