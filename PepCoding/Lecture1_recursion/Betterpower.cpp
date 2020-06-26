//Power of a number x ^ n

#include<iostream>
using namespace std;

int pow(int x,int n)
{
   if(x==1)return 1;
   if(n==0)return 1;
   
   int p=pow(x,n/2);

   if(n%2==0)
   return p*p;

   else 
   return p*p*x;
}

int main()
{
    int ans=pow(2,4);
    cout<<ans;
    return 0;
}