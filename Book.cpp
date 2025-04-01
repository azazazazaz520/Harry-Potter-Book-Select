#include "Book.h"
using namespace std;

void Book::Named(string names)
{
	name = names;
}

void Book::readTxt(string file)
{
	int i = 0;               //记录章节变量
	bool flag1 = false;
	fstream infile;           //创建infile对象
	infile.open(file.data(), ios::in);
	char c[2];
	while (!infile.eof())
	{
		c[1] = '\0';
		infile.read(c, 1);
		if (c[0] == '\n')       //当读取到回车时
		{
			flag1 = true;        //记录下该字符
		}
		if (flag1 == true)
		{
			if (c[0] >= 0 && c[0] <= 9)        //如果上个字符是回车，并且这个字符是0-9之间的数
			{
				c[0] = '@';					   //记录下页码				
			}
			else if (c[0] != '\n')
			{
				flag1 = false;					
			}
		}
		contact += c[0];


	}
	infile.close();

	//将章节对应的位置存入chaptor中

	size_t fi = contact.find("Chaptor", 0);
	if (fi == contact.npos)
	{
		fi = contact.find("CHAPTER", 0);
		while (fi != contact.npos)
		{
			chapter[i++] = fi;
			fi = contact.find("CHAPTER", fi + 1);
		}
	}
	else
	{
		while (fi != contact.npos)
		{
			chapter[i++] = fi;
			fi = contact.find("Chaptor", 0);
		}
	}

	//将所有页码的位置存入pages变量中

	size_t fi1 = contact.find("@", 0);
	i = 0;
	while (fi1 != contact.npos)
	{
		pages[i++] = fi1;
		fi1 = contact.find("@", fi1 + 1);
	}


}
