#include "login/login.h"
#include "sql/sql.h"

Login::Login(QWidget *parent) : QWidget(parent)
{
    _layout();
    m_backPixmap = new QPixmap(QStringLiteral("p.jpg"));     // 设置图片背景
    this->setBackgroundImage(m_backPixmap);

    QTimer* timer = new QTimer(this);
    timer->start(2000);
    connect(timer, &QTimer::timeout, [=](){set(); timer->stop();});

    s = new sql();
    s->createTab();   // 创建各表，创建之后可注释
}

Login::~Login()
{
    delete this;
}

void Login::login()
{

    bool tf = s->verificationLogin(m_idEdit->text(), m_passwdEdit->text());     // 与数据库内数据进行比对。
    // qDebug() << tf;
    // 登录成功显示主界面
    if (tf) {
        savecfg();  // 保存登录信息
        emit loginSucceed();    // 发送登录成功信号
        delete s;
        this->close();
    } else {
        QMessageBox::about(nullptr, "error", QStringLiteral("账号或密码错误。 "));
        m_passwdEdit->clear();
    }
}

// 如果上一次选择自动登录，打开软件会自动登录
void Login::set()
{
    QSettings cfg("user.ini",QSettings::IniFormat);
    if(cfg.value("remeberPasswd").toString() == "true") {
        if (cfg.value("autoLogin").toBool()){
                m_loginButton->click();
        }
    }
}

// 保存账号、密码、保存密码检查框状态、自动登录检查框状态。
void Login::savecfg()
{
    QString passWd = m_passwdEdit->text();

    QSettings cfg("user.ini", QSettings::IniFormat);
    if (m_passwdCheckBox->isTristate() == true) {
        cfg.setValue("usersname", m_idEdit->text());
        cfg.setValue("passwd", passWd);
        cfg.setValue("remeberPasswd", m_passwdCheckBox->isTristate());
        cfg.setValue("autoLogin", m_autoLoginCheckBox->isTristate());
        cfg.sync();
    } else
        cfg.setValue("remeberPasswd", m_passwdCheckBox->isTristate());
}

