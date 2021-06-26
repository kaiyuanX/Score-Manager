#include <fstream>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::string;

#define num_of_sub 7

/* 课程信息 */
class sub
{
private:
    string name;
    string num;
    string time;
    string score;

public:
    //获取信息
    string getname()
    {
        return name;
    }
    string getnum()
    {
        return num;
    }
    string gettime()
    {
        return time;
    }
    string getscore()
    {
        return score;
    }
    //赋值
    void assignsub(string *x)
    {
        name = x[0];
        num = x[1];
        time = x[2];
        score = x[3];
    }
};

/* 单链表记录单个学生的课程编号 */
/* suball[i] 为编号 200i的课程 */
struct sublist
{
    int subject;
    struct sublist *next;
};

typedef struct sublist *subnode;

extern sub suball[];

/* 记录出生日期 */
/* student的父类 */
class birth
{
private:
    string year;
    string month;
    string day;

public:
    birth(string year_, string month_, string day_) : year(year_), month(month_), day(day_) {}
    //获取信息
    string getyear()
    {
        return year;
    }
    string getmonth()
    {
        return month;
    }
    string getday()
    {
        return day;
    }

    void assignbirth(string *x)
    {
        year = x[0];
        month = x[1];
        day = x[2];
    }
    void assignwithkbhit_birth()
    {
        cout << "Please put birth of the student." << endl;
        cin >> year;
        cin >> month;
        cin >> day;
    }
};

/* 学生信息 */
class student : public birth
{
private:
    string name;
    string num;
    string gender;    // 0女 1男
    string institute; //学院
    string major;
    string grade;
    string clas;

    subnode subhead; //学生所选课程的集合,以链表方式进行存储

public:
    student(string year_ = "000", string month_ = "000", string day_ = "000",
            string name_ = "000", string num_ = "000", string gender_ = "000",
            string institute_ = "000", string major_ = "000", string grade_ = "000", string class_ = "000")
        : birth(year_, month_, day_), name(name_),
          num(num_), gender(gender_), institute(institute_), major(major_), grade(grade_), clas(class_)
    {
        subhead = new struct sublist;
        subhead->next = NULL;
    }
    //获取信息
    string getname()
    {
        return name;
    }
    string getnum()
    {
        return num;
    }
    string getgender()
    {
        return gender;
    }
    string getinstitute()
    {
        return institute;
    }
    string getmajor()
    {
        return major;
    }
    string getgrade()
    {
        return grade;
    }
    string getclas()
    {
        return clas;
    }
    subnode getsub()
    {
        return subhead;
    }
    //赋值
    void assignstudent(string *x)
    {
        name = x[0];
        num = x[1];
        gender = x[2];
        assignbirth(x + 3);
        institute = x[6];
        major = x[7];
        grade = x[8];
        clas = x[9];
    }
    void assignstudent_subhead(subnode x)
    {
    }
    /* 用键盘进行赋值 */
    void assignwithkbhit_student()
    {
        /* 输入基本信息 */
        cout << "Please put name of the student." << endl;
        cin >> name;
        cout << "Please put number of the student." << endl;
        cin >> num;
        cout << "Please put gender of the student.( 0:girl , 1:boy )" << endl;
        cin >> gender;

        assignwithkbhit_birth();

        cout << "Please put institute of the student." << endl;
        cin >> institute;
        cout << "Please put major of the student." << endl;
        cin >> major;
        cout << "Please put grade of the student." << endl;
        cin >> grade;
        cout << "Please put class of the student." << endl;
        cin >> clas;

        /* 输入课程 */
        cout << "These are subjects you can choose below." << endl;
        for (int i = 0; i < num_of_sub; i++)
        {
            cout << "  name of subject : " << suball[i].getname() << endl;
            cout << "number of subject : " << suball[i].getnum() << endl;
            cout << endl;
        }

        cout << "Please put the count of the subjects you want to choose" << endl;
        int n;
        cin >> n;

        cout << "Please put number of subjects of the student." << endl;
        subnode temp0 = NULL, p1 = subhead;
        int ch;
        char ch_;
        for (int i = 0; i < n; i++)
        {
            cin >> ch_;
            cin >> ch_;
            cin >> ch_;
            cin >> ch;

            if ((temp0 = new struct sublist) == NULL)
            {
                printf("创建失败,内存不足。");
            }
            temp0->next = NULL;
            temp0->subject = ch;

            while (p1->next != NULL)
            {
                p1 = p1->next;
            }
            p1->next = temp0;
        }
    }
};

/* 存储学生信息的单链表 */
struct stulist
{
    student stu;
    struct stulist *next;
};

typedef struct stulist *stunode;

/*  */
/* 课程信息读取 */
void Subread(sub *suball);

/* 学生信息初始化 */
stunode Studentread(stunode head);

/* 使用 尾插法 对某学生的课程情况进行编辑 */ //*******
subnode InsertAtEnd(subnode l, sub value);

/* 添加一个学生的信息 */
stunode InsertAtEnd_student(stunode head);

/* 输出 suball[] */
void Print_suball(sub *sublist_);

/* 输出 链表stunode 所含信息 */
void Print_stuall(stunode head);
void Print_stuall_Only_Num(stunode head);

/* 输出 链表 subnode 所含信息 */
void Print_stu_of_sub(subnode head);

/* 从 链表stunode 中找到对应 num 的节点 */
/* 返回该节点的地址 */
stunode Find_from_Num_of_Student(stunode head, string num_to_be_find);

/* 把 head 中的全部信息保存在 student.txt 中 */
void Save_Student_information(stunode head);