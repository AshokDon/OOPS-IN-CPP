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
/* what is a class and what is a object*/

//let us start a new concept in CPP --> OOPS
//OOPS is used to solve real entity problems
//let us assum we are bulding an humen
//human has attributs like (name, gendar, heigh, weight etc..)
//human do some activites like (talk, eat, walks) and some how we can combine
//this activaties and actions under one name 
//class is a user defined data type which can allows us to combine the
//data and the actions that going to perform on that data

//decleration of class


class HumanBeing{
	//members --> attributes and activaties 

	//acess specifers--> tells where this members can be avalible
public: // can be acessied inside and out side of the class
	void Display(){
		cout<<"hello Huma";
	}

};

int main() {
    // your code goes here
    fast_io;
    TakeInput();
    //objects --> real world entity , its a veriable of type class
    //runtime veriable
    HumanBeing Ashok;
    Ashok.Display();

    
    return 0;
}
