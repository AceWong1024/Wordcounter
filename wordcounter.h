#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <dialog.h>
#include <vector>
#include <qapplication.h>
#include <dirent.h>
#include <sys/types.h>
#include <fnmatch.h>
using namespace std;
class Wordcounter{
private:
//    FILE *fp;
public:
    Wordcounter(){

    }
    Wordcounter(int argc,char** argv){
//        app=new QApplication(argc,argv);
    }
    int isValid(char* str);
    static int countchars(const char* str);
    static int countwords(const char* str);
    static int countlines(const char* str);
    static int* counta(const char* str);
    static vector<int> counts(const char* str);
    int countx(int,char**);
};

#endif // WORDCOUNTER_H
