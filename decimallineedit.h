#ifndef DECIMALLINEEDIT_H
#define DECIMALLINEEDIT_H

#include <QWidget>
#include <QLineEdit>

class DecimalLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    DecimalLineEdit(QWidget* parent = nullptr);

};

#endif // DECIMALLINEEDIT_H
