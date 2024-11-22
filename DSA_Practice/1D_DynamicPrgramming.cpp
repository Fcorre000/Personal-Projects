#include <iostream>
#include <unordered_map>
using namespace std;
//use fibonacci sequence as example for functions
//f(0) = 0, f(1) = 1
//f(n) = f(n-1) + f(n-2)

//Brute Force
int BruteForceFib(int n){
    if(n <= 1){
        return n;
    }
    return BruteForceFib(n - 1) + BruteForceFib(n - 2);
}

//Memoization
//uses a hashmap to store sub problems, so fib(n) isn't calculated every iteration
//making the TC 0(n)
int memoization(int n, unordered_map<int, int> *cache){
    if(n <= 1){
        return n;
    }
    if(cache -> count(n)){
        return (*cache)[n];
    }
    (*cache)[n] = memoization(n - 1, cache) + memoization(n - 2, cache);
    return (*cache)[n];
}

//Bottom Up or "True Dynamic Programming"
int dp(int n){
    if(n < 2){
        return n;
    }

    int dp[] = {0, 1};
    int i = 2;
    while(i <= n){
        int tmp = dp[1];
        dp[1] = dp[0] + dp[1];
        dp[0] = tmp;
        i++;
    }
    return dp[1];
}

int main() {
    int n = 5; // Example value for Fibonacci sequence
    unordered_map<int, int> cache;

    // Compute Fibonacci using memoization
    int result = memoization(n, &cache);
    cout << "Fibonacci of " << n << " is " << result << endl;

    return 0;
}