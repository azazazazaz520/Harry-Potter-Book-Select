#include "Book.h"
using namespace std;

void Book::Named(string names)
{
	name = names;
}

void Book::readTxt(string file)
{
	int i = 0;               //��¼�½ڱ���
	bool flag1 = false;
	fstream infile;           //����infile����
	infile.open(file.data(), ios::in);
	char c[2];
	while (!infile.eof())
	{
		c[1] = '\0';
		infile.read(c, 1);
		if (c[0] == '\n')       //����ȡ���س�ʱ
		{
			flag1 = true;        //��¼�¸��ַ�
		}
		if (flag1 == true)
		{
			if (c[0] >= 0 && c[0] <= 9)        //����ϸ��ַ��ǻس�����������ַ���0-9֮�����
			{
				c[0] = '@';					   //��¼��ҳ��				
			}
			else if (c[0] != '\n')
			{
				flag1 = false;					
			}
		}
		contact += c[0];


	}
	infile.close();

	//���½ڶ�Ӧ��λ�ô���chaptor��

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

	//������ҳ���λ�ô���pages������

	size_t fi1 = contact.find("@", 0);
	i = 0;
	while (fi1 != contact.npos)
	{
		pages[i++] = fi1;
		fi1 = contact.find("@", fi1 + 1);
	}


}
