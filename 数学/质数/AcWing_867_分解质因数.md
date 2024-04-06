x有两种情况
> 1. x 为质数，则结果为 x 的 1 次方。
> 2. x 为合数，则可以分解为多个质因数相乘。

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int n;
void divide(int x)
{
    for (int i = 2; i <= x / i; i ++)
    {
        // 此处满足条件的i一定为质数
        // 假设i不为质数为合数，则i可以分解为多个质因数相乘，且质因数小于i，因为for循环是从小到大枚举i，所以先枚举了i的质因数，才到i
        // 但枚举到比i小的质因数时，会将x更新，使得x整除到不能再整除比i小的质因数，所以也定不能和i整除，所以此处的i一定是不能被2 ` i-1中的数整除的数，则i定为质数
        // 其实有点筛质数的思想
        if (x % i == 0)
        {
            int c = 0;
            while (x % i == 0)
            {
                x /= i;
                c ++;
            }
            cout << i << ' ' << c << endl;
        }
    }
    if (x > 1)
        cout << x << ' ' << 1 << endl;
    cout << endl;
}

int main()
{
    
    cin >> n;
    while (n --)
    {
        int a;
        cin >> a;
        divide(a);
    }
    return 0;
}
```
