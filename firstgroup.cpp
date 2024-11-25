# include <iostream>
using namespace std;


class Addition {
public:
    int x;
    int y;

    int calculateSum() {
        return x + 2 * y - 7;
    }
};


int main() {
        Addition add;

    cout << "Enter x: ";
    cin >> add.x;
    cout << "Enter y: ";
    cin >> add.y;

int sum = add.calculateSum();
    cout << "Sum: " << sum << endl;


    return 0;
}

