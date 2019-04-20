#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->rBtnBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->rBtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_chkBoxUnder_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setUnderline(checked);
    ui->textEdit->setFont(font);
}


void Dialog::on_chkBoxItalic_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setItalic(checked);
    ui->textEdit->setFont(font);
}

void Dialog::on_chkBoxBold_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setBold(checked);
    ui->textEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
    QPalette plet = ui->textEdit->palette();
    if(ui->rBtnRed->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    else if(ui->rBtnBlue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    else if(ui->rBtnBlack->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    else
        plet.setColor(QPalette::Text,Qt::black);
    ui->textEdit->setPalette(plet);
}

