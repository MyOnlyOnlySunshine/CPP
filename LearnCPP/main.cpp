//
//  main.cpp
//  LearnCPP
//
//  Created by apple on 2017/5/11.
//  Copyright © 2017年 畅畅. All rights reserved.
//

#include <iostream>
using namespace std;

class People
{
 public:
    string name;
    int age;
    bool sex;
    void setName(string name);
    void setAge(int age);
    void setSex(bool sex);
    void test(string name,int age,bool sex);
    People(string name,int age,bool sex);
    ~People();
    
 protected:
    string spouseName;
 private:
    string sonName;
    
};

void People::setName(string name){this->name = name;}
void People::setAge(int age){this ->age = age;};
void People::setSex(bool sex){this ->sex = sex; }

void People::test(string name,int age,bool sex)
{
    cout<<"people "<<this->name<<" "<<this->age<<" "<<"\n";
};

People::People(string name,int age,bool sex):name(name),age(age),sex(sex)
{
    
}

People::~People()
{
    cout<<"people析构函数"<<"\n";
};

class Human
{
    
};

//注意不加public 默认为private
class Student: public People
{
 public:
    float score;
    void setScore(float score);
    void test(float score);
    Student(string name,int age,bool sex,float score);
    ~Student();
    using People::setSex;
    using People::spouseName;
private:
    void show();
   // using People::sonName;
};

Student::Student(string name,int age, bool sex, float score):People(name,age,sex),score(score)
{
    //cout<<"age : "<<age<<"sex : "<<sex<<endl;
}

Student::~Student()
{
    cout<<"Student 析构函数"<<endl;
}
void Student::test(float score)
{
    cout<<"student "<<score<<" "<<"\n";
}

void Student::show()
{
    this->spouseName= "qqq";
    cout<<"spouse"<<this->spouseName<<"\n";
}

void Student::setScore(float score){this->score = score;};

int main(int argc, const char * argv[]) {
    People p("qq",222,1);
    p.setSex(true);
    p.setAge(30);
    p.setName("zzz");
    p.test("222", 30, 1);
    Student s("aa",20,true,9.9);
    
    cout<<s.name<<" "<<s.age<<" "<<s.sex<<" "<<s.score<<"\n";
    return 0;
}


