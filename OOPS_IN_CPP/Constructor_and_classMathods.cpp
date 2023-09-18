#include<bits/stdc++.h>
using namespace std;

void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
//What are constructors and class methods ? How to use them ?
//what if you want to creat a multiple objects for a same class 
//the decleration and initilation of attrubutes become more complecated
//so we can use constructors to overcome this problem
//Constructor : is a special method which is going to be invocked when
//an object is created for a class
//two rules : 1.constructor has same name as class 2.it dont have any return type


class YouTubeChannel{
	//members
public:
	string Name;
	string OwnerName;
	int SubscribesCount;
	list<string>PublishedVideoTitles;
	YouTubeChannel(string name, string ownerName){
		Name = name;
		OwnerName = ownerName;
		SubscribesCount = 0;
	}
	void GetInfo(){
		cout << "Channel name : "<<Name << "\n";
		cout << "Owner Name : " << OwnerName << "\n";
		for(string videotitles:PublishedVideoTitles ){
			cout<<videotitles<<"\n";
		}

	}
};

int main(){
	TakeInput();
	YouTubeChannel YTchannel("Codeblooded","Ashok");
	YTchannel.PublishedVideoTitles.push_back("C++ STL");
	YTchannel.PublishedVideoTitles.push_back("C++ OOP");
	YTchannel.GetInfo();
	

}











