#include<iostream>
using namespace std;

void printInc(int a,int b)
{
    if(a==b+1)  //base case
    return;
   
   cout<<a;    //preorder work
   printInc(a+1,b);

}

int main()
{
    printInc(0,5);
    return 0;
}
