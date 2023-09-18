#include<bits/stdc++.h>
using namespace std;

void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
//What is encapsulation in programming ?
//hading the data from the users so they cant modify them
//so make the properties or attributes private

//design some methods and give acess to the users to get and set the properties so by obying
//the rules of that methods user can get the acess


class YouTubeChannel{
	//members
private:
	string Name;
	string OwnerName;
	int SubscribesCount;
	list<string>PublishedVideoTitles;
public:
	YouTubeChannel(string name, string ownerName){
		Name = name;
		OwnerName = ownerName;
		SubscribesCount = 0;
	}
	void GetInfo(){
		cout << "Channel name : "<<Name << "\n";
		cout << "Owner Name : " << OwnerName << "\n";
		cout << "Subscribes : " <<SubscribesCount << "\n";
		for(string videotitles:PublishedVideoTitles ){
			cout<<videotitles<<"\n";
		}

	}
	void Subscribe(){
		SubscribesCount++;
	}
	void Unsubscribe(){
		SubscribesCount--;
	}
	void PublishVideo(string Title){
		PublishedVideoTitles.push_back("C++ STL")
	}
};

int main(){
	TakeInput();
	YouTubeChannel YTchannel("Codeblooded","Ashok");
	YTchannel.Subscribe();
	YTchannel.Subscribe();
	YTchannel.GetInfo();
	

}











