#include "ig.h"
#include "ui_ig.h"

IG::IG(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IG)
{
    ui->setupUi(this);
    connect(ui->askLocation, SIGNAL(clicked()), this, SLOT(loc()));

}

IG::~IG()
{
    delete ui;
}
