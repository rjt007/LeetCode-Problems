//https://leetcode.com/problems/unique-morse-code-words/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N).
int uniqueMorseRepresentations(vector<string> &words)
{
    vector<string> v = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    int n = words.size();
    unordered_set<string> s;
    for (int i = 0; i < n; i++)
    {
        int digit = 0;
        string store = "";
        for (int j = 0; j < words[i].length(); j++)
        {
            digit = words[i][j] - 'a';
            store += v[digit];
        }
        words[i] = store;
    }
    for (int i = 0; i < n; i++)
    {
        s.insert(words[i]);
    }
    return s.size();
}
int main()
{
    int n;
    cin>>n;
    vector<string>v;
    string val;
    for (int i = 0; i < v.size(); i++)
    {
        cin>>val;
        v.push_back(val);   
    }
    int ans = uniqueMorseRepresentations(v);
    cout<<"Result is: "<<ans<<endl;
    vector<char>v1={'a','e','i','o','u','A','E','I','O','U'};
    sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}