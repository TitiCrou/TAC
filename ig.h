#ifndef IG_H
#define IG_H

#include <QMainWindow>

namespace Ui {
class IG;
}

class IG : public QMainWindow
{
    Q_OBJECT

public:
    explicit IG(QWidget *parent = 0);
    ~IG();

private:
    Ui::IG *ui;
};

#endif // IG_H
