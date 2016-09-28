//  main.cpp
//  C_codeTask
//  Created by Cheng Peng on 9/26/16.
//  Copyright © 2016 Cheng Peng. All rights reserved.

/*
 This class is used to calculate all the numbers between 1 and 10,000,000 that are the product of two distinct primes.
 The space complexity of this method is O(n), the time complexity of this method is also O(n).
 
 */
#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

const int MAXN=5000001;
int prime[MAXN];//保存素数
bool vis[MAXN];//初始化
int Prime(int n)
{
    int cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<n;i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            printf("%zd\n", i);//打印素数
        }
        for(int j=0;j<cnt&&i*prime[j]<n;j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)//关键
            {
                break;
            }
        }
    }
    return cnt;//返回小于n的素数的个数
}

bool IsPrime(unsigned n)
{
    if (n<2)
    {//小于2的数即不是合数也不是素数
        throw 0;
    }
    for(unsigned i=2;i<n/2+1;++i)
    { // 和比它的一半小数相除，如果都除不尽，证明素数
        if ( 0 == n % i )
        { // 除尽了，合数
            return false;
        }
    }
    return true; // 都没除尽，素数
}

/*the function to get all the primes until n*/
vector<int> getPrimes(int n){
    vector<int> primes = {};
    for(int i = 2; i < n/2; i ++){
        if(IsPrime(i)){
            primes.push_back(i);
        }
    }
    return primes;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    /*
     int max = 1e3;
     vector<int> primes = getPrimes(max/2);
     printf("%zd\n", primes.size());
     for(int o = 0; o < primes.size(); o++){
     //    printf("%zd\n", primes[o]);
     }
     printf("\n\n***************\n\n");
     vector<int> biprimes;
     for (int i = 0; i < primes.size() && primes[i] < sqrt(max); ++i) {
     for (int j = i; j < primes.size() && primes[i] * primes[j] < max; ++j) {
     if(primes[i] == primes[j]){
     continue;
     }
     biprimes.push_back(primes[i] * primes[j]);
     printf("%zd = %zd * %zd\n", primes[i] * primes[j],primes[i],primes[j]);
     }
     }
     printf("%zd\n", biprimes.size());
     */
    Prime(5000000);
    return 0;
}
