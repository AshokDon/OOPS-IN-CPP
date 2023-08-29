 #include<iostream>
using namespace std;
void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
/*inheritance*/
class Person{
public:
	string name;
	int age;
	void SetName(string word){
		name = word;
	}
	void SetAge(int val){
		age = val;
	}

};
class Student : public Person{
public:
	int id;
	void SetId(int val){
		id = val;
	}
	void Introduce(){
		cout<<"Hi i am "<<name<<" and my age is "<<age<<" with id as "<<id<<endl;
	}

};

int main(){
	TakeInput();
	Student Ashok;
	Ashok.SetName("Ashok");
	Ashok.SetAge(28);
	Ashok.SetId(12345);
	Ashok.Introduce();
}




