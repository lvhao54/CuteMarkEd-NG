# 学生管理系统

## 主函数

```cpp

int main()	                //主函数
{
	vector<Score> v;
	Score stu;
	int m;

	while (1)
	{
		cout << "1.添加学生" << endl;		   //输出操作提示
		cout << "2.修改学生" << endl;
		cout << "3.平均分" << endl;
		cout << "4.按平均分排序" << endl;
		cout << "5.按学号查询" << endl;
		cout << "6.按姓名查询" << endl;
		cout << "7.按班级查询" << endl;
		cout << "8.按学期查询" << endl;
		cout << "9.查询不及格名单" << endl;
		cout << "10.保存" << endl;
		cout << "0.退出" << endl;

		cin >> m;                         //接受要操作的步骤 
		if (m <= 10 && m >= 0) {
			switch (m)
			{
			case 1: stu.insert(&v); break;          //选1 添加学生
			case 2: stu.change(&v); break;     	      //选2 修改学生
			case 3: stu.Avg(&v); break;			//选3 学生平均分
			case 4: stu.sort(&v); break;			//选4 按平均分排序
			case 5: stu.find(&v); break;			//选5 按学号查询
			case 6: stu.find1(&v); break;			//选6 按姓名查询
			case 7: stu.find2(&v); break;			//选7 按班级查询
			case 8: stu.find3(&v); break;			//选8 按学期查询
			case 9: stu.findn(&v);	break;	 //选9 查询不及格名单
			case 10: stu.save(&v); break;			//选10 保存
			case 0:  exit(0);	                //选0结束保存
			}
			cout << endl << endl << "操作完毕，请再次选择！" << endl;
		}
		else cout << endl << endl << "选择错误，请再次选择！" << endl;

	}

}
```



## Struct

定义学生类Student，定义分数类Score继承学生

```cpp
class Student
{
public:
	string num;//学号 
	string name;//姓名 
	string sex;//性别
	string cla;//班级
public:
	Student() {}
	Student(string a, string b, string c, string d) : num(a), name(b), sex(c), cla(d){ }
	Student(const Student& S)
	{
		num = S.num;
		name = S.name;
		sex = S.sex;
		cla = S.cla;
	}
	~Student() {}
};


class Score : public Student
{
public:
	Score();
	Score(string a, string b, string c, string d, double e, double f, double g, double h, double i);
	Score(const Score& C)
	{
		num = C.num;
		name = C.name;
		sex = C.sex;
		cla = C.cla;
		chinese = C.chinese;
		mathematics = C.mathematics;
		english = C.english;
		avg = C.avg;
		Semester = C.Semester;
	}
	~Score();
	void insert(vector<Score> *v);
	void change(vector<Score> *v);
	void Avg(vector<Score> *v);
	void sort(vector<Score> *v);
	void find(vector<Score> *v);
	void find1(vector<Score> *v);
	void find2(vector<Score> *v);
	void find3(vector<Score> *v);
	void findn(vector<Score> *v);

	void display(vector<Score> *v);
	void Delete(vector<Score> *v);
	void save(vector<Score> *v);

private:
	double chinese;		// 语文
	double mathematics;	// 数学
	double english;		// 英语
	double avg;			// 平均分
	double Semester;	// 学期
};
```

## 学生信息插入

```cpp
void Score::insert(vector<Score> *v)
{
	Score s;
	cout << "请输入学生的信息:" << endl;
	cout << "学号 姓名 性别 班级 语文 数学 英语 取得学期" << endl;
	cin >> s.num;
	cin >> s.name;
	cin >> s.sex;
	cin >> s.cla;
	cin >> s.chinese;
	cin >> s.mathematics;
	cin >> s.english;
	cin >> s.Semester;

	for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
	{
		if ((*i).num == s.num) {
			cout << "已有该学生。" << endl;
			return;
		}
	}
	v->push_back(s);
}
```

## 显示所有学生信息

