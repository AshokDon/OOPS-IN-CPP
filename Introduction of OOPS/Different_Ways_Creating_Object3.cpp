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
/*creating objects for a class in Different ways*/


class HumanBeing{
	public:
		string name;
		void Introduce(){
			cout<<"I am "<<name<<endl;
		}

};

int main() {
    // your code goes here
    fast_io;
    TakeInput();
    //creat an object in two different ways
    //1st way it will be allocated in stack
    HumanBeing Ashok;
    Ashok.name = "Ashok";
    Ashok.Introduce();

    //2nd way creating object dynamically
    //it will be allocated in heap memory

    HumanBeing *Ram = new HumanBeing();
    Ram->name = "Ram";
    Ram->Introduce();



    
    return 0;
}
