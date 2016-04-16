#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

bool in_vector(vector<int> s, int n) {
    for(int i=0;i<s.size();i++){
        if(s[i]==n)
            return true;
    }

    return false;
}

int another_element(int a[], int cur, int prev, int n){
    cout<<"another";
    for(int i=0;i<n;i++){
        if(a[i] == cur && cur!=prev)
            return i;
    }

    return -1;
}
int start_assigning(int a[], int present, int n){
    vector<int> s;
    s.push_back(present);

    int count = 1;

    while(1){
        if(in_vector(s, a[present])){
            int another = another_element(a, a[present], present,n);
            if(another != -1){
                s.push_back(a[another]);
                present = a[another];
                count++;
                continue;
            }
            else
                break;
        }
        s.push_back(a[present]);
        present = a[present];
        count++;
    }

    if(a[present] == s[0])
        count++;

    return count-1;
}

int main() {
    //freopen("A1-1.txt", "w", stdout);
    //freopen("A1-large.in", "r", stdin);
    int t;
    cin>>t;
    int x=1;
    while(x<=t) {
        int n;
        cin>>n;
        int a[1000];
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]--;
        }

        int max = -1;
        for(int i=0;i<n;i++) {
            int val = start_assigning(a, i, n);
            if(val>max)
                max = val;
        }

        cout<<max;
        x++;
    }
    return 0;
}


