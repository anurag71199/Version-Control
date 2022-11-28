#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
void swapvec(vector<int> &a, vector<int> &b)
{
    int temp;
    for (int i = 0; i < a.size(); i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
vector<int> cal_SA(const string &s)
{
    int n = s.size();
    vector<int> sfvec(2 * n), res(n), arr(n);
    vector<int> arr2(n), restemp(n), counter(n + 1);
    for (int i = 0; i < n; ++i)
        sfvec[i] = sfvec[i + n] = i;

    for (int i = 0; i < n; i++)
    {
        res[i] = i;
    }

    stable_sort(res.begin(), res.end(), [&](int i, int j)
                { return s[i] < s[j]; });

    arr[res[0]] = 0;
    for (int i = 1; i < n; ++i)
        arr[res[i]] = arr[res[i - 1]] + (s[res[i]] != s[res[i - 1]]);

    
    for (int k = 1; k < n; k <<= 1)
    {
        for (int &x : res)
            x = sfvec[x - k + n];

        for (int j = 0; j <= n; j++)
        {
            counter[j] = 0;
        }

        for (int x : arr)
            counter[x + 1]++;

        for (int j = 1; j <= n; j++)
        {
            counter[j] = counter[j] + counter[j - 1];
        }

        for (int x : res)
            restemp[counter[arr[x]]++] = x;
        swapvec(res, restemp);

        arr2[res[0]] = 0;
        for (int i = 1; i < n; ++i)
        {
            int l = res[i - 1], r = res[i];
            arr2[r] = arr2[l] + (arr[l] != arr[r] || arr[sfvec[l + k]] != arr[sfvec[r + k]]);
        }
        swapvec(arr, arr2);
    }

    return res;
}

int main()
{
    string s, news = "";
    cin >> s;
    news = s + s;
    news += '$';

    vector<int> sarr = cal_SA(news);
    vector<int> ansvec;
    for (int i = 1; i < sarr.size(); i++)
    {
        ansvec.push_back(sarr[i]);
    }
    vector<int> temp(news.size() - 1, 0);
    for (int i = 0; i < ansvec.size(); i++)
    {
        temp[ansvec[i]] = i;
    }
    int min = temp[0];
    int idx = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (min > temp[i])
        {
            min = temp[i];
            idx = i;
        }
    }
    string suffix = news.substr(idx, s.size());
    cout << suffix;
    return 0;
}