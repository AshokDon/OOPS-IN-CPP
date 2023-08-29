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
// void Get(){
// 	static int cnt = 0;
// 	cout<<++cnt<<endl;
// }
class Human{
public:
	static int Human_count;
	Human(){
		Human_count++;
	}
	void Display(){
		cout<<Human_count<<endl;
	}
	static void display(){
		cout<<"Hi"<<Human_count<<endl;
	}

};
int Human::Human_count = 0;
int main()
{
	TakeInput();
	
	cout<<Human::Human_count;
	Human Ashok;
	Human::display();
	Human Assu;
	Ashok.Display();

	
}
