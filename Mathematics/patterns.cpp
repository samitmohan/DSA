#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Pattern Questions (Question 7)
// a
// *
// **
// ***
// ****
// *****

int pattern_a(int n)
{
    int id = 0, nst = 1;
    while (id <= n)
    {
        int cst = 1;
        while (cst < nst)
        {
            cout << "*";
            cst++;
        }
        cout << "\n";
        nst++;
        id++;
    }
    return 0;
}

// b
//     1
//     12
//     123
//     1234
//     12345

int pattern_b(int n)
{
    int id = 0, nst = 1;
    while (id <= n)
    {
        int cst = 1;
        while (cst < nst)
        {
            cout << cst;
            cst++;
        }
        cout << "\n";
        nst++;
        id++;
    }
    return 0;
}

// c
//          1
//        1 2 1
//      1 2 3 2 1
//    1 2 3 4 3 2 1
//  1 2 3 4 5 4 3 2 1

int pattern_c(int n)
{
    int id = 1, nst = 1, nsp = n - 1;
    while (id <= n)
    {
        int csp = 1;
        while (csp <= nsp)
        {
            cout << " ";
            csp++;
        }
        int cst = 1;
        while (cst <= nst)
        {
            // Condition
            if (cst <= (nst + 1) / 2)
            {
                cout << cst;
            }
            else
            {
                cout << nst - cst + 1; // logic
            }
            cst++;
        }
        cout << "\n";
        nst += 2;
        nsp--;
        id++;
    }
    return 0;
}

// d
//         1
//       2 3 2
//     3 4 5 4 3
//   4 5 6 7 6 5 4
// 5 6 7 8 9 8 7 6 5

// *DOUBT*
int pattern_d(int n)
{
    int id = 1, nst = 1, nsp = n - 1;
    while (id <= n)
    {
        int csp = 1;
        while (csp <= nsp)
        {
            cout << "  ";
            csp++;
        }
        int cst = nst; // 3,5,7,9
        // Condition
        while (cst <= ((2 * nst) - 1))
        {
            // Extra condition
            if (cst == (2 * nst - 1))
            {
                while (cst != (nst - 1))
                {
                    cout << cst << " ";
                    cst--;
                }
                break;
            }
            else
            {
                cout << cst << " ";
                cst++;
            }
        }
        cout << "\n";
        nst += 1;
        id++;
        nsp--;
    }
    return 0;
}

// e
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1

int pattern_e(int n)
{
    int id = 1, nst = 1, val;
    while (id <= n)
    {
        int cst = 1;
        val = 1;
        while (cst <= nst)
        {
            int one = 1;
            if (id == 1 || id == 2)
            {
                cout << one;
            }
            else
            {
                cout << val;
                if (cst <= nst / 2)
                {
                    val++;
                }
                else
                {
                    val--;
                }
            }
            cst++;
        }
        nst++;
        cout << endl;
        id++;
    }
    return 0;
}

// f
//           *                #1
//         * * *              #2
//       * * * * *            #3
//     * * * * * * *          #4
//    * * * * * * * *         #5
//     * * * * * * *          #6
//       * * * * *            #7
//         * * *              #8
//           *                #9

int pattern_f(int n)
{
    int id = 1, nst = 1, nsp = n - 1;
    while (id <= (2 * n) - 1)
    {
        // Spaces
        int csp = 1;
        while (csp <= nsp)
        {
            cout << " ";
            csp++;
        }
        // Stars
        int cst = 1;
        while (cst <= nst)
        {
            cout << "*";
            cst++;
        }
        cout << "\n";
        // Condition
        if (id < n)
        {
            nst += 2;
            nsp--;
        }
        else
        {
            nst -= 2;
            nsp++;
        }
        id++;
    }
    return 0;
}

// g

// *                 *
// * *             * *
// * * *         * * *
// * * * *     * * * *
// * * * * * * * * * *
// * * * *     * * * *
// * * *         * * *
// * *             * *
// *                 *

int pattern_g(int n)
{

    int id = 1, nst = 2 * n, nsp = 1;
    while (id <= n)
    {
        int cst = 1;
        while (cst <= nst)
        {
            if (id < cst)
                cout << " ";
            else
                cout << "*";
            if (id <= (2 * n - cst))
                cout << " ";
            else
                cout << "*";
            cst++;
        }
        cout << "\n";
        id++;
    }
    id = 2;

    while (id <= n)
    {
        int cst = 1;
        while (cst <= nst)
        {
            if (id > (n - cst + 1))
                cout << " ";
            else
                cout << "*";
            if ((id + n) > cst)
                cout << " ";
            else
                cout << "*";
            cst++;
        }
        cout << "\n";
        id++;
    }
    return 0;
}

// h
// * * * * * * * * *
// * * * *   * * * *
// * * *       * * *
// * *           * *
// *               *
// * *           * *
// * * *       * * *
// * * * *   * * * *
// * * * * * * * * *

int pattern_h(int n)
{
    int nst = 4;
    int nsp = 0;
    int id = 1;
    while (id <= n)
    {
        int cst = 1;
        while (cst <= nst)
        {
            cout << "*";
            cst++;
        }
        int csp = 1;
        while (csp <= nsp)
        {
            cout << " ";
            csp++;
        }
        if (id > 2 && id < n - 1)
        {
            cout << " ";
        }
        if (id == (n + 1) / 2)
        {
            cout << " ";
        }
        for (cst = 1; cst <= nst; cst++)
        {
            if (cst == 4)
            {
                cout << " ";
            }
            else
            {

                cout << "*";
            }
        }
        cout << endl;
        if (id <= n / 2)
        {
            nst--;
            nsp += 1;
        }
        else
        {
            nst++;
            nsp -= 1;
        }
        id++;
    }
    return 0;
}

// i
// 5 5 5 5 5 5 5 5 5
// 5 4 4 4 4 4 4 4 5
// 5 4 3 3 3 3 3 4 5
// 5 4 3 2 2 2 3 4 5
// 5 4 3 2 1 2 3 4 5
// 5 4 3 2 2 2 3 4 5
// 5 4 3 3 3 3 3 4 5
// 5 4 4 4 4 4 4 4 5
// 5 5 5 5 5 5 5 5 5

// Logic -> 9 numbers (2n-1)
int pattern_i(int n)
{
    for (int id = 0; id < ((2 * n) - 1); id++)
    {
        for (int nst = 0; nst < ((2 * n) - 1); nst++)
        {
            int m = min(id, nst);
            m = min(m, ((2 * n) - 1) - id - 1);
            m = min(m, ((2 * n) - 1) - nst - 1);
            cout << n - m;
        }
        cout << endl;
    }
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // pattern_a(5);
    // pattern_b(5);
    // pattern_c(5);
    // pattern_d(5);
    // pattern_e(5);
    // pattern_f(5);
    // pattern_g(5);
    // pattern_h(5);
    // pattern_i(5);
    return 0;
}