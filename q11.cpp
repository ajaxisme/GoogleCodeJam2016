#include<iostream>
#include<deque>
#include<cstdio>

using namespace std;

int main() {
    freopen("A1-1.txt", "w", stdout);
    freopen("A1-large.in", "r", stdin);
    int t;
    cin>>t;
    int x=1;
    while(x<=t) {
        string s;
        cin>>s;
        deque<char> last_word;
        last_word.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i] >= last_word.front()){
                last_word.push_front(s[i]);
            }
            else {
                last_word.push_back(s[i]);
            }
        }

        cout<<"Case #"<<x<<": ";
        for(deque<char>::iterator it=last_word.begin(); it!=last_word.end();it++)
            cout<<*it;

        cout<<endl;
        x++;
    }
    return 0;
}
