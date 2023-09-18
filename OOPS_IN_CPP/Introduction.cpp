#include<bits/stdc++.h>
using namespace std;

void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
//OOP
//object oriented programming
//it is useful to represent real life objects in programming
//this real life objects are going to represent together with there attributes and behavioures
//First import topic in OOP is classes and objects

//class :- class is going to represent templete (blue print)(user define data type)
//object :- object real reprent an example of that class or instance of that class
//Example :- class :- fruit , object :- apple,banana
//Example : class : car , object :- valvo , BMW


class YouTubeChannel{
	//members
public:
	string name;
	string OwnerName;
	int SubscribesCount;
	list<string>PublishedVideoTitles;

};

int main(){
	TakeInput();
	YouTubeChannel YTchannel;
	YTchannel.name = "Codeblooded";
	YTchannel.OwnerName = "Ashok";
	YTchannel.SubscribesCount = 1200;
	YTchannel.PublishedVideoTitles = {"C++ STL","C++ OOP","DSA"};
	cout << "Channel name : "<<YTchannel.name << "\n";
	cout << "Owner Name : " << YTchannel.OwnerName << "\n";
	for(string videotitles: YTchannel.PublishedVideoTitles ){
		cout<<videotitles<<"\n";
	}

}











