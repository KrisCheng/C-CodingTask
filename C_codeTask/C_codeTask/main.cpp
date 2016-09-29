//  main.cpp
//  C_codeTask
//  Created by Cheng Peng on 9/26/16.
//  Copyright © 2016 Cheng Peng. All rights reserved.

/*
 This class is used to calculate all the numbers between 1 and 10,000,000 that are the product of two distinct primes(call semiprimes for short,but remove those numbers that producted by two same numbers).
 The space complexity of this method is O(n), the time complexity of this method is also O(n).
 */

#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

const int MAXN=1e7;
bool vis[MAXN/2];//the array for judge whether a number is a prime.

/*this function is to get all the primes to n, which is based on Euler function.*/
vector<int> getPrimes(int n)
{
    vector<int> primes;
    int cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<n;i++)
    {
        if(!vis[i])
        {
            cnt++;
            primes.push_back(i);//store the primes.
        }
        for(int j=0;j<cnt&&i*primes[j]<n;j++)
        {
            vis[i*primes[j]]=1;
            if(i%primes[j]==0)//key process,which means i*primes[j+1] is filtered by N*primes[j],no filter anymore.
            {
                break;
            }
        }
    }
    return primes;//return all the primes from 2 to n.
}

int main() {
    //1.get all the primes from 2 to 5e6.
    vector<int> primes = getPrimes(MAXN/2);
    //2.get all the semiprimes from 2 to 1e7.
    vector<vector<int>> semiprimes;
    for (int i = 0; i < primes.size() && primes[i] < sqrt(MAXN); ++i)
    {
        for (int j = i+1; j < primes.size() && primes[i] * primes[j] < MAXN; ++j)
            {
                semiprimes.push_back({primes[i] * primes[j],primes[i],primes[j]});
            }
    }
    //3. sort the semiprimes.
    sort(semiprimes.begin(),semiprimes.end());
    for(int i = 0; i < semiprimes.size(); i ++)
    {
       cout<<semiprimes[i][0]<<'='<<semiprimes[i][1]<<'*'<<semiprimes[i][2]<<'\n';
    }
    cout<<"count of all the numbers:"<<semiprimes.size()+'\n';
    return 0;
}
