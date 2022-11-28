#include <bits/stdc++.h>
using namespace std;
 //dcabcadcabca
int main()
{
    // string s = "banana";
    string s;
    cin>>s;
    string orig = s;
    s = s+s;
    int n = s.length();
    map<string, int> Map;
    int suffix[n];
 
    // Mapping string with its index of
    // it's last letter.
    string sub = "";
    for (int i = n - 1; i >= 0; i--) {
        sub = s[i] + sub;
        Map[sub] = i;
    }
 
    // Storing all values of map
    // in suffix array.
    int j = 0;
    for (auto x : Map) {
        suffix[j] = x.second;
        j++;
    }
 
    // printing suffix array.
    // cout << "Suffix array for banana is" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << suffix[i] << " ";
    // }
    // cout << endl;
    // cout<<s<<endl;
    long long int min = suffix[0];
    for(long long unsigned int i=1;i<orig.size();i++){
        if(min>suffix[i]){
            min = suffix[i];
            // cout<<"new min = "<<min<<"\n";
        }
    }
    // cout<<min<<"\n";
    // cout<<orig.size()<<"\n";
    long long int diff = min-orig.size();
    // cout<<diff<<endl;
    if(diff < 0)
    cout<<s.substr(min,orig.size());
    else
    cout<<s.substr(diff,orig.size());
    return 0;
}