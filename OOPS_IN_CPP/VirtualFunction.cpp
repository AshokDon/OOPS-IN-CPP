#include<bits/stdc++.h>
using namespace std;

void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

/*
Relation between virtual function and Pure virtual function and Abstract class
*/
class Instrument{
public:
	virtual void MakeSound() = 0;
};
class Gitter : public Instrument{
public:
	void MakeSound(){
		cout<<"The instrument Gitter is playing..\n";
	}
};
class Piano : public Instrument{
	void MakeSound(){
		cout<<"The instrument Piano is playing..\n";
	}
};

int main(){
	TakeInput();
	Instrument *i1 = new Gitter();
	i1->MakeSound();

	Instrument *i2 = new Piano();
	i2->MakeSound();
	
}
