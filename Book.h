#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>
#include <Windows.h>
#include <fstream>
class Book {
public:
    std::string name;       //书名
    std::string contact;    //书的内容
    long int pages[4000];   //书的页码
    long int chapter[500];  //书的章节总数
    void Named(std::string names);
    void readTxt(std::string file);//读取书的内容
};












#endif