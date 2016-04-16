#include<iostream>
#include<bitset>
#include<cstdio>

using namespace std;

bool covered(bitset<10> digits){
    for(int i=0;i<digits.size();i++){
        if(digits[i] == false)
            return false;
    }

    return true;
}

int main(){
    freopen("output.txt", "w", stdout);
    freopen("A-large.in", "r", stdin);
    int t;
    cin>>t;
    int x=0;
    while(x<t){
        int n;
        cin>>n;
        bool done = false;
        int digit;

        bitset<10> digits;

        if(n==0)
            cout<<"Case #"<<x+1<<": INSOMNIA"<<endl;
        else {
            int i = 1;
            while(!covered(digits)){
                int temp = n*i;
                while(temp>0){
                    digit = temp%10;
                    digits[digit] = true;
                    temp = temp/10;
                }
                i++;
            }
            i--;
            cout<<"Case #"<<x+1<<": "<<n*i<<endl;
        }
        x++;
    }
    return 0;
}
