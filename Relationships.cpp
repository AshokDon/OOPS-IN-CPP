#include <iostream>
using namespace std;

class Teacher {
public:
    string name;
    Teacher(string n) : name(n) {}
};

class Student {
public:
    string name;
    Student(string n) : name(n) {}

    void setTeacher(Teacher* t) {   // Student knows Teacher
        cout << name << " is taught by " << t->name << endl;
    }
};

int main() {
    Teacher t("Mr. Brown");
    Student s("Alice");
    s.setTeacher(&t);   // Unidirectional: Student → Teacher
    return 0;
}



//Bidirectional
#include <iostream>
#include <vector>
using namespace std;

class Student; // forward declaration

class Teacher {
public:
    string name;
    vector<Student*> students;
    Teacher(string n) : name(n) {}

    void addStudent(Student* s);
    void showStudents();
};

class Student {
public:
    string name;
    Teacher* teacher;   // Student knows Teacher

    Student(string n) : name(n), teacher(nullptr) {}

    void setTeacher(Teacher* t) {
        teacher = t;
        t->addStudent(this);   // Mutual link
    }

    void showTeacher() {
        if (teacher) cout << name << " is taught by " << teacher->name << endl;
    }
};

void Teacher::addStudent(Student* s) {
    students.push_back(s);
}

void Teacher::showStudents() {
    cout << name << " teaches: ";
    for (auto s : students) cout << s->name << " ";
    cout << endl;
}

int main() {
    Teacher t("Mr. Brown");
    Student s1("Alice"), s2("John");

    s1.setTeacher(&t);
    s2.setTeacher(&t);

    t.showStudents();    // Teacher → Students
    s1.showTeacher();    // Student → Teacher
    s2.showTeacher();

    return 0;
}


//Multiplicity
#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    Student(string n) : name(n) {}
};

class Teacher {
public:
    string name;
    vector<Student*> students;   // Multiplicity (1-to-many)

    Teacher(string n) : name(n) {}

    void addStudent(Student* s) {
        students.push_back(s);
    }

    void showStudents() {
        cout << name << " teaches: ";
        for (auto s : students) cout << s->name << " ";
        cout << endl;
    }
};

int main() {
    Teacher t("Mr. Brown");
    Student s1("John"), s2("Emma"), s3("Liam");

    t.addStudent(&s1);
    t.addStudent(&s2);
    t.addStudent(&s3);

    t.showStudents();
    return 0;
}


//Aggregation
#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    Book(string t) : title(t) {}
};

class Library {
public:
    vector<Book*> books;  // Aggregation

    void addBook(Book* b) {
        books.push_back(b);
    }

    void showBooks() {
        cout << "Library has: ";
        for (auto b : books) cout << b->title << " ";
        cout << endl;
    }
};

int main() {
    Book b1("C++ Basics"), b2("OOP Design");
    Library lib;

    lib.addBook(&b1);
    lib.addBook(&b2);

    lib.showBooks();
    return 0;
}

//Composition
#include <iostream>
using namespace std;

class Engine {
public:
    Engine() { cout << "Engine created\n"; }
    void start() { cout << "Engine started\n"; }
};

class Car {
private:
    Engine engine;   // Composition (Car owns Engine)
public:
    Car() { cout << "Car created\n"; }
    void drive() {
        engine.start();
        cout << "Car is moving\n";
    }
};

int main() {
    Car c1;     // Engine is created with Car
    c1.drive();
    return 0;
}
