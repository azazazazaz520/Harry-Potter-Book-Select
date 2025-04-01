#ifndef _SEARCH_H_
#define _SEARCH_H_
#include <Windows.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <time.h>

long int map[8][2000];            //每一本书内要搜索的单词的具体的位置
int cha[8][2000];                 //每一本书要搜索的单词所在具体的章节
int pag[8][2000];                 //每一本书要检索的单词所在具体的页码

struct Numx//总序号
{
	int book;//对应的具体数目
	int local;//对应的具体位置
};
Numx numx[16000];//定义一个总索引，总索引指向了map的二维数组，将map的二维数组用一个序号储存
int outnum;
const void Search(const Book* book)
{
	int i = 0, j = 0, m = 0, k = 0;         //j 章节,m 页码
	std::string finding, midf;         ////finding是搜索内容，midf是输入内容，finding=空格+midf
	int begintime, endtime;//用于处理程序的运行时间

	/*输入搜索内容*/
	system("cls");      //清空屏幕
	std::cout << "已成功加载哈利波特系列丛书" << std::endl << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "请输入你要检索的单词：" << std::endl;
	//输入操作
	std::cin >> midf;
	finding += midf;
	begintime = clock();//记录搜索开始时间

	std::cout << std::left << std::setw(10) << "序号："
		<< std::setw(15) << "人名/地名："
		<< std::setw(10) << "页码："
		<< std::setw(10) << "章节："
		<< "书名：" << std::endl;
	std::cout << std::right << std::endl;

	for (int l = 0; l < 8; l++)        //遍历八本书
	{
		i = 0;
		j = 0; m = 0;            //j是章节，m是页码
		size_t fi = book[l].contact.find(finding, 0);//搜索具体位置
		while (fi != book[l].contact.npos)
		{
			map[l][i] = fi;
			while (true)
			{
				if (fi > book[l].chapter[j] && fi < book[l].chapter[j + 1])
					break;
				j++;
			}
			cha[l][i] = j;//输出该位置对应的章节
			while (true)
			{
				if (fi > book[l].pages[m] && fi < book[l].pages[m + 1])
					break;
				m++;
			}
			pag[l][i] = m;
			numx[k].book = l;//每个总索引对应的具体map书号
			numx[k].local = i;//每个总索引对应的具体map序号
			if (k < 10)
			{
				std::cout << std::left << std::setw(10) << k
					<< std::setw(15) << midf
					<< std::setw(10) << pag[l][i]
					<< std::setw(10) << cha[l][i]
						<< book[l].name << std::endl;
			}
			i++; k++;        //自增
			fi = book[l].contact.find(finding, fi + 1);
		}
		
		



	}
	endtime = clock();       //搜索结束时间

	if (k == 0)
	{
		std::cout << "无结果(输入-2搜索新的单词)" << std::endl;
		std::cin >> outnum;
		if (outnum == -2)
		{
			Search(book);
		}
	}
	else
	{
		std::cout << "Running Time：" << endtime - begintime << "ms" << std::endl;
		std::cout << "只显示前10项" << std::endl;
		std::cout << "总共有:" << k - 1 << "项" << std::endl;

		/*输出搜索结果*/
		do
		{
			std::cout << std::endl << "输入你要查看的序号，即可显示单词所在的句子。(按-1退出,-2搜索新的单词)" << std::endl;
			std::cin >> outnum;
			if (outnum > k - 1)
			{
				std::cout << "输入的序号不存在" << std::endl;
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
				/*显示finding附近的100个单词,例如：book[1].contact[map[1][0]]*/
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