```cpp
void Score::display(vector<Score> *v)//显示 
{
	for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
	{
		cout << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << (*i).chinese
			<< (*i).mathematics << (*i).english << (*i).avg << (*i).Semester << endl;
	}
}

```

## 通过学号修改学生信息

```cpp
void Score::change(vector<Score> *v)	// 修改
{
	string s;
	cout << "请输入要修改的学生学号：";
	cin >> s;

	for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
	{
		if (s == (*i).num)
		{
			cout << "请输入学生的成绩:" << endl;
			cout << "语文 数学 英语" << endl;
			cin >> (*i).chinese;
			cin >> (*i).mathematics;
			cin >> (*i).english;
		}
	}
	cout << "修改成功" << endl;
}
```

## 统计学生平均分

```cpp
void Score::Avg(vector<Score>* v)
{
	for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
	{
		(*i).avg = ((*i).chinese + (*i).mathematics + (*i).english) / 3;
	}
	//cout << "平均成绩：" << a << endl;
}
```

## 对所有学生进行排序

```cpp

void Score::sort(vector<Score> *v)
{
	for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
	{
		for (vector<Score>::iterator j = v->begin(); j != v->end(); j++)
		{
			if ((*i).avg < (*j).avg)
			{
				double a;
				a = (*i).avg;
				(*i).avg = (*j).avg;
				(*j).avg = a;
			}
		}
	}
	cout << "排序成功" << endl;
}
```

## 根据学号查找对应学生

```cpp
void Score::find(vector<Score>* v)
{
	string s;
	cout << "请输入要查询的学生学号：";
	cin >> s;

	for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
	{
		if (s == (*i).num)
		{
			cout << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << "\t" << (*i).chinese
				<< "\t" << (*i).mathematics << "\t" << (*i).english << "\t" << (*i).avg << endl;
		}
	}
	cout << "查询成功" << endl;
}
```

## 根据学生姓名查找对应学生

```cpp

void Score::find1(vector<Score>* v)
{
	string s;
	cout << "请输入要查询的学生姓名：";
	cin >> s;

	for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
	{
		if (s == (*i).name)
		{
			cout << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << "\t" << (*i).chinese
				<< "\t" << (*i).mathematics << "\t" << (*i).english << "\t" << (*i).avg << endl;
		}
	}
	cout << "查询成功" << endl;
}
```

## 根据班级查找该班级所有学生

```cpp
void Score::find2(vector<Score>* v)
{
	string s;
	cout << "请输入要查询的学生班级：";
	cin >> s;

	for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
	{
		if (s == (*i).cla)
		{
			cout << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << "\t" << (*i).chinese
				<< "\t" << (*i).mathematics << "\t" << (*i).english << "\t" << (*i).avg << endl;
		}
	}
	cout << "查询成功" << endl;
}
```

## 根据学期查询该学期所有学生

```cpp

void Score::find3(vector<Score>* v)
{
	double s;
	cout << "请输入要查询的学生学期：";
	cin >> s;

	for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
	{
		if (s == (*i).Semester)
		{
			cout << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << "\t" << (*i).chinese
				<< "\t" << (*i).mathematics << "\t" << (*i).english << "\t" << (*i).avg << endl;
		}
	}
	cout << "查询成功" << endl;
}
```

## 保存学生信息到文件

```cpp
void Score::save(vector<Score>* v)
{
	fstream fio("test.txt", ios::app);
	for (auto i = v->begin(); i != v->end(); i++)
	{
		fio << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << "\t" << (*i).chinese
			<< "\t" << (*i).mathematics << "\t" << (*i).english << "\t" << (*i).avg << "\t" << (*i).Semester << endl;
	}
	fio.close();
}
```



## All

