#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>   // for tolower()
#include<iterator>  //for back_inserter
#include<map>
#include<stdexcept>

using namespace std;
string input();
bool del(char c);
char low(char& c){return tolower(c);}
void decrypt_affine(string& s);
int inv(int a, int m);

int main()
{
    string cip = input();
    decrypt_affine(cip);
    return 0;
}
string input()
{
    string s,t;

    cout<<"Enter the ciphertext: "<<endl;
    while(getline(cin,t)){
        t.erase(remove_if(t.begin(),t.end(),del), t.end());
        transform(t.begin(), t.end(), back_inserter(s), low);
    }
    cin.clear();
    return s;
}
bool del(char c)
{
        return !isalpha(c);
}
void decrypt_affine(string& s)
{
    const string ch = "abcdefghijklmnopqrstuvwxyz";
    map<char, char> shif;
    char c;
    const int L=ch.size();
    int i=0;
    int k,a,b;
    for(k=1;k<L;k++){
        a =inv(k,L);
        if(a!=0){
            for(b=0;b<L;b++){
                for(i=0;i<ch.size();i++){
                    c = ch[i];
                    shif[c] = ch[((a*(i-b)%L)+L)%L];
                }
                string t;
                for(i=0;i<s.size();i++){
                    c=s[i];
                    t += shif[c];
                }
                cout<<"a= "<<k<<"b= "<<b<<"plaintext = "<<t<<endl;
            }
        }

    }
}
int inv(int a, int m)
{
    int i;
    for(i=1;i<m;i++){
        if(((a*i)%m+m)%m == 1)
        break;
    }
    if(i!=m)
        return i;
    else
        return 0;
}
