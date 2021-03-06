#include "data.h"
#include <stdlib.h>

/* 课程信息读取 */
void Subread(sub *suball)
{
    /* sub.txt里面记录了所有的课程信息 */
    ifstream fp;
    fp.open("sub.txt");

    string temp[4];
    char ch = fp.get();

    for (int i = 0; i < num_of_sub; i++)
    {
        while (ch != ':')
        {
            ch = fp.get();
        }
        getline(fp, temp[0]);
        ch = fp.get();

        while (ch != ':')
        {
            ch = fp.get();
        }
        getline(fp, temp[1]);
        ch = fp.get();

        while (ch != ':')
        {
            ch = fp.get();
        }
        getline(fp, temp[2]);
        ch = fp.get();

        while (ch != ':')
        {
            ch = fp.get();
        }
        getline(fp, temp[3]);
        ch = fp.get(); //ch=='\n'

        suball[i].assignsub(temp);

        /* 之后ch指向 eof 或 下一项的某个字符 */
        ch = fp.get();
        ch = fp.get();
    }
    fp.close();
}

/* 学生信息初始化 */
stunode Studentread(stunode head)
{
    /* student.txt里面记录了所有的学生信息 */
    ifstream fp;
    fp.open("student.txt");

    string temp[10];
    char ch = fp.get();

    for (int i = 0; ch != EOF; ch = fp.get(), i++)
    {
        /* 读取学生的基本信息 */
        while (ch != ':')
        {
            ch = fp.get();
        }
        getline(fp, temp[0]);
        ch = fp.get();

        while (ch != ':')
        {
            ch = fp.get();
        }
        getline(fp, temp[1]);
        ch = fp.get();

        while (ch != ':')
        {
            ch = fp.get();
        }
        getline(fp, temp[2]);
        ch = fp.get();

        while (ch != ':')
        {
            ch = fp.get();
        }
        getline(fp, temp[3], '-');
        getline(fp, temp[4], '-');
        getline(fp, temp[5]);
        ch = fp.get();

        while (ch != ':')
        {
            ch = fp.get();
        }
        getline(fp, temp[6]);
        ch = fp.get();

        while (ch != ':')
        {
            ch = fp.get();
        }
        getline(fp, temp[7]);
        ch = fp.get();

        while (ch != ':')
        {
            ch = fp.get();
        }
        getline(fp, temp[8]);
        ch = fp.get();

        while (ch != ':')
        {
            ch = fp.get();
        }
        getline(fp, temp[9]);
        ch = fp.get();

        /* 使用 尾插法 对head进行添加节点 */
        stunode temp1, p;
        if ((temp1 = new struct stulist) == NULL)
        {
            printf("创建失败,内存不足。");
        }
        temp1->next = NULL;
        (temp1->stu).assignstudent(temp);

        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp1;

        /* 读取学生的课程信息 */
        while (ch != ':')
        {
            ch = fp.get();
        }
        while ((ch = fp.get()) != '\n')
        {
            ch = fp.get();
            ch = fp.get();
            ch = fp.get(); //此时ch==课程编号的最后一位

            subnode temp0, p1;
            if ((temp0 = new struct sublist) == NULL)
            {
                printf("创建失败,内存不足。");
            }
            temp0->next = NULL;
            temp0->subject = (int)(ch - 48);

            p1 = (temp1->stu).getsub();
            while (p1->next != NULL)
            {
                p1 = p1->next;
            }
            p1->next = temp0;

            /* 读掉编号后的' ' */
            ch = fp.get();
        }
        ch = fp.get();
    }
    fp.close();
    return head;
}

/* 使用 尾插法 对某学生的课程情况进行编辑 */
subnode InsertAtEnd(subnode l, int value)
{
    subnode temp, p;
    if ((temp = (subnode)malloc(sizeof(int))) == NULL)
    {
        printf("创建失败,内存不足。");
    }
    temp->next = NULL;
    temp->subject = value; //为新增的节点赋值

    p = l;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;

    return l;
}

