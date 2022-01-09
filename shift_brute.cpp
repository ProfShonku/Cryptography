#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>   // for tolower()
#include<iterator>  //for back_inserter
#include<map>

using namespace std;
string input();
bool del(char c);
char low(char& c){return tolower(c);}
string decrypt_shift(string& s,int k);

int main()
{
    cout<<"SHIFT DECRYPTION"<<endl;
    string cip = input();
    int t;

    while(!cip.empty())
    {
        //cout<<"Enter the Key: ";
        int k;
        //cin>>k;
        for(k=1;k<26;k++)
        {
            string pla;
            pla = decrypt_shift(cip,k);
            cout<<"Key = "<<k<<" "<<"plaintext: "<<pla<<endl;
        }
        cip=input();
    }
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
string decrypt_shift(string& s,int k)
{
    const string ch = "abcdefghijklmnopqrstuvwxyz";
    map<char, char> shif;
    char c;
    const int L=ch.size();
    int i=0;
    k=(-k)%L;
    k=(k+L)%L;
    for(i=0;i<ch.size();i++){
        c = ch[i];
        shif[c] = ch[(i+k)%L];
    }
    string t;
    for(i=0;i<s.size();i++){
        c=s[i];
        t += shif[c];
    }
    return t;
}
