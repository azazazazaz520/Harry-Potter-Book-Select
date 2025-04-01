#include "Book.h"
#include "Search.h"
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem; 
using namespace std;

int main()
{
    //int i = 0, j = 0, k = 0, m = 0;
    Book book[8];            //定义8本书
    //int begintime, endtime;//用于处理程序的运行时间
    cout << "正在加载书目..." << endl;
    fs::path exePath = fs::absolute(fs::current_path());
    std::string path_string = exePath.string(); 
    book[0].Named("J.K. Rowling - HP 0 - Harry Potter Prequel");
    cout << path_string + "\\J.K. Rowling - HP 0 - Harry Potter Prequel.txt" << endl;
    book[0].readTxt(path_string + "\\J.K. Rowling - HP 0 - Harry Potter Prequel.txt");
    book[1].Named("HP7--Harry_Potter_and_the_Deathly_Hallows_Book_7_");
    cout << path_string + "\\HP7--Harry_Potter_and_the_Deathly_Hallows_Book_7_.txt" << endl;
    book[1].readTxt(path_string + "\\HP7--Harry_Potter_and_the_Deathly_Hallows_Book_7_.txt");
    book[2].Named("J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban");
    cout << path_string + "\\J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban.txt" << endl;
    book[2].readTxt(path_string + "\\J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban.txt");
    book[3].Named("HP2--Harry_Potter_and_the_Chamber_of_Secrets_Book_2_");
    cout << path_string + "\\HP2--Harry_Potter_and_the_Chamber_of_Secrets_Book_2_.txt" << endl;
    book[3].readTxt(path_string + "\\HP2--Harry_Potter_and_the_Chamber_of_Secrets_Book_2_.txt");
    book[4].Named("J.K. Rowling - Quidditch Through the Ages");
    cout << path_string + "\\J.K. Rowling - Quidditch Through the Ages.txt" << endl;
    book[4].readTxt(path_string + "\\J.K. Rowling - Quidditch Through the Ages.txt");
    book[5].Named("J.K. Rowling - The Tales of Beedle the Bard");
    cout << path_string + "\\J.K. Rowling - The Tales of Beedle the Bard.txt" << endl;
    book[5].readTxt(path_string + "\\J.K. Rowling - The Tales of Beedle the Bard.txt");
    book[6].Named("J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince");
    cout << path_string + "\\J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince.txt" << endl;
    book[6].readTxt(path_string + "\\J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince.txt");
    book[7].Named("J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire");
    cout << path_string + "\\J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire.txt" << endl;
    book[7].readTxt(path_string + "\\J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire.txt");
    Search(book);

}
