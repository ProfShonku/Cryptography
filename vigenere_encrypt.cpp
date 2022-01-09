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
string encrypt_vigenere(string& s, string& key);
string decrypt_vigenere(string& s, string& key);
//string decrypt_shift(string& s,int k);

int main()
{
    string s = input();
    cout<<"Enter the key: ";
    string t,k;
    cin>>t;
    transform(t.begin(), t.end(), back_inserter(k), low);
    string cip;
    cip = encrypt_vigenere(s,k);
    cout<<endl<<"The ciphertext is: "<<endl;
    cout<<cip<<endl;
    cout<<"The plaintext is : "<<endl;
    string pla;
    pla = decrypt_vigenere(cip,k);
    cout<<pla<<endl;
    if(s==pla){cout<<"decryption is right.";}
    return 0;
}
string input()
{
    string s,t;

    cout<<"Enter the plaintext: "<<endl;
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
string encrypt_vigenere(string& s, string& key)
{
    const string ch = "abcdefghijklmnopqrstuvwxyz";
    map<char, int> shif;
    char c;
    int i=0,L=ch.size();
    for(i=0;i<ch.size();i++){
        c = ch[i];
        shif[c] = i;
    }
    string t;
    int j,M = key.size();
    for(i=0;i<s.size();i++){
        c=s[i];
        j=key[i%M];
        t+= ch[((shif[c]+shif[j])%L+L)%L];
    }
    return t;
}
string decrypt_vigenere(string& s, string& key)
{
    const string ch = "abcdefghijklmnopqrstuvwxyz";
    map<char, int> shif;
    char c;
    int i=0,L=ch.size();
    for(i=0;i<ch.size();i++){
        c = ch[i];
        shif[c] = i;
    }
    string t;
    int j,M = key.size();
    for(i=0;i<s.size();i++){
        c=s[i];
        j=key[i%M];
        t+= ch[((shif[c]-shif[j])%L+L)%L];
    }
    return t;
}
