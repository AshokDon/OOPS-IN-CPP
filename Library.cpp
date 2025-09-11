#include<bits/stdc++.h>
using namespace std;

class Book{
    public:
    int id;
    string title;
    string author;
    int avalibleCopies;
    Book(int id, string title, string author, int avalibleCopies){
        this->id = id;
        this->title = title;
        this->author = author;
        this->avalibleCopies = avalibleCopies;
    }
    void DisplayBook(){
        //is to print the info of the book
        //the id of book : 
        //the autor of book
    }

};
class Member{
    public:
    int id;
    string name;
    int phoneNumber;
    vector<int>InfoBook;

    Member(int id, string name, int phoneNumber){
        this->id = id;
        this->name = name;
        this->phoneNumber = phoneNumber;
    }
    void borrowBook(int bookId){
        InfoBook.push_back(bookId);
    }
    void returnBook(int bookId){
        auto it = find(InfoBook.begin(),InfoBook.end(),bookId);
        InfoBook.erase(it);


    }

};

class Library{
    public:
    vector<Book>books; // 100
    vector<Member>members;

    void addBook(Book b){
        books.push_back(b);
    }
    void addMember(Member m){
        members.push_back(m);
    }

    void borrowBook(int memberId, int bookId){
        bool f = 0;
        for(auto &b : books){
            if(b.id == bookId && b.avalibleCopies > 0){
                for(auto &m : members){
                    if(m.id == memberId){
                        m.borrowBook(bookId);
                        b.avalibleCopies--;
                        f = 1;
                        cout << m.name <<" borrowed " << b.title << endl;
                    }
                }
            }
        }
        if(f == 0) cout << "book is not avalible\n";
    }
    void returnBook(int memberId, int bookId){
        for(auto &b : books){
            if(b.id == bookId){
                for(auto &m : members){
                    if(m.id == memberId){
                        m.returnBook(bookId);
                        b.avalibleCopies++;
                        cout << m.name <<" returned " << b.title << endl;
                        return;
                    }
                }
            }
        }
        cout << "Invalid return" << endl;
    }


};


int main(){
    Library lib;
    Book b1(1,"c++","Ashok",3);
    lib.addBook(b1);
    Member m1(2,"Ram",78347463);

}
