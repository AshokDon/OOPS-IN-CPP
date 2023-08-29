 #include<iostream>
using namespace std;
void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
/*friend class and friend function*/
//which can acess all its pravite members
class HumaBeing{

private:
	string name;
	int age;
public:
	HumaBeing(string word, int val){
		name = word;
		age = val;
	}
	friend void Display(HumaBeing Ashok);

//friend class Student;

};
void Display(HumaBeing Ashok){
	cout<<Ashok.nameendl;
}

int main()
{
	TakeInput();
	
	HumaBeing Ashok("Ashok", 28);
	Display(Ashok);
	
	
	


	


}
