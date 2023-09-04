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
//chaging Access level of Base class members in Drived Class 
class Person{
	protected:
		int age;
	public:
		void SetAge(int val){
			age = val;
		}
};
class Student : private Person{
public:
	Person :: age;
	Person :: SetAge;
	void Display(){
		cout<<age<<endl;
	}
};
int main() {
    // your code goes here
    fast_io;
    //TakeInput();
    Student Ashok;
    Ashok.SetAge(28);
    Ashok.Display();


}