void Login::_layout()
{
    QString editStyle("QLineEdit{background-color:rgba(0,0,0,40);border-style:outset;border-width:2px;border-radius:5px;border-color:rgba(255,255,255,30);font:bold 15px;color:rgba(0,0,0,200);padding:6px;color:#F8F8FF;}QLineEdit:hover{background-color:rgba(0,0,0,0);border-color:rgba(255,255,255,200);color:rgba(0,0,0,200);color:#F8F8FF;}");
    QString buttonSytle(
                //正常状态样式
                "QPushButton{"
                "background-color:rgba(0,220,255,100);"    //背景色（也可以设置图片）
                "border-style:outset;"                     //边框样式（inset/outset）
                "border-width:2px;"                        //边框宽度像素
                "border-radius:8px;"                       //边框圆角半径像素
                "border-color:rgba(255,255,255,30);"       //边框颜色
                "font:bold 12px;"                          //字体，字体大小
                // "color:rgba(0,0,0,200);"                   //字体颜色
                "color:#F8F8FF;"
                "padding:6px;"                             //填衬
                "}"
                //鼠标悬停样式
                "QPushButton:hover{"
                "background-color:rgba(0,230,255,50);"
                "border-color:rgba(255,255,255,200);"
                "color:rgba(0,0,0,200);"
                "}");

    setWindowFlags(Qt::FramelessWindowHint);        //无边框
    //setAttribute(Qt::WA_TranslucentBackground);     //背景透明
    resize(800, 600);

    // 设置窗口圆角
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),10,10);
    setMask(bmp);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QHBoxLayout* headlayout = new QHBoxLayout();
    QLabel* label = new QLabel(QStringLiteral("信息系统集成与构建"), this);
    QFont font;
    label->setFont(QFont("Timers", 20));
    label->setAlignment(Qt::AlignCenter);           // 位置在中间, QFont::Bold
    label->setStyleSheet("color:#F8F8FF;");
    headlayout->addWidget(label);

    QHBoxLayout* idLayout = new QHBoxLayout();
    QLabel* idLabel = new QLabel(QStringLiteral("账号"), this);
    idLabel->setFont(QFont("Timers", 12, QFont::Bold));
    idLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    idLabel->setStyleSheet("color:#F8F8FF;");
    m_idEdit = new QLineEdit(this);
    m_idEdit->setStyleSheet(editStyle);
    idLayout->addWidget(idLabel, 1);
    idLayout->addWidget(m_idEdit, 1);
    idLayout->addStretch(2);

    QHBoxLayout* passwdLayout = new QHBoxLayout();
    QLabel* passwdLabel = new QLabel(QStringLiteral("密码"), this);
    passwdLabel->setFont(QFont("Timers", 12, QFont::Bold));
    passwdLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    passwdLabel->setStyleSheet("color:#F8F8FF;");
    m_passwdEdit = new QLineEdit(this);
    m_passwdEdit->setEchoMode(QLineEdit::Password);
    m_passwdEdit->setStyleSheet(editStyle);
    passwdLayout->addWidget(passwdLabel, 1);
    passwdLayout->addWidget(m_passwdEdit, 1);
    passwdLayout->addStretch(2);

    QSettings cfg("user.ini",QSettings::IniFormat);
    QHBoxLayout* checkBoxLayout = new QHBoxLayout();
    m_passwdCheckBox = new QCheckBox(QStringLiteral("记住密码"),this);
    m_passwdCheckBox->setTristate(cfg.value("remeberPasswd").toBool());
    m_passwdCheckBox->setStyleSheet("color:#F8F8FF;");
    m_autoLoginCheckBox = new QCheckBox(QStringLiteral("自动登录"),this);
    m_autoLoginCheckBox->setTristate(cfg.value("autoLogin").toBool());
    m_autoLoginCheckBox->setStyleSheet("color:#F8F8FF;");
    checkBoxLayout->addStretch(2);
    checkBoxLayout->addWidget(m_passwdCheckBox,1);
    checkBoxLayout->addWidget(m_autoLoginCheckBox,1);
    checkBoxLayout->addStretch(4);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    m_loginButton = new QPushButton(QStringLiteral("登录"), this);
    m_loginButton->setStyleSheet(buttonSytle);
    QPushButton* registerButton = new QPushButton(QStringLiteral("注册"), this);
    registerButton->setStyleSheet(buttonSytle);
    buttonLayout->addStretch(2);
    buttonLayout->addWidget(m_loginButton, 1);
    buttonLayout->addWidget(registerButton, 1);
    buttonLayout->addStretch(4);

    mainLayout->addLayout(headlayout, 1);
    mainLayout->addLayout(idLayout, 1);
    mainLayout->addLayout(passwdLayout, 1);
    mainLayout->addLayout(checkBoxLayout, 1);
    mainLayout->addLayout(buttonLayout, 1);
    mainLayout->addStretch(1);

    if(cfg.value("remeberPasswd").toString() == "true") {
        m_idEdit->setText(cfg.value("usersname").toString());
        m_passwdEdit->setText(cfg.value("passwd").toString());
        m_passwdCheckBox->setCheckState(Qt::Checked);
        if (cfg.value("autoLogin").toBool()){
                m_autoLoginCheckBox->setCheckState(Qt::Checked);
        }
    } else
        m_idEdit->setText(cfg.value("usersname").toString());

    connect(m_passwdCheckBox, &QCheckBox::clicked, [=](){
        m_passwdCheckBox->setTristate(!m_passwdCheckBox->isTristate());
        if (m_autoLoginCheckBox->isTristate()) m_autoLoginCheckBox->setCheckState(Qt::Unchecked);
    });
    connect(m_autoLoginCheckBox, &QCheckBox::clicked, [=](){
        m_autoLoginCheckBox->setTristate(!m_autoLoginCheckBox->isTristate());
        if (!m_passwdCheckBox->isTristate())m_passwdCheckBox->setTristate(!m_passwdCheckBox->isTristate());
        m_passwdCheckBox->setCheckState(Qt::Checked);
    });
    //connect(m_passwdCheckBox, &QCheckBox::clicked, [=](){qDebug() << m_passwdCheckBox->isTristate();});
    connect(m_loginButton, &QPushButton::clicked, this, &Login::login);
    connect(registerButton, &QPushButton::clicked, [](){});

}

// 设置背景图片
void Login::setBackgroundImage(QPixmap* pixmap)
{
    if(pixmap->isNull()){
        QMessageBox::about(nullptr, "error", QStringLiteral("无法打开背景图片"));
        return;
    }
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    // 设置背景图片自动缩放充满全屏
    palette.setBrush(this->backgroundRole(),
                     QBrush(pixmap->scaled(this->size(),
                                           Qt::IgnoreAspectRatio,
                                           Qt::SmoothTransformation)));
    this->setPalette(palette);
}

// 重载resizeEvent
void Login::resizeEvent(QResizeEvent *)
{
    setBackgroundImage(m_backPixmap);
}

// 回车事件绑定到登录按钮
void Login::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
        m_loginButton->clicked(true);

}
