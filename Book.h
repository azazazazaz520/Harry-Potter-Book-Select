#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>
#include <Windows.h>
#include <fstream>
class Book {
public:
    std::string name;       //����
    std::string contact;    //�������
    long int pages[4000];   //���ҳ��
    long int chapter[500];  //����½�����
    void Named(std::string names);
    void readTxt(std::string file);//��ȡ�������
};












#endif