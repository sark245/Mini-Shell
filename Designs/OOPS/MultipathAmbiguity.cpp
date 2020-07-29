#include<bits/stdc++.h>
using namespace std;

class A{
public: 
    int a;
};

class B : public A{
public: 
    int b;
};

class C : public A{
public: 
    int c;
};

class D : public B, public C{
public : 
    int d;
};

int main(){
    D obj;
    //obj.a = 10;         gives error

    obj.B::a = 10;
    obj.C::a = 100;

    obj.b = 20;
    obj.c = 30;
    obj.d = 40;
    

    return 0;

}
