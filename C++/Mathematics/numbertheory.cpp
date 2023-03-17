#include <iostream>
#include <vector>

#define ll long long
using namespace std;

// Checking if number is prime or not in O(rootN) time

bool prime(int n)
{
    if (n < 2)
        return false;
    // 2- i^2, if n divides i or not.
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int factors_1(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            // half
            n /= x;
        }
    }
    //. If number divisible by itself
    if (n > 1)
    {
        f.push_back(n);
    }
    return 1;
}

// Printing factors in O(logn) time.

int factors_2(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x; // half
        }
    }
    // If number is divisible by itself.
    if (n > 1)
        f.push_back(n);
    return 1;
}

// Sieve of Eratosthenes (O(nlogn)) // prime numbers in a range.

// If n is prime then condition :  (1 -> root N) have no factors of N
void primeNumber(int n)
{
    // Assuming all numbers are marked prime (TRUE)
    bool prime[n + 1]; // n+1 bcs count starts from 0.
    memset(prime, true, sizeof(prime));
    // till i = root(N) or i^2 = N, mark all false.
    for (int i = 2; i * i <= n; i++)
    {
        // if prime is not touched, then it is a prime.
        if (prime[i] == true) // 2 is true
        {
            /* touch all multiples of p automatically and mark them false
            4,6,8,10... are false (now 2 can / these numbers so not prime.) */
            for (int j = 2 * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    // Print all prime numbers
    for (int i = 2; i <= n; i++)
        if (prime[i])
            cout << i << " ";
}

// Euclid common divisor.
// gcd -> greatest number that divides both a and b (HCF)
// LCM(a,b) -> a*b / gcd(a,b)

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

/* gcd(13,8) -> gcd(8,5) -> gcd(5, 3) -> gcd(3, 2) -> gcd(2, 1) -> gcd(1,0)
b = 0, return 1; */

// Modular Exponentiation
// a^b
int power(int a, int b)
{
    int result = 1;
    while (b != 0)
    {
        // if b is odd then multiply a with result.
        if ((b & 1) != 0)
        {
            result *= a;
        }
        a *= a;     // 4
        b = b >> 1; // 1
    }
    return result;
}
// O(root K)
// A factorial problem (by coding blocks)

void factorial_problem()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, res = 0;

        cin >> n >> k;

        ll curPow = k;
        //calculating no of times k is present in n
        while (curPow <= n)
        {
            ll count = n / curPow;
            res += count;
            curPow *= k;
        }

        cout << res << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
