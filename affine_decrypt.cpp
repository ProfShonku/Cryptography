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
string decrypt_affine(string& s,int a,int b);
int inv(int a, int m);

int main()
{
    string cip = input();
    cout<<"Enter a, b respectively: ";
    int a,b;
    cin>>a>>b;
    string pla;
    pla = decrypt_affine(cip,a,b);
    cout<<"The plaintext is : "<<endl;
    cout<<pla<<endl;
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
string decrypt_affine(string& s,int a,int b)
{
    const string ch = "abcdefghijklmnopqrstuvwxyz";
    map<char, char> shif;
    char c;
    const int L=ch.size();
    int i=0;
    a=inv(a,L);
    cout<<"a inverse is = "<<a<<endl;
    for(i=0;i<ch.size();i++){
        c = ch[i];
        shif[c] = ch[((a*(i-b)%L)+L)%L];
    }
    string t;
    for(i=0;i<s.size();i++){
        c=s[i];
        t += shif[c];
    }
    return t;
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
        throw domain_error("Caution: a is not invertable!!");
}
