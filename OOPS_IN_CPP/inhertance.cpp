#include<bits/stdc++.h>
using namespace std;

void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
//what is inheritance in Programming


class YouTubeChannel{
	//members
private:
	
	int SubscribesCount;
	list<string>PublishedVideoTitles;
protected:
	string Name;
	string OwnerName;
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
		if(SubscribesCount > 0)
		SubscribesCount--;
	}
	void PublishVideo(string Title){
		PublishedVideoTitles.push_back(Title);
	}
};
class CookingYouTubeChennel : public YouTubeChannel{
public:
	//YouTubeChannel :: Name;
	CookingYouTubeChennel(string name, string ownerName):YouTubeChannel(name,ownerName){

	}
	void Practice(){
		cout<<Name<<" practicing some recipes"<<"\n";
	}
};

int main(){
	TakeInput();
	CookingYouTubeChennel cookingYTchannel("Pullama's kitchen", "Pullama");
	cookingYTchannel.GetInfo();
	cookingYTchannel.Practice();
	

}











