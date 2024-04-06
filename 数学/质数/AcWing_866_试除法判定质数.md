# 暴力解法
从质数的定理出发，暴力的解法就为枚举`2`到`a-1`的数，分别和`a`取模，如果模结果为0，则说明`a`不为质数。
该方法的时间复杂度为`O(n)`，超时。
下面是暴力解法的代码。
``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool is_prime(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i < a; i ++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        if (is_prime(a))
            cout << "Yes << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
```
# 优化
![原理](https://cdn.acwing.com/media/article/image/2024/04/06/407140_ec032fccf3-407140_b023bbfaef-A84B73CA-C181-4BC0-9F09-76C42E6CA1B3.jpeg) 
只枚举`d<=a/d`的d即可，将时间复杂度降低到`O(sqrt(n))`。
``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

bool check(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i <= a / i; i ++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cin >> n;
    while (n -- )
    {
        int a;
        cin >> a;
        if (check(a))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
```
