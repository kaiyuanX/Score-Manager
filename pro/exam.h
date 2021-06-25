#include "data.h"

#define Default_Count_of_Student 100

/* Return next prime; assume N >= 10 */
static int NextPrime(int N)
{
    int i;

    if (N % 2 == 0)
        N++;
    for (;; N += 2)
    {
        for (i = 3; i * i <= N; i += 2)
            if (N % i == 0)
                goto ContOuter; /* Sorry about this! */
        return N;
    ContOuter:;
    }
}

enum KindOfEntry
{
    // hashtable 每个位置的状态
    // 0 1 2
    Legitimate, //使用中
    Empty,      //空的
    Deleted     //删除
};

/* 考试成绩信息 */
/* 一个节点存储一个学生的一门课程 */
/* 一个单链表存储一个学生的所有课程 */
struct examlist
{
    string studentnumber;
    string subject;
    int score;
    struct examlist *next;
};

typedef struct examlist *examnode;

/* 以散列表的形式存储不同学生的所有成绩 */
/* 采用平方探测寻址法 */
class result
{
private:
public:
    /* 整个表的大小为 size */
    /* 根据平方探测寻址法的原则 , 当表小于 size/2时就当做满了 */
    /* 所以实际只能存储 size/2 个人的考试信息 */
    int size;
    
    /* 表头 */
    /* 每个元素为 examnode */
    examnode *htable;
    
    /* 记录表中每个元素的状态 */
    int *status;

    /* 默认建立一个存储 100 人的表 */
    result(int size_ = NextPrime(Default_Count_of_Student * 2));

    /* 保存 */
    void Save_Exam_Information();

    /* 初始化 */
    void Resultread();
};

/* 散列的方式 */
int Hash(string stunum, int size);

/* 元素查找 , 返回元素所在位置 */
int Find_Hash(string Key, result *hashtable);

/* 查询 */
void Get_Score(int key, result *hashtable);

/* 元素添加 */
void Insert_Hash(stunode head, string stunum, result *hashtable);
