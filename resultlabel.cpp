#include "resultlabel.h"

#include <QFont>

ResultLabel::ResultLabel(QString text, QWidget* parent) : QLabel(text, parent) {
    this->defaultText = text;

    QFont font = this->font();
    font.setPixelSize(12);

    this->setFont(font);
    this->setAlignment(Qt::AlignCenter);
}

void ResultLabel::setCriteriaInfo(bool isMeetingCriteria) {
    if (isMeetingCriteria) {
        this->setText(this->defaultText + "\nСоответствует.");
        this->setCorrect();
        return;
    }

    this->setText(this->defaultText + "\nНе соответствует.");
    this->setWrong();
}

void ResultLabel::setDefault() {
    this->setText(this->defaultText);
    this->setStyleSheet("QLabel { background-color: none; }");
}
