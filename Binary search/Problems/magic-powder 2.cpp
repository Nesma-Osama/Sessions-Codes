#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int N = 1e5 + 5;
int need[N], have[N];
int n, k;

bool ok(int noOfCakes)
{
    ll magicPowder = k;

    for (int i = 0; i < n; i++)
    {
        ll extraNeed = (ll)need[i] * noOfCakes - have[i];

        if (extraNeed < 0) // we have enough
            continue;

        magicPowder -= extraNeed; // remove the extra need from the magic powder
        if (magicPowder < 0)      // magic powder isn't enough
            return false;
    }
    return true;
}

int main()
{
    IO;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> need[i];
    for (int i = 0; i < n; i++)
        cin >> have[i];

    ll left = 0, right = 2e9, res = 0;

    while (left <= right)
    {
        // ll mid = (left + right) / 2;
        ll mid = left + (right - left) / 2;
        if (ok(mid))
        {
            left = mid + 1;
            res = mid;
        }
        else
            right = mid - 1;
    }

    cout << res << endl;
    return 0;
}