#include <bits/stdc++.h>
using namespace std;

int findDigits(int n)
{
    if (n < 0)
        return 0;

    if (n <= 1)
        return 1;

    double digits = 0;
    for (int i=2; i<=n; i++)
        digits += log10(i);

    return floor(digits) + 1;
}

int main()
{
    cout << findDigits(1000) << endl;
    cout << findDigits(5) << endl;
    cout << findDigits(10) << endl;
    cout << findDigits(120) << endl;
    return 0;
}
