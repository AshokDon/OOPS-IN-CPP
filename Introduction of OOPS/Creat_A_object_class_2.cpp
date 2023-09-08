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
/*Demonestartion on creating class and objects*/


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
    //objects --> real world entity , its a veriable of type class
    //runtime veriable
    HumanBeing Ashok;
    Ashok.name = "Ashok";
    Ashok.Introduce();

    HumanBeing Prabhu;
    Prabhu.name = "Prabhu";
    Prabhu.Introduce();

    
    return 0;
}
