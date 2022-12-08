#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets>
#include "sql/sql.h"

class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    void set();

private:
    void login();
    void savecfg();
    void _layout();
    void resizeEvent(QResizeEvent *);
    void keyPressEvent(QKeyEvent *event);
    void setBackgroundImage(QPixmap *pixmap);

signals:
    void loginSucceed();

public slots:

private:
    QPixmap* m_backPixmap;
    QLineEdit* m_idEdit;
    QLineEdit* m_passwdEdit;
    QPushButton* m_loginButton;
    QCheckBox* m_passwdCheckBox;
    QCheckBox* m_autoLoginCheckBox;

    //QSqlDatabase db;
    sql* s;

};

#endif // LOGIN_H
