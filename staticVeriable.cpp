 #include<iostream>
using namespace std;
void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
/*static variables and static functions*/
//
void Get(){
	static int cnt = 0;
	cout<<++cnt<<endl;
}
class Human{
public:
	static int Human_count;//one reference copy is created for all objects
	Human(){
		Human_count++;
	}
	void Display(){
		cout<<Human_count<<endl;
	}

};
int Human::Human_count = 0;//we can initialize  out side the class
int main()
{
	TakeInput();
	Get();
	cout<<Human::Human_count;
	Human Ashok;
	Human Assu;
	Ashok.Display();

	
}
