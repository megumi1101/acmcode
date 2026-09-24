#include <bits/stdc++.h>
using namespace std;
int T, n, m;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        printf("%d ", n);
        for (int i = 1; i <= min(m, n - 1); i++)
            printf("%d ", i);
        for (int i = n - 1; i >= m + 1; i--)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}