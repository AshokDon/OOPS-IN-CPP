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
/*Destructor */
//Destructor --> nothing but a special function or method
//which has no return type and same name as class and don't take
//any arguments
//this is will be called when object is deleted 
class Human{
private:
	string *name;
	int *age;
public:
	Human(string myname, int myage){
		name = new string;
		age = new int;
		*name = myname;
		*age = myage;
	}
	void Display(){
		cout<<*name<<" "<<*age<<endl;
	}
	~Human(){
		delete name;
		delete age;
		cout<<"Destructor is called";
	}

};

int main() {
    // your code goes here
    fast_io;
    TakeInput();
    Human *Ashok = new Human("Ashok",28);
    Ashok->Display();
    delete Ashok;//
    
    

	
}
