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
//this Keyword //
//every object in cpp has an acess to its own addres through an important
//pointer this
class Person{
private:
	int age;
public:
	void SetAge(int age){
		this->age = age;
	}
	void ShowData(){
		cout<<age<<endl;
	}
};

int main() {
    // your code goes here
    fast_io;
    TakeInput();
    Person Ashok;
    Ashok.SetAge(28);
    Ashok.ShowData();


    


}
