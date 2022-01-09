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
string encrypt_shift(string& s,int k);
//string decrypt_shift(string& s,int k);

int main()
{
    string s = input();
    cout<<"Enter the number of shift operation: ";
    int k;
    cin>>k;
    string cip;
    cip = encrypt_shift(s,k);
    cout<<endl<<"The ciphertext is: "<<endl;
    cout<<cip<<endl;
    /*
    cout<<"The plaintext is : "<<endl;
    string pla;
    pla = decrypt_shift(cip,k);
    cout<<pla<<endl;
    if(s==pla){cout<<"decryption is right.";}
    */
    return 0;
}
string input()
{
    string s,t;

    cout<<"Enter the text: "<<endl;
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
string encrypt_shift(string& s,int k)
{
    const string ch = "abcdefghijklmnopqrstuvwxyz";
    map<char, char> shif;
    char c;
    int i=0;
    for(i=0;i<ch.size();i++){
        c = ch[i];
        shif[c] = ch[(i+k)%ch.size()];
    }
    string t;
    for(i=0;i<s.size();i++){
        c=s[i];
        t += shif[c];
    }
    return t;
}
/*
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
*/
