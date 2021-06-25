# Student Test Score Information Management

### Description
**My piece of work from C++ assignment.** Hope you like it.

### Main Data
* class sub
* class student
* class result

### Structure_Chart
* [subject](structure_chart/subject.png)
* [student](structure_chart/student.png)
* [score](structure_chart/score.png)

### Reference
* student.txt 记录登记过的所有人员信息 ( subhead 项中每个编号后面接一个空格)
* sub.txt     记录所有学科的信息
* score.txt   记录登记过的考试成绩
* 在交互界面选择 "5" 或 "8" 后 , 修改才会在 文件 中更新
* 在 <exam.h> 中修改管理人数 : `#define Default_Count_of_Student 100`( 默认 100 )
* 更新 sub.txt 后 , 记得修改 <data.h> 中总学科的数量 : `#define num_of_sub 6`( 目前 6 门学科 )

### Notice
* 建议 3 个文件不要手动修改 ( 除非你跟我一样 , 熟悉文件读取规则 )
* class result 中数据成员的访问权限全为 public , 没有格外的原因 , 单纯太懒
* **还有一件事 : new 的所有对象没有手动释放 , 在于人太懒 , 以后保证不会这样 。( 大家不要模仿 )**
  
*( 英语水平有限 , 用中文写这部分 )*

### Postscript
**The program has not yet lived up to expectations, strive for constant updates**
