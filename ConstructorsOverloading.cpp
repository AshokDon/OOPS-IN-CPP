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
/*Constructors Overloading*/
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
		cout<<"default Constructor is called"<<endl;
	}
	Human(int val){
		name = "Noname";
		age = val;
		cout<<"Constructor is called age as perameter"<<endl;
	}
	Human(string word){
		name = word;
		age = 0;
		cout<<"Constructor is called name as perameter"<<endl;
	}
	Human(int val, string word){
		name = word;
		age = val;
		cout<<"Constructor is called with name and age as perameter"<<endl;
	}
	

};

int main() {
    // your code goes here
    fast_io;
    TakeInput();
    Human Ashok;
    Human Ram("Ram");
    
    

	
}
