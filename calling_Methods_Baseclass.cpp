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
//calling Methods Using Base Class //
class Person{
public:
	void Introduce(){
		cout<<"hey this is Person"<<endl;
	}
};
class Student : public Person{
public:
	void Introduce(){
		cout<<"hey this is Student"<<endl;
	}
};
void WhosThis(Person P){
	P.Introduce();
}
int main() {
    // your code goes here
    fast_io;
    TakeInput();
    Student Ashok;
    Ashok.Introduce();
    WhosThis(Ashok);
    


    


}
