#ifndef RESULTLABEL_H
#define RESULTLABEL_H

#include <QLabel>

#include <QString>

class ResultLabel : public QLabel
{
    Q_OBJECT

private:
    QString defaultText;

private:
    void setCorrect() { this->setStyleSheet("QLabel { background-color: green; }"); }
    void setWrong() { this->setStyleSheet("QLabel { background-color: red; }"); }

public:
    ResultLabel(QString text, QWidget* parent = nullptr);

public:
    void setCriteriaInfo(bool isMeetingCriteria);

public slots:
    void setDefault();

};

#endif // RESULTLABEL_H
