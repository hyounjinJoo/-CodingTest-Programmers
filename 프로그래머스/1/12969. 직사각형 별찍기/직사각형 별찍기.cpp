#include <iostream>

using namespace std;

int main(void) {
    int rowMax;
    int columnMax;
    cin >> columnMax >> rowMax;
    for(int rowIter = 0; rowIter < rowMax; ++rowIter)
    {
        for(int columnIter = 0; columnIter < columnMax; ++columnIter)
        {
            cout << '*';
        }
        
        cout << '\n';
    }
    
    return 0;
}