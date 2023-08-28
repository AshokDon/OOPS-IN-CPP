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
/*Private Access Specifier*/



class HumanBeing{
	private:
		int age;
		int GetAge(){
			return age-5;
		}
	public:
		void DisplayAge(){
			cout<<GetAge()<<endl;
		}
		void SetAge(int val){
			age = val;
		}
};
//string HumanBeing::name = "Assu";

int main() {
    // your code goes here
    fast_io;
    TakeInput();
    HumanBeing Ashok;
    Ashok.SetAge(29);
    Ashok.DisplayAge();
    return 0;
}
