#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pb push_back
#define pf push_front
using namespace std;
//const int mod = (int)1e9 + 7;

void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
/*Constructors*/
//constructor --> nothing but a special function or method
//which has no return type and same name as class
//this is will be called when object is created 
class Human{
private:
	string name;
	int age;
public:
	Human(){
		name = "Noname";
		age = 0;
		cout<<"Constructor is called"<<endl;
	}
	void Display(){
		cout<<name<<endl<<age<<endl;
	}

};

int main() {
    // your code goes here
    fast_io;
    TakeInput();
    Human Ashok;
    Ashok.Display();
    

	
}
