#include <iostream>
using namespace std;

int main()
{
    int n = 3;

    for(int i = 1; i <= n; i++)
    {
        // Left side
        for(int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // Spaces
        for(int j = 1; j <= 2*(n-i); j++)
        {
            cout << " ";
        }

        // Right side
        for(int j = i; j >= 1; j--)
        {
            if(i == n && j == i)  // avoid repeating middle digit
                continue;
            cout << j;
        }

        cout << endl;
    }

    return 0;
}