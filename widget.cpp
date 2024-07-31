#include "widget.h"
#include "./ui_widget.h"
// #include <QDebug>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , myui(new Ui::Widget)
{
    myui->setupUi(this);
    myui->label_image->clear();// 清空文字
}

Widget::~Widget()
{
    delete myui;
}

void Widget::on_btn_open_clicked(){
    // qDebug() << "被点击"<<Qt::endl;
    /**
     * [static] QString QFileDialog::getOpenFileName(
     *      QWidget *parent = nullptr, // 父指针
     *      const QString &caption = QString(), // 提示
     *      const QString &dir = QString(), // 文件路径
     *      const QString &filter = QString(),// 选择图片的提示词 和 过滤
     *      QString *selectedFilter = nullptr,
     *      QFileDialog::Options options = Options())
     */
    QString FileName =  QFileDialog::getOpenFileName(this, "选择图片", "C:/Users/tony/Pictures", "选择图片(*.png *.jpg)");

    if(FileName.isEmpty()){
        return;
    }
    myui->lineEdit_path->setText(FileName); // 在路径栏显示选择的图片路径
    myui->label_image->setPixmap(QPixmap(FileName));

}
