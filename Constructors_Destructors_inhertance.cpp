#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pb push_back
using namespace std;

void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
//Order of Execution of Constructors and Destructors in inheritance // 
class Person{
	 public:
	 	Person(){
	 		cout<<"Constructor of Base class is called"<<endl;
	 	}
	 	~Person(){
	 		cout<<"Destructor of Base class is called"<<endl;
	 	}
};
class Student : public Person{
public:
	Student(){
		cout<<"Constructor of Drived class is called"<<endl;
	}
	~Student(){
		cout<<"Destructor of Drived class is called"<<endl;
	}
};
int main() {
    // your code goes here
    fast_io;
    TakeInput();
    Student Ashok;
    


}
