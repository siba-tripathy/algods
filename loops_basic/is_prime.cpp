
// GFG : AC : Easy : https://www.geeksforgeeks.org/problems/prime-number2314/1

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n == 1)
        {
            return false;
        }
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
