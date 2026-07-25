#ifndef ADDVIDEOPAGE_H
#define ADDVIDEOPAGE_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QSpinBox;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;

class AddVideoPage : public QDialog
{
    Q_OBJECT

public:
    explicit AddVideoPage(QWidget* parent = nullptr);

private slots:
    void saveVideo();

private:
    // Labels
    QLabel* titleLabel;
    QLabel* videoTitleLabel;
    QLabel* genreLabel;
    QLabel* yearLabel;
    QLabel* copiesLabel;

    // Input fields
    QLineEdit* titleEdit;
    QLineEdit* genreEdit;
    QSpinBox* yearBox;
    QSpinBox* copiesBox;

    // Buttons
    QPushButton* saveButton;
    QPushButton* cancelButton;
};

#endif