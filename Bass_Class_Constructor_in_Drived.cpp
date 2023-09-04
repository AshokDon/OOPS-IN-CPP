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
//calling and Passing values to Base class Constructor in Drived class// 
class Father{
	protected:
		int height;
	public:
		Father(int val){
			cout<<"Base class constructor"<<endl;
			height = val;
		}

};
class Child : public Father{
public:
	Child(int x) : Father(x){
		cout<<"child class constructor"<<endl;

	}
	void Display(){
		cout<<height<<endl;
	}
};

int main() {
    // your code goes here
    fast_io;
    TakeInput();
    Child Ashok(28);
    Ashok.Display();

    


}
