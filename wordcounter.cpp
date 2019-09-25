#include "wordcounter.h"


using namespace std;
int Wordcounter::isValid(char* str){
    if(!strcmp(str,"-c")){
        return 1;
    }else if (!strcmp(str,"-w")){
        return 2;
    }else if (!strcmp(str,"-l")){
        return 3;
    }else if (!strcmp(str,"-s")){
        return 4;
    }else if (!strcmp(str,"-a")){
        return 5;
    }else{
        cout << "Parameter error!" << endl;
        return -1;
    }
}

int Wordcounter::countchars(const char* str){
    char path[500];
    strcpy(path,get_current_dir_name());
    strcat(path,"/");
    strcat(path,str);

    FILE *fp;
    fp = fopen(path,"r");
    cout << path << endl;
    if(fp == NULL){
        cout << "open file error!" << endl;
        return -1;
    }
    char ch;
    int count = 0;
    while (!feof(fp)) {
        ch = getc(fp);//获取当前字符
        if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))              //发现一个单词
        {
            ++count;
        }
    }
//    cout << "chars:" << count << endl;
    return count;
}

int Wordcounter::countwords(const char* str){
    char path[500];
    strcpy(path,get_current_dir_name());
    strcat(path,"/");
    strcat(path,str);

    FILE *fp;
    fp = fopen(path,"r");
    cout << path << endl;
    if(fp == NULL){
        cout << "open file error!" << endl;
        return -1;
    }
    char ch;
    int count = 0;
    while (!feof(fp)) {
        ch = getc(fp);//获取当前字符
        if (ch == ' ' || ch == 10)
        {//ASCLL码中10为换行符，此条件为遇到空格或火车则跳过
            continue;
        }
        if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))              //发现一个单词
        {
            while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch == '\''))
            {
                if (ch >= 'A'&&ch <= 'Z')
                    ch += 32;//转换成小写
                ch = getc(fp);
            }
            //一个单词结束
        ++count;
        }
    }
//    cout << "words:" << count << endl;
    return count;
}

int Wordcounter::countlines(const char* str){
    char path[500];
    strcpy(path,get_current_dir_name());
    strcat(path,"/");
    strcat(path,str);

    FILE *fp;
    fp = fopen(path,"r");
    cout << path << endl;
    if(fp == NULL){
        cout << "open file error!" << endl;
        return -1;
    }
    char ch;
    int count = 0;
    while (!feof(fp)) {
        ch = getc(fp);//获取当前字符
        if (ch == '\n')
        {
            ++count;
        }
    }
//    cout << "lines:" << count << endl;
    return count;
}

int* Wordcounter::counta(const char* str){
    int space = 0,note = 0,code = 0;

    char path[500];
    strcpy(path,get_current_dir_name());
    strcat(path,"/");
    strcat(path,str);

    FILE *fp;
    fp = fopen(path,"r");
    if(fp == NULL){
        cout << "open file error!" << endl;
        return nullptr;
    }
    char line[500];
    int len = 0;
    while (fgets(line,500,fp) != nullptr) {
        len = strlen(line);
        if(len == 0){
            ++space;
        }else if(len == 1){
            if(line[0] == '{' || line[0] == '}')
                ++space;
            else
                ++code;
        }else{
            if(strstr(line,"//") || strstr(line,"}//") || strstr(line,"{//"))
                ++note;
            else
                ++code;
        }
    }
    cout << "space:" << space << endl;
    cout << "note:" << note << endl;
    cout << "code:" << code << endl;
    int *result = new int[3];
    result[0] = space;
    result[1] = note;
    result[2] = code;
    return result;
}

vector<int> Wordcounter::counts(const char* str){
    if(strstr(str,"*") || strstr(str,"?")){
        //recursive fuction
        vector<int> res;

        DIR *dir;
        struct dirent *entry;
        int ret;

        dir = opendir(get_current_dir_name());	//打开指定路径

        //路径存在
        if(dir != NULL)
        {
            //逐个获取文件夹中文件
            while( (entry = readdir(dir)) != NULL)
            {
              ret = fnmatch(str, entry->d_name, FNM_PATHNAME|FNM_PERIOD);
              if(ret == 0){
                cout << entry->d_name << endl;
                int *result = counta(entry->d_name);
                for(int i=0;i<3;++i){
                    res.push_back(result[i]);
                }
              }else if(ret == FNM_NOMATCH){
                continue ;
              }else{
                printf("error file=%s\n", entry->d_name);
              }
           }
           closedir(dir);
        }
        return res;
    }else{
        //non-recursive function
        int *result;
        vector<int> res;
        result = counta(str);
        for(int i=0;i<3;++i){
            res.push_back(result[i]);
        }
        return res;
    }
}

int Wordcounter::countx(int argc,char** argv){
    QApplication app(argc,argv);
    Dialog dialog;
    dialog.show();
    return app.exec();
}
