#include<iostream>
#include<cstdio>
#include<bitset>
#include<vector>
#include<cmath>

using namespace std;

//const unsigned long long LIMIT = 10000000000000000;
const unsigned long long LIMIT = 10000000;
bitset<LIMIT>& is_not_prime = *(new bitset<LIMIT>());

void make_sieve(){
    is_not_prime[0] = true;
    is_not_prime[1] = false;
    for(unsigned long long i=2;i<LIMIT;i++){
        unsigned long long j = i+i;
        while(j<LIMIT){
            is_not_prime[j-1] = true;
            j = j + i;
        }
    }
}

unsigned long long convert(string s, int base){
    unsigned long long num = 0;
    unsigned long long d = 1;

    for(int i=s.size()-1;i>=0;i--){
        if(s[i] == '1'){
            num = num + d;
        }

        d = d*2;
    }

    return num;
}

unsigned long long find_factor(unsigned long long num) {
    for(int i=2;i<=sqrt(num);i++){
        if(num%i == 0)
            return i;
    }

    return -1;
}

string convert_to_bin(unsigned long long num){
    string s;
    while(num>0){
        char c = num%2 + '0';
        s.push_back(c);
        num = num/2;
    }

    return s;
}

int main(){
    //freopen("outputCsmall.txt", "w", stdout);
    //freopen("B-large.in", "r", stdin);
    int n, j;
    cin>>n>>j;
    make_sieve();
    vector<string> ans_str;
    vector< vector <unsigned long long> > ans_factors;

    string s = "100001";

    while(1){
        int base=10;
        unsigned long long num = convert(s, base);
        vector<unsigned long long> factors;

        if(is_not_prime[num]){
            factors.push_back(find_factor(num));
            base--;
            while(base>1){
                num = convert(s, base);
                if(is_not_prime[num-1]){
                    //find factor
                    factors.push_back(find_factor(num));
                }
                else{
                    break;
                }

                base--;
            }

            if(base==1){
                //Found 1
                ans_str.push_back(convert_to_bin(num));
                ans_factors.push_back(factors);
                if(ans_str.size() == j)
                    break;
            }
        }

        num = num + 1;
        cout<<num<<endl;
    }

    for(int i=0;i<ans_str.size();i++){
        cout<<ans_str[i]<<" ";
        for(int k=0;k<ans_factors[i].size();k++){
            cout<<"Hello";
            //cout<<ans_factors[k];
        }
        cout<<endl;
    }

    delete &is_not_prime;
    return 0;
}
