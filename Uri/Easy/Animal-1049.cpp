#include<bits/stdc++.h>
using namespace std;

int main(){
    string S1,S2,S3;
    cin>>S1>>S2>>S3;
    string concatenar = S1+S2+S3;
    if(concatenar == "vertebradomamiferoherbivoro")
        cout<<"vaca\n";
    if(concatenar == "vertebradomamiferoonivoro")
        cout<<"homem\n";
    if(concatenar == "vertebradoavecarnivoro")
        cout<<"aguia\n";
    if(concatenar == "vertebradoaveonivoro")
        cout<<"pomba\n";
    if(concatenar == "invertebradoinsetohematofago")
        cout<<"pulga\n";
    if(concatenar == "invertebradoinsetoherbivoro")
        cout<<"lagarta\n";
    if(concatenar == "invertebradoanelideohematofago")
        cout<<"sanguessuga\n";
    if(concatenar == "invertebradoanelideoonivoro")
        cout<<"minhoca\n";
}
