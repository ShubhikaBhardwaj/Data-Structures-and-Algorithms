#include<iostream>
using namespace std;

void printIncDec(int a,int b)
{
    if(a==b)  //base case
    {
        cout<<a;
        return;
    }
   
   cout<<a; //preorder
   printIncDec(a+1,b);
   cout<<a; //post order

}

int main()
{
    printIncDec(0,5);
    return 0;
}
