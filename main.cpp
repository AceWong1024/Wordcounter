#include <iostream>
#include <string.h>
#include <wordcounter.h>
#include <dialog.h>
using namespace std;
int main(int argc,char** argv){
    Wordcounter wc;
    if(argc < 2){
        cout << "Parameter error!" << endl;
    }else{
        if(argc == 2){
            if(!strcmp(argv[1],"-x")){
                wc.countx(argc,argv);
            }else{
                cout << "Parameter error!" << endl;
            }
        }else if(argc == 3){
            switch (wc.isValid(argv[1])) {
            case 1:wc.countchars(argv[2]);break;
            case 2:wc.countwords(argv[2]);break;
            case 3:wc.countlines(argv[2]);break;
            case 4:wc.counts(argv[2]);break;
            case 5:wc.counta(argv[2]);break;
            default:cout << "Unvalid Parameter!" << endl;break;
            }
        }else {
            cout << "Parameter error!" << endl;
        }
    }
//    return app.exec();
}