[TEST](https://Code.exe)

```cpp
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include <istream>

using namespace std;

//定义类
class Student
{
public:
    string num;//学号 
    string name;//姓名 
    string sex;//性别
    string cla;//班级
public:
    Student() {}
    Student(string a, string b, string c, string d) : num(a), name(b), sex(c), cla(d){ }
    Student(const Student& S)
    {
        num = S.num;
        name = S.name;
        sex = S.sex;
        cla = S.cla;
    }
    ~Student() {}

};
class Score : public Student
{
public:
    Score();
    Score(string a, string b, string c, string d, double e, double f, double g, double h, double i);
    Score(const Score& C)
    {
        num = C.num;
        name = C.name;
        sex = C.sex;
        cla = C.cla;
        chinese = C.chinese;
        mathematics = C.mathematics;
        english = C.english;
        avg = C.avg;
        Semester = C.Semester;
    }
    ~Score();
    void insert(vector<Score> *v);
    void change(vector<Score> *v);
    void Avg(vector<Score> *v);
    void sort(vector<Score> *v);
    void find(vector<Score> *v);
    void find1(vector<Score> *v);
    void find2(vector<Score> *v);
    void find3(vector<Score> *v);
    void findn(vector<Score> *v);

    void display(vector<Score> *v);
    void Delete(vector<Score> *v);
    void save(vector<Score> *v);

private:
    double chinese;        // 语文
    double mathematics;    // 数学
    double english;        // 英语
    double avg;            // 平均分
    double Semester;    // 学期
};

Score::Score()
{
}

Score::Score(string a, string b, string c, string d, double e, double f, double g, double h, double i)
{
    this->num = a;
    this->name = b;
    this->sex = c;
    this->cla = d;
    this->chinese = e;
    this->mathematics = f;
    this->english = g;
    this->avg = h;
    this->Semester = i;
}

Score::~Score()
{
}
//类外定义成员函数

// 插入学生信息
void Score::insert(vector<Score> *v)
{
    Score s;
    cout << "请输入学生的信息:" << endl;
    cout << "学号 姓名 性别 班级 语文 数学 英语 取得学期" << endl;
    cin >> s.num;
    cin >> s.name;
    cin >> s.sex;
    cin >> s.cla;
    cin >> s.chinese;
    cin >> s.mathematics;
    cin >> s.english;
    cin >> s.Semester;

    for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
    {
        if ((*i).num == s.num) {
            cout << "已有该学生。" << endl;
            return;
        }
    }
    v->push_back(s);
}

void Score::display(vector<Score> *v)//显示 
{
    for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
    {
        cout << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << (*i).chinese
            << (*i).mathematics << (*i).english << (*i).avg << (*i).Semester << endl;
    }
}

void Score::change(vector<Score> *v)    // 修改
{
    string s;
    cout << "请输入要修改的学生学号：";
    cin >> s;

    for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
    {
        if (s == (*i).num)
        {
            cout << "请输入学生的成绩:" << endl;
            cout << "语文 数学 英语" << endl;
            cin >> (*i).chinese;
            cin >> (*i).mathematics;
            cin >> (*i).english;
        }
    }
    cout << "修改成功" << endl;
}

void Score::Avg(vector<Score>* v)
{
    for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
    {
        (*i).avg = ((*i).chinese + (*i).mathematics + (*i).english) / 3;
    }
    //cout << "平均成绩：" << a << endl;
}

void Score::sort(vector<Score> *v)
{
    for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
    {
        for (vector<Score>::iterator j = v->begin(); j != v->end(); j++)
        {
            if ((*i).avg < (*j).avg)
            {
                double a;
                a = (*i).avg;
                (*i).avg = (*j).avg;
                (*j).avg = a;
            }
        }
    }
    cout << "排序成功" << endl;
}

void Score::find(vector<Score>* v)
{
    string s;
    cout << "请输入要查询的学生学号：";
    cin >> s;

    for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
    {
        if (s == (*i).num)
        {
            cout << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << "\t" << (*i).chinese
                << "\t" << (*i).mathematics << "\t" << (*i).english << "\t" << (*i).avg << endl;
        }
    }
    cout << "查询成功" << endl;
}
void Score::find1(vector<Score>* v)
{
    string s;
    cout << "请输入要查询的学生姓名：";
    cin >> s;

    for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
    {
        if (s == (*i).name)
        {
            cout << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << "\t" << (*i).chinese
                << "\t" << (*i).mathematics << "\t" << (*i).english << "\t" << (*i).avg << endl;
        }
    }
    cout << "查询成功" << endl;
}
void Score::find2(vector<Score>* v)
{
    string s;
    cout << "请输入要查询的学生班级：";
    cin >> s;

    for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
    {
        if (s == (*i).cla)
        {
            cout << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << "\t" << (*i).chinese
                << "\t" << (*i).mathematics << "\t" << (*i).english << "\t" << (*i).avg << endl;
        }
    }
    cout << "查询成功" << endl;
}
void Score::find3(vector<Score>* v)
{
    double s;
    cout << "请输入要查询的学生学期：";
    cin >> s;

    for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
    {
        if (s == (*i).Semester)
        {
            cout << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << "\t" << (*i).chinese
                << "\t" << (*i).mathematics << "\t" << (*i).english << "\t" << (*i).avg << endl;
        }
    }
    cout << "查询成功" << endl;
}

void Score::findn(vector<Score>* v)
{
    for (vector<Score>::iterator i = v->begin(); i != v->end(); i++)
    {
        if (60.0 > (*i).chinese || 60.0 > (*i).english || 60.0 > (*i).mathematics)
        {
            cout << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << "\t" << (*i).chinese
                << "\t" << (*i).mathematics << "\t" << (*i).english << "\t" << (*i).avg << endl;
        }
    }
    cout << "查询成功" << endl;
}

void Score::save(vector<Score>* v)
{
    fstream fio("test.txt", ios::app);
    for (auto i = v->begin(); i != v->end(); i++)
    {
        fio << (*i).num << "\t" << (*i).name << "\t" << (*i).sex << "\t" << (*i).cla << "\t" << (*i).chinese
            << "\t" << (*i).mathematics << "\t" << (*i).english << "\t" << (*i).avg << "\t" << (*i).Semester << endl;
    }
    fio.close();
}


int main()                    //主函数
{
    vector<Score> v;
    Score stu;
    int m;

    while (1)
    {
        cout << "1.添加学生" << endl;           //输出操作提示
        cout << "2.修改学生" << endl;
        cout << "3.平均分" << endl;
        cout << "4.按平均分排序" << endl;
        cout << "5.按学号查询" << endl;
        cout << "6.按姓名查询" << endl;
        cout << "7.按班级查询" << endl;
        cout << "8.按学期查询" << endl;
        cout << "9.查询不及格名单" << endl;
        cout << "10.保存" << endl;
        cout << "0.退出" << endl;

        cin >> m;                         //接受要操作的步骤 
        if (m <= 10 && m >= 0) {
            switch (m)
            {
            case 1: stu.insert(&v); break;          //选1 添加学生
            case 2: stu.change(&v); break;               //选2 修改学生
            case 3: stu.Avg(&v); break;            //选3 学生平均分
            case 4: stu.sort(&v); break;            //选4 按平均分排序
            case 5: stu.find(&v); break;            //选5 按学号查询
            case 6: stu.find1(&v); break;            //选6 按姓名查询
            case 7: stu.find2(&v); break;            //选7 按班级查询
            case 8: stu.find3(&v); break;            //选8 按学期查询
            case 9: stu.findn(&v);    break;     //选9 查询不及格名单
            case 10: stu.save(&v); break;            //选10 保存
            case 0:  exit(0);                    //选0结束保存
            }
            cout << endl << endl << "操作完毕，请再次选择！" << endl;
        }
        else cout << endl << endl << "选择错误，请再次选择！" << endl;

    }

}
```


