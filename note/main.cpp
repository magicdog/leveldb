#include <iostream>


using namespace std;

int main() {
    char *p = new char[3];
    p[0]='1';
    p[1]='1';
    p[2] = '2';
    cout << p  << endl;

    cout << reinterpret_cast<uintptr_t> (p)<< endl;
    cout << (reinterpret_cast<uintptr_t> (p) & 0x3 )<< endl;
}
