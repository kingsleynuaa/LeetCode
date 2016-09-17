class Solution {
public:
//Sieve of Eratosthenes，算法时间复杂度nloglogn
//https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    int countPrimes(int n) {
        vector<bool> prime(n,true);
        prime[0] = false;
        prime[1] = false;
        for(int i = 0; i < sqrt(n); i++)
            if(prime[i])
            {
                for(int j = i*i; j < n; j += i)
                    prime[j] = false;
            }
        return count(prime.begin(),prime.end(),true);
        
    }
};
