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
//Overriding Base class Methods in drived class
class Person{
public:
	void Intoduce(){
		cout<<"hi i am an Person"<<endl;
	}
};
class Student : public Person{
public:
	void Intoduce(){
		cout<<"hi i am a Student"<<endl;
	}
};

int main() {
    // your code goes here
    fast_io;
    TakeInput();
    Student Ashok;
    Ashok.Person::Intoduce();

    


}
