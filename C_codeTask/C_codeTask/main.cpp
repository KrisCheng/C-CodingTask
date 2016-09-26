//
//  main.cpp
//  C_codeTask
//
//  Created by Cheng Peng on 9/26/16.
//  Copyright © 2016 Cheng Peng. All rights reserved.
//

#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

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
    
    return 0;
}
