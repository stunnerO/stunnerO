#include <iostream>
using namespace std;

class PatternPrinter {
public:
    void printPattern(int n) {
        for (int i = 0; i < n; i++) {
            printRow(i + 1);
            cout << endl;
        }
        for (int i = n - 2; i >= 0; i--) {
            printRow(i + 1);
            cout << endl;
        }
    }

private:
    void printRow(int n) {
        for (int i = 0; i < n; i++) {
            cout << static_cast<char>('A' + i);
        }
        for (int i = n - 2; i >= 0; i--) {
            cout << static_cast<char>('A' + i);
        }
    }
};

int main() {
    PatternPrinter printer;
    printer.printPattern(5); // Change the number to print different patterns
    return 0;
}