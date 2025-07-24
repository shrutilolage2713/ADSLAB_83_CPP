/*

Assignment by Shruti Lolage PRN UCS23F1083.

Problem 3: Implement a problem of smallest number with atleast number of trailing zeros in factorial.

Statement: Given a number n the task is to find the smallest no. whoose factorial contains atleast n trailing zeros.

Approch: Applying the Binary Search algorithm to find the trailing zeros.

Input: n=3

Output: 15

*/

#include <iostream>
using namespace std;

// Function to count trailing zeros in x!
int countTrailingZeros(int x) 
{
    int count = 0;
    for (int i = 5; x / i >= 1; i *= 5)
        count += x / i;
    return count;
}

// Binary Search to find smallest number whose factorial has at least n trailing zeros
int findNumberWithTrailingZeros(int n)
{
    int low = 0, high = 5 * n;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int zeros = countTrailingZeros(mid);

        if (zeros >= n) 
        {
            ans = mid;          // Possible answer
            high = mid - 1;     // Try smaller number
        } 
        else 
        {
            low = mid + 1;      // Try larger number
        }
    }

    return ans;
}

int main() 
{
    int n;
    cout << "Enter number of trailing zeros: ";
    cin >> n;

    int result = findNumberWithTrailingZeros(n);
    cout << "Smallest number whose factorial has at least " << n << " trailing zeros is: " << result << endl;

    return 0;
}
