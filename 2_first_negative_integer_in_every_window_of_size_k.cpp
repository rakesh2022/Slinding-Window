https : // practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

        typedef long long ll;
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    vector<ll> res;
    queue<ll> q;
    ll i = 0, j = 0;
    while (j < N)
    {
        if (A[j] < 0)
            q.push(A[j]);
        if (j - i + 1 == K)
        {
            if (q.empty())
                res.push_back(0);
            else
            {
                res.push_back(q.front());
                if (A[i] == q.front())
                    q.pop();
            }
            i++;
        }
        j++;
    }
    return res;
}