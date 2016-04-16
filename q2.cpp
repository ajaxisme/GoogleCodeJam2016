#include<iostream>
#include<cstdio>

using namespace std;

int find_last_index(string s){
    for(int i=s.size()-1;i>=0;i--){
        if(s[i] == '-')
            return i;
    }

    return -1;
}
int main(){
    freopen("outputBlarge.txt", "w", stdout);
    freopen("B-large.in", "r", stdin);
    int t;
    cin>>t;
    int x=0;
    while(t--){
        string s;
        cin>>s;
        int flips = 0;

        while(1){
            int ind = find_last_index(s);
            if(ind == -1)
                break;
            for(int i=0;i<=ind;i++){
                if(s[i] == '+')
                    s[i] = '-';
                else
                    s[i] = '+';
            }
            flips++;
        }
        cout<<"Case #"<<x+1<<": "<<flips<<endl;
        x++;
    }
    return 0;
}
