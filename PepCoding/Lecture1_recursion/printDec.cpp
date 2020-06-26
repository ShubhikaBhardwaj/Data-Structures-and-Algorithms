#include<iostream>
using namespace std;

void printDec(int a,int b)
{
    if(a==b+1)  //base case
    return;
   
   
   printDec(a+1,b);
   cout<<a; //post order

}

int main()
{
    printDec(0,5);
    return 0;
}
