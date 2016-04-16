#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
    freopen("A1-large-2.txt", "w", stdout);
    freopen("B-large.in", "r", stdin);
    int t;
    cin>>t;
    int x=1;
    while(x<=t) {
        int n;
        cin>>n;
        int h;
        int a[2500];
        for(int i=0;i<2500;i++)
            a[i] = 0;

        for(int i=0;i<(n*(2*n-1));i++) {
            cin>>h;
            a[h-1]++;
        }
        vector<int> elem;
        for(int i=0;i<2500;i++){
            if(a[i]%2 != 0)
                elem.push_back(i+1);
        }
        cout<<"Case #"<<x<<": ";
        sort(elem.begin(), elem.end());
        for(int i=0;i<elem.size();i++)
            cout<<elem[i]<<" ";
        cout<<endl;
        x++;
    }
    return 0;
}

