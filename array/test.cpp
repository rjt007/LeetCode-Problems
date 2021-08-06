#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int id;
    string name;
    int age;
    virtual int func(int x, int y)
    {
        return x+y;
    }
/*     int func(string s, string s1)
    {
        int l1 = s.length();
        int l2 = s1.length();
        return l1+l2;
    } */
};
class nodec:public node
{
    public:
    int size;
    int func(int x, int y)
    {
        cout<<"Child fn called";
        return 0;
    }
};
int main()
{
    node* data;
    nodec data2;
    data = &data2;
    data2.size=25;
    data->func(8,10);
    cout<<endl;
    data->age=20;
    data->name="rajat";
    data->id=1;
    data->func(5,10);
    cout<<data->id<<" "<<data->name<<" "<<data->age<<" "<<" "<<endl;
    return 0;
}