#include<bits/stdc++.h>
using namespace std;


void sumof2bit(int n)
{
    // Initialize higher of two sets bits
    int x = 1;
    int sum1=0;
 
    // Keep reducing n for every number
    // with two set bits.
    while (n > 0)
    {
        // Consider all lower set bits for
        // current higher set bit
        int res=0;
        int y = 0;
        while (y < x)
        {
            // Print current number
            res=(1<<x)+(1<<y);
            cout << (1 << x) + (1 << y) << " ";
            sum1+=res;
 
            // If we have found n numbers
            n--;
            if (n == 0)
                return;
 
            // Consider next lower bit for current
            // higher bit.
            y++;
           
        }
       
        // Increment higher set bit
        x++;
    }
    cout<<sum1;
}

int main()
{
    sumof2bit(4);
 
    return 0;
}