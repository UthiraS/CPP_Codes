#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

std::vector<int> a{-4, 5, 2, 1, 5, 2 , -10};
int main()
{
    unsigned long numComb = pow(2, a.size());

    std::vector<int> sumComb;
    
    for(unsigned long i=0; i<numComb; i++)
    {
        int sum = 0;
        for(unsigned long j=0; j<a.size(); j++)
        {
            if( (1<<j) & i)
            {
                sum += a[j];
            }
        }
        sumComb.push_back(sum);
    }

    std::sort(sumComb.begin(), sumComb.end(), std::greater<int>());

    for(auto val: sumComb)
    {
        if (val%2 == 0)
        {
            cout<<val;
            break;
        }
    }
}