#include<iostream>
using namespace std;

int main()
{
    string msg,crc,encoded="";
    cout<<"Enter the message"<<endl;
    getline(cin,msg);
    cout<<"Enter the crc generator polynomial"<<endl;
    getline(cin,crc);
    int m=msg.length(),n=crc.length();
    encoded+=msg;
    for(int i=1;i<=n-1;i++)
    {
        encoded+='0';
    }
    for(int i=0;i<=(encoded.length()-n);)
    {
        for(int j=0;j<n;j++)
        {
            encoded[i+j]=encoded[i+j]==crc[j]?'0':'1';
        }
        for( ;i<encoded.length() && encoded[i]!='1';i++);
    }
    
    //receiver
    for(char i:encoded.substr(encoded.length()-crc.length()))
    {
        if(i!='0')
        {
            cout<<"Error in communication...";
            return 0;
        }   
        
    }
    cout<<"No eroor..."<<endl;
    return 0;
}