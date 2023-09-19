using namespace std;

void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
//what is Polymorphism in Programming
//polymorphism in c++ means, the same entity (function or object) behaves differently
//in different scenarious.

//Example 
/*
The “ +” operator in c++ can perform two specific functions at two different 
scenarios i.e when the “+” operator is used in numbers, it performs addition.

int a = 10;
int b = 20;
int sum = a + b;

And the same “+” operator is 
string firstname = "Ashok ";
string lastname = "Marnala";
sring name = firname + lastname;

Types of Polymorphism
1.compile time polymorphism
2.run time polymorphism


*/

//1.compile time polymorphism
/*
In compile-time polymorphism, a function is called at the time of program 
compilation. We call this type of polymorphism as early binding or Static binding.

Function overloading and operator overloading is the type of 
Compile time polymorphism.

I. Function Overloading

Function overloading means one function can perform many tasks. In C++, a single 
function is used to perform many tasks with the same name and different types of 
arguments. In the function overloading function will call at the time of program 
compilation. It is an example of compile-time polymorphism.

In the below example, A function ADD() is used to perform two tasks. 
The two asks would be to add two integer values and add two strings (concatenate). 

Readability of the program increases by function overloading. 
It is achieved by using the same name for the same action

*/

class Addition {
public:
    int ADD(int X,int Y)   // Function with parameter 
    {
        return X+Y;     // this function is performing addition of  two Integer value
    }
    int ADD() {              // Function with same name but without parameter
        string a= "HELLO";
        string b="SAM";   // in this function concatenation is performed
       string c= a+b;
       cout<<c<<endl;
        
    }
};
int main(void) {
    Addition obj;   // Object is created  
    cout<<obj.ADD(128, 15)<<endl; //first method is called
    obj.ADD();  // second method is called
    return 0;
}



/*
II. Operator Overloa
Operator overloading means defining additional tasks to operators without 
changing its actual meaning. We do this by using operator function.

The purpose of operator overloading is to provide a special meaning to 
the user-defined data types.

The advantage of Operators overloading is to perform different operations 
on the same operand.ding
*/

#include <iostream>  
using namespace std;  
class A  
{  
     
    string x;  
      public:  
      A(){}  
    A(string i)  
    {  
       x=i;  
    }  
    void operator+(A);  
    void display();  
};  
   
void A:: operator+(A a)  
{  
      
    string m = x+a.x;  
    cout<<"The result of the addition of two objects is : "<<m;  
   
}  
int main()  
{  
    A a1("Welcome");  
    A a2("back");  
    a1+a2;  
    return 0;  
}


/*



2. Runtime Polymorphism

In a Runtime polymorphism, functions are called at the time the program execution. Hence, it is known as late binding or dynamic binding.

Function overriding is a part of runtime polymorphism. 
In function overriding, more than one method has the same name with different 
types of the parameter list. 

It is achieved by using virtual functions and pointers.
 It provides slow execution as it is known at the run time. 
 Thus, It is more flexible as all the things executed at the run time.

I. Function overriding

In function overriding, we give the new definition to base class 
function in the derived class. At that time, we can say the base function has been overridden. It can be only possible in the ‘derived class’. In function overriding, we have two definitions of the same function, one in the superclass and one in the derived class. The decision about which function definition requires calling happens at runtime. That is the reason we call it ‘Runtime polymorphism’.


*/


#include <iostream>  
using namespace std;  
class Animal {  
    public:  
void function(){    
cout<<"Eating..."<<endl;    
    }      
};   
class Man: public Animal    
{    
 public:  
 void function()    
    {    
       cout<<"Walking ..."<<endl;    
    }    
};  
int main(void) {  
 Animal A =Animal();
   A.function();   //parent class object 
   Man m = Man();    
   m.function();   // child class object
   
   return 0;  
}