/* 添加一个学生的信息 */
stunode InsertAtEnd_student(stunode head)
{
    /* 使用 尾插法 对head进行添加节点 */
    stunode temp, p;
    if ((temp = new struct stulist) == NULL)
    {
        printf("创建失败,内存不足。");
    }
    temp->next = NULL;
    (temp->stu).assignwithkbhit_student();

    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;

    return head;
}

void Print_suball(sub *sublist_)
{
    for (int i = 0; i < num_of_sub; i++)
    {
        cout << "  name of subject : " << suball[i].getname() << endl;
        cout << "number of subject : " << suball[i].getnum() << endl;
        cout << "  time of subject : " << suball[i].gettime() << endl;
        cout << " score of subject : " << suball[i].getscore() << endl;
        cout << endl;
    }
}

string Find_Subnum_From_Sunname(string subsubnum)
{
    for (int i = 0; i < num_of_sub; i++)
    {
        if (suball[i].getnum() == subsubnum)
        {
            return suball[i].getname();
        }
    }
    return "No_Such_Subnum";
}

void Print_Onestudent(stunode head)
{
    cout << "     name : " << (head->stu).getname() << endl;
    cout << "   number : " << (head->stu).getnum() << endl;
    cout << "   gender : " << (head->stu).getgender() << " ( 0:girl , 1:boy )" << endl;
    cout << "    birth : " << (head->stu).getyear() << "-" << (head->stu).getmonth() << "-" << (head->stu).getday() << endl;
    cout << "institute : " << (head->stu).getinstitute() << endl;
    cout << "    major : " << (head->stu).getmajor() << endl;
    cout << "    grade : " << (head->stu).getgrade() << endl;
    cout << "    class : " << (head->stu).getclas() << endl;
    cout << endl;
}

void Print_stuall_Name_Num(stunode head)
{
    stunode p = head;
    while (p->next != NULL)
    {
        cout << "     name : " << (p->next->stu).getname() << endl;
        cout << "   number : " << (p->next->stu).getnum() << endl;
        cout << endl;

        p = p->next;
    }
    cout << endl;
}

void Print_stuall_Only_Num(stunode head)
{
    stunode p = head;
    int count = 0;
    while (p->next != NULL)
    {
        count++;

        cout << "   number" << count << " : " << ((p->next)->stu).getnum() << endl;

        p = p->next;
    }
    cout << endl;
}

void Print_stu_of_sub(subnode head)
{
    subnode p = head;
    while (p->next != NULL)
    {
        cout << "  name of subject : " << suball[(p->next)->subject].getname() << endl;
        cout << "number of subject : " << suball[(p->next)->subject].getnum() << endl;
        cout << endl;

        p = p->next;
    }
}

stunode Find_from_Num_of_Student(stunode head, string num_to_be_find)
{
    stunode p = head;
    while (p->next != NULL)
    {
        if (((p->next)->stu).getnum() == num_to_be_find)
        {
            return p->next;
        }
        p = p->next;
    }
    return NULL;
}

void Save_Student_information(stunode head)
{
    ofstream fp;
    fp.open("student.txt", std::ios::app);
    if (fp.is_open())
    {
        fp << "     name :" << (head->stu).getname() << endl;
        fp << "   number :" << (head->stu).getnum() << endl;
        fp << "   gender :" << (head->stu).getgender() << endl;
        fp << "    birth :" << (head->stu).getyear() << "-" << (head->stu).getmonth() << "-" << (head->stu).getday() << endl;
        fp << "institute :" << (head->stu).getinstitute() << endl;
        fp << "    major :" << (head->stu).getmajor() << endl;
        fp << "    grade :" << (head->stu).getgrade() << endl;
        fp << "    class :" << (head->stu).getclas() << endl;

        /* 打印某学生所选学科 */
        fp << " subjects :";
        subnode p1 = head->stu.getsub();
        while (p1->next != NULL)
        {
            fp << (suball[(p1->next)->subject]).getnum() << " ";
            p1 = p1->next;
        }
        fp << endl;

        /* 最后多输出一个 '\n' */
        fp << endl;

        fp.close();
    }
}