#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    char result[500];
    if(!ui->comboBox->currentText().compare("-c")){
        cout << ui->comboBox->currentText().toStdString() << endl;
        sprintf(result,"chars:%d",Wordcounter::countchars(ui->lineEdit->text().toStdString().data()));
        cout << result << endl;
        ui->textBrowser->append(result);
    }else if(!ui->comboBox->currentText().compare("-w")){
        sprintf(result,"words:%d",Wordcounter::countwords(ui->lineEdit->text().toStdString().data()));
        ui->textBrowser->append(result);
    }else if(!ui->comboBox->currentText().compare("-l")){
        sprintf(result,"lines:%d",Wordcounter::countlines(ui->lineEdit->text().toStdString().data()));
        ui->textBrowser->append(result);
    }else if(!ui->comboBox->currentText().compare("-s")){
        //output
        vector<int> res = Wordcounter::counts(ui->lineEdit->text().toStdString().data());
        for(int i=0;3*i < res.size();++i){
            sprintf(result,"space:%d  note:%d  code:%d",res[i],res[i+1],res[i+2]);
            ui->textBrowser->append(result);
        }
    }else if(!ui->comboBox->currentText().compare("-a")){
        int *ptr = Wordcounter::counta(ui->lineEdit->text().toStdString().data());
        sprintf(result,"space:%d  note:%d  code:%d",*ptr,*(ptr+1),*(ptr+2));
        ui->textBrowser->append(result);
    }else{
        cout << "error!" << endl;
    }
}
