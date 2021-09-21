//Tower of hanoi using recursion.O(1)
#include<bits/stdc++.h>
using namespace std;

void towerofhanoi(int n, int s,int d,int h)
{
    if(n==1)
    {
        cout<<"Moving plate " <<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    towerofhanoi(n-1,s,h,d);
    cout << "Moving plate " << n << " from " << s << " to " << d << endl;
    towerofhanoi(n-1,h,d,s);
}
int main()
{
    int n,s,d,h;
    //s->1,d->2,h->3;
    cout<<"Enter no of plates, source, destination and helper respectively: ";
    cin>>n>>s>>d>>h;
    towerofhanoi(n,s,d,h);
    return 0;
}