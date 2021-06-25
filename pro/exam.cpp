#include "exam.h"

result::result(int size_)
{
    /* 比 size_ 大的最小素数 */
    int size0 = NextPrime(size_);

    size = size0;

    htable = new examnode[size0];
    for (int i = 0; i < size0; i++)
    {
        htable[i] = new struct examlist;
        htable[i]->next = NULL;
    }

    status = new int[size0];
    for (int i = 0; i < size0; i++)
    {
        status[i] = Empty;
    }
}

int Hash(string stunum, int size)
{
    int key = std::stoi(stunum);
    return key % size;
}

int Find_Hash(string Key, result *hashtable)
{
    int CurrentPos;
    int CollisionNum;

    CollisionNum = 0;
    CurrentPos = Hash(Key, hashtable->size);

    while ((hashtable->status)[CurrentPos] != Empty &&
           (hashtable->htable)[CurrentPos]->studentnumber != Key)
    {
        CurrentPos += 2 * ++CollisionNum - 1; //Currentpos随循环 +1 +3 +5 +7 +9
        if (CurrentPos >= hashtable->size)
        {
            CurrentPos -= hashtable->size;
        }
    }

    return CurrentPos;
}

void Insert_Hash(stunode head, string stunum, result *hashtable)
{
    stunode temp_student = Find_from_Num_of_Student(head, stunum);
    if (temp_student == NULL)
    {
        cout << "Can not find this student." << endl;
        return;
    }

    int Pos;
    Pos = Find_Hash(stunum, hashtable);
    if (hashtable->status[Pos] != Legitimate)
    {
        /* OK to insert here */
        hashtable->status[Pos] = Legitimate;
        hashtable->htable[Pos]->studentnumber = stunum;
    }

    examnode temp_examnode = hashtable->htable[Pos];
    subnode p = (temp_student->stu).getsub();
    while (p->next != NULL)
    {
        temp_examnode->next = new struct examlist;

        temp_examnode->next->studentnumber = stunum;
        temp_examnode->next->subject = suball[p->next->subject].getnum();
        cout << "Input the score " << temp_student->stu.getname() << " gain for his " << suball[p->next->subject].getname() << endl;
        cin >> temp_examnode->next->score;

        p = p->next;
        temp_examnode = temp_examnode->next;
    }
    temp_examnode->next = NULL;
}

void Get_Score(int key, result *hashtable)
{
    if (hashtable->status[key] != Legitimate)
    {
        cout << "Can not find this student" << endl;
        return;
    }

    examnode tempexamnode = (hashtable->htable)[key];

    while (tempexamnode->next != NULL)
    {
        //suball[std::stoi(tempexamnode->next->next->subject)].getname()
        cout << tempexamnode->next->subject << " : " << tempexamnode->next->score << endl;
        tempexamnode = tempexamnode->next;
    }
}

void result::Save_Exam_Information()
{
    ofstream fp("score.txt");
    if (fp.is_open())
    {
        examnode temp_examnode = NULL;

        for (int i = 0; i < size; i++)
        {
            if (status[i] == Legitimate)
            {
                fp << htable[i]->studentnumber << endl;

                temp_examnode = htable[i];
                while (temp_examnode->next != NULL)
                {
                    fp << temp_examnode->next->subject << ":" << temp_examnode->next->score << endl;
                    temp_examnode = temp_examnode->next;
                }
                fp << endl;
            }
        }

        cout << "Job done." << endl;
        fp.close();
    }
}

int Insert_Hash_(string stunum, result *hashtable)
{
    int Pos;
    Pos = Find_Hash(stunum, hashtable);
    if (hashtable->status[Pos] != Legitimate)
    {
        /* OK to insert here */
        hashtable->status[Pos] = Legitimate;
        hashtable->htable[Pos]->studentnumber = stunum;
    }

    return Pos;
}

void result::Resultread()
{
    /* score.txt里面记录了所有的成绩信息 */
    ifstream fp;
    fp.open("score.txt");

    string temp_s;
    char ch;
    int temp_n;
    int key;

    while (getline(fp, temp_s), (ch = fp.get()) != EOF)
    {
        key = Insert_Hash_(temp_s, this);
        htable[key]->studentnumber = temp_s;

        examnode p = htable[key], temp_examnode;
        while (ch != '\n')
        {
            ch = fp.get();
            ch = fp.get();
            ch = fp.get(); // ch == 'num'
            temp_n = (int)ch - 48;
            ch = fp.get(); // ch == ':'

            temp_examnode = new struct examlist;
            temp_examnode->next = NULL;
            temp_examnode->subject = suball[temp_n].getnum();
            fp >> temp_examnode->score;

            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp_examnode;

            ch = fp.get(); // ch == '\n'
            ch = fp.get();
        }
    }

    fp.close();
}