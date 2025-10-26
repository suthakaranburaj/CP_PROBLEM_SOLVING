#include <bits/stdc++.h>
using namespace std;

// ------------------------
// 1️⃣ Encapsulation + Abstraction
// ------------------------
class GrandParent {
protected:
    string *gender;  // Encapsulation: hidden from public
public:
    string *name;
    string *color;
    string *family;
    int *age;

    // Constructor (Encapsulation + Initialization)
    GrandParent(string name, string gender, string color, string family, int age) {
        this->name = new string(name);
        this->gender = new string(gender);
        this->color = new string(color);
        this->family = new string(family);
        this->age = new int(age);
        cout << "GrandParent created!" << endl;
    }

    // Abstraction: only exposes "eat" behavior
    void eat() {
        cout << *name << " is eating" << endl;
    }

    virtual void display() {  // Polymorphism: virtual function
        cout << "GrandParent: " << *name << ", " << *gender << ", Age: " << *age << endl;
    }

    virtual ~GrandParent() {
        delete name;
        delete gender;
        delete color;
        delete family;
        delete age;
        cout << "GrandParent destroyed!" << endl;
    }
};

// ------------------------
// 2️⃣ Single Inheritance
// ------------------------
class Parent : public GrandParent {
protected:
    string *job;
public:
    Parent(string name, string gender, string color, string family, int age, string job)
        : GrandParent(name, gender, color, family, age) {
        this->job = new string(job);
        cout << "Parent created!" << endl;
    }

    void work() {
        cout << *name << " is working as " << *job << endl;
    }

    void display() override {  // Polymorphism: overriding
        cout << "Parent: " << *name << ", Job: " << *job << ", Age: " << *age << endl;
    }

    ~Parent() {
        delete job;
        cout << "Parent destroyed!" << endl;
    }
};

// ------------------------
// 3️⃣ Multiple Inheritance
// ------------------------
class Skills {
protected:
    string *skill;
public:
    Skills(string skill) {
        this->skill = new string(skill);
        cout << "Skills created!" << endl;
    }

    void showSkill() {
        cout << "Skill: " << *skill << endl;
    }

    virtual ~Skills() {
        delete skill;
        cout << "Skills destroyed!" << endl;
    }
};

// ------------------------
// 4️⃣ Multilevel + Hierarchical Inheritance
// ------------------------
class Child : public Parent, public Skills {
public:
    Child(string name, string gender, string color, string family, int age, string job, string skill)
        : Parent(name, gender, color, family, age, job), Skills(skill) {
        cout << "Child created!" << endl;
    }

    void display() override {
        cout << "Child: " << *name << ", Age: " << *age << ", Job: " << *job << ", Skill: " << *skill << endl;
    }

    ~Child() {
        cout << "Child destroyed!" << endl;
    }
};

int main() {
    cout << "------ GrandParent ------" << endl;
    GrandParent gp("Enamuthu", "Male", "Brown", "Nadar", 72);
    gp.eat();
    gp.display();

    cout << "\n------ Parent ------" << endl;
    Parent p("Kumar", "Male", "Fair", "Nadar", 45, "Engineer");
    p.eat();
    p.work();
    p.display();

    cout << "\n------ Child ------" << endl;
    Child c("Anbu", "Male", "Fair", "Nadar", 20, "Student", "Coding");
    c.eat();
    c.work();
    c.showSkill();
    c.display();

    return 0;
}
