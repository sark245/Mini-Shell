//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);
    

class Parent{
public : 
    int d1 = 10;
    int d = 100;
    void fun1(){
        cout<<"Parent's fun 1\n";
    }
    void fun(){
        cout<<"Parent's fun\n";
    }
};

class Child : public Parent{
public : 
    int d2 = 20;
    int d = 200;
    void fun2(){
        cout<<"Child's fun 2\n";
    }
    void fun(){
        cout<<"Child's fun\n";
    }
};




int main(){
   IOS

    Parent *p = new Parent();
    Child *c = new Child();
    Parent *pc = new Child();

    // Child *cp = new Parent();  //gives compile time error

    pc->fun();
    pc->fun1();
    cout<<pc->d<<" "<<pc->d1<<'\n';
    //pc->fun2();   compile time error

    // c->fun();
    // c->fun1();
    // c->fun2();
    // cout<<c->d<<' '<<c->d1<<' '<<c->d2<<"\n";
    



}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1) res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

