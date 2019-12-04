#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)cout<<"Bir Sreshtho Captain Mohiuddin Jahangir: ";
        else if(n==2)cout<<"Bir Sreshtho Sepahi Hamidur Rahman: ";
        else if(n==3)cout<<"Bir Sreshtho Sepahi Muhammad Mustafa: ";
        else if(n==4)cout<<"Bir Sreshtho Engine Room Artificer Mohammad Ruhul Amin: ";
        else if(n==5)cout<<"Bir Sreshtho Flight Lieutenant Matiur Rahman: ";
        else if(n==6)cout<<"Bir Sreshtho Lance Naik Munshi Abdur Rouf: ";
        else cout<<"Bir Sreshtho Lance Naik Noor Mohammad Sheikh: ";
        cout<<"Amra Tomay Vulbo Na.\n";
    }
    return 0;
}
