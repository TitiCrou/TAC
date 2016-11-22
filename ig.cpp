#include "ig.h"
#include "ui_ig.h"

IG::IG(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IG)
{
    ui->setupUi(this);
}

IG::~IG()
{
    delete ui;
}
