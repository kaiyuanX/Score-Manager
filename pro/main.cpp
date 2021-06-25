#include "exam.h"

/* 从sub。txt中读取的信息存储在这里面 */
/* 目前只有6门课程 */
sub suball[num_of_sub];

/* 用户交互函数 */
void User_interaction(stunode stuhead, result *hashtable);

int main()
{
    /* 窗口初始化 */
    system("title Student Test Score Information Management");
    system("color 70");

    /* 读取所有的课程信息 */
    Subread(suball);

    /* 读取所有已知的学生信息 */
    stunode stuhead = new struct stulist;
    stuhead->next = NULL;
    stuhead = Studentread(stuhead);

    /* 默认可容纳 100 人的考试成绩 */
    result *hashtable = new result;
    hashtable->Resultread();

    /* 交互 */
    User_interaction(stuhead, hashtable);

    return 0;
}

void User_interaction(stunode stuhead, result *hashtable)
{
    cout << "-----------------------------------------------Welcome TO Transcript-----------------------------------------------\n";
    cout << endl;

    int user_choice;
    int temp_int;
    string student_number_to_be_find;
    stunode temp_stunode = NULL;

    do
    {
        cout << "---------------根据需求键入数字---------------\n";
        cout << "1.查看所有科目的详细信息\n";
        cout << "2:查看所有学生的详细信息\n";
        cout << "3:查看某学生的所选科目\n";
        cout << "4:添加一个学生的信息\n";
        cout << "5:保存学生信息\n";
        cout << "6.查询一个学生的考试成绩\n";
        cout << "7:填写考试成绩\n";
        cout << "8:保存成绩信息\n";

        cout << "0:退出\n";
        cout << endl;

        cin >> user_choice;
        cout << endl;

        switch (user_choice)
        {
        case 0:
            cout << "Waiting to qiut...." << endl;
            return;
            break;

        case 1:
            Print_suball(suball);
            cout << endl;
            break;

        case 2:
            Print_stuall(stuhead);
            cout << endl;
            break;

        case 3:
            cout << "Input the number of the student that you want to find." << endl;
            cin >> student_number_to_be_find;
            temp_stunode = Find_from_Num_of_Student(stuhead, student_number_to_be_find);
            if (temp_stunode != NULL)
            {
                Print_stu_of_sub(temp_stunode->stu.getsub());
                cout << endl;
            }
            else
            {
                cout << "No such student." << endl;
            }
            break;

        case 4:
            InsertAtEnd_student(stuhead);
            cout << "Job done." << endl;
            cout << endl;
            break;

        case 5:
            Save_Student_information(stuhead);
            cout << "Job done." << endl;
            cout << endl;
            break;

        case 6:
            Print_stuall_Only_Num(stuhead);
            cout << "Input the number of the student which you want to check." << endl;
            cin >> student_number_to_be_find;
            cout << endl;
            temp_int = Find_Hash(student_number_to_be_find, hashtable);
            Get_Score(temp_int, hashtable);
            cout << endl;
            break;

        case 7:
            Print_stuall_Only_Num(stuhead);
            cout << "Input the number of the student which you want to fill." << endl;
            cin >> student_number_to_be_find;
            cout << endl;
            Insert_Hash(stuhead, student_number_to_be_find, hashtable);
            cout << "Job done." << endl;
            cout << endl;
            break;

        case 8:
            hashtable->Save_Exam_Information();
            cout << endl;
            break;

        default:
            cout << "Worry input!!!" << endl;
            break;
        }

        system("pause");
        system("cls");
    } while (1);
}
