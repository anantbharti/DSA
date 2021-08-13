//dp approach O(n*n) time with O(n*n) space
long long Catalan(long long A) 
{
    long long dp[A+1]={0};//catalan numbers
    dp[0]=dp[1]=1;// base case of catalan numbers
    
    long long M=1e9+7;
    for(int i=2;i<=A;i++)
    for(int j=0;j<i;j++)
    dp[i]=(dp[i]+(dp[j]*dp[i-j-1])%M)%M;
    
    return dp[A];
}

//binomial coefficient approach O(n) time with O(1) space
long long Catalan(long long A)
{
    long long n=2*A,k=A;
    long long res = 1;
    for (int i = 0; i < k; ++i) 
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res/(A+1);
}

