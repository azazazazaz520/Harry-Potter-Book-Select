#ifndef _SEARCH_H_
#define _SEARCH_H_
#include <Windows.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <time.h>

long int map[8][2000];            //ÿһ������Ҫ�����ĵ��ʵľ����λ��
int cha[8][2000];                 //ÿһ����Ҫ�����ĵ������ھ�����½�
int pag[8][2000];                 //ÿһ����Ҫ�����ĵ������ھ����ҳ��

struct Numx//�����
{
	int book;//��Ӧ�ľ�����Ŀ
	int local;//��Ӧ�ľ���λ��
};
Numx numx[16000];//����һ����������������ָ����map�Ķ�ά���飬��map�Ķ�ά������һ����Ŵ���
int outnum;
const void Search(const Book* book)
{
	int i = 0, j = 0, m = 0, k = 0;         //j �½�,m ҳ��
	std::string finding, midf;         ////finding���������ݣ�midf���������ݣ�finding=�ո�+midf
	int begintime, endtime;//���ڴ�����������ʱ��

	/*������������*/
	system("cls");      //�����Ļ
	std::cout << "�ѳɹ����ع�������ϵ�д���" << std::endl << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "��������Ҫ�����ĵ��ʣ�" << std::endl;
	//�������
	std::cin >> midf;
	finding += midf;
	begintime = clock();//��¼������ʼʱ��

	std::cout << std::left << std::setw(10) << "��ţ�"
		<< std::setw(15) << "����/������"
		<< std::setw(10) << "ҳ�룺"
		<< std::setw(10) << "�½ڣ�"
		<< "������" << std::endl;
	std::cout << std::right << std::endl;

	for (int l = 0; l < 8; l++)        //�����˱���
	{
		i = 0;
		j = 0; m = 0;            //j���½ڣ�m��ҳ��
		size_t fi = book[l].contact.find(finding, 0);//��������λ��
		while (fi != book[l].contact.npos)
		{
			map[l][i] = fi;
			while (true)
			{
				if (fi > book[l].chapter[j] && fi < book[l].chapter[j + 1])
					break;
				j++;
			}
			cha[l][i] = j;//�����λ�ö�Ӧ���½�
			while (true)
			{
				if (fi > book[l].pages[m] && fi < book[l].pages[m + 1])
					break;
				m++;
			}
			pag[l][i] = m;
			numx[k].book = l;//ÿ����������Ӧ�ľ���map���
			numx[k].local = i;//ÿ����������Ӧ�ľ���map���
			if (k < 10)
			{
				std::cout << std::left << std::setw(10) << k
					<< std::setw(15) << midf
					<< std::setw(10) << pag[l][i]
					<< std::setw(10) << cha[l][i]
						<< book[l].name << std::endl;
			}
			i++; k++;        //����
			fi = book[l].contact.find(finding, fi + 1);
		}
		
		



	}
	endtime = clock();       //��������ʱ��

	if (k == 0)
	{
		std::cout << "�޽��(����-2�����µĵ���)" << std::endl;
		std::cin >> outnum;
		if (outnum == -2)
		{
			Search(book);
		}
	}
	else
	{
		std::cout << "Running Time��" << endtime - begintime << "ms" << std::endl;
		std::cout << "ֻ��ʾǰ10��" << std::endl;
		std::cout << "�ܹ���:" << k - 1 << "��" << std::endl;

		/*����������*/
		do
		{
			std::cout << std::endl << "������Ҫ�鿴����ţ�������ʾ�������ڵľ��ӡ�(��-1�˳�,-2�����µĵ���)" << std::endl;
			std::cin >> outnum;
			if (outnum > k - 1)
			{
				std::cout << "�������Ų�����" << std::endl;
				continue;
			}
			if (outnum == -1)
				break;
			if (outnum == -2)
			{
				Search(book);
			}
			else
			{
				/*��ʾfinding������100������,���磺book[1].contact[map[1][0]]*/
				int firstlocal, endlocal;
				firstlocal = book[numx[outnum].book].contact.find_last_of('.', map[numx[outnum].book][numx[outnum].local]);
				endlocal = book[numx[outnum].book].contact.find_first_of('.', map[numx[outnum].book][numx[outnum].local]);

				for (i = firstlocal + 1; i < endlocal + 1; i++)
					std::cout << book[numx[outnum].book].contact[i];
				std::cout << std::endl << std::endl;
			}
		} while (true);
	}
	

}















#endif