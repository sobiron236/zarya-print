#include <QtSingleApplication>
#include <QtGui/QMessageBox>
#include <QtCore/QTextCodec>
#include <QtCore/QStringList>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "mainwindow.h"

#include "config.h"


int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(images);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QtSingleApplication app(argc, argv, true);



    installLog("Client prn",QObject::trUtf8("Заря"));

    QStringList aList=app.arguments();
    if (aList.size()< 2){
        QMessageBox::critical(0,QObject::trUtf8("Обратитесь к системному администратору"),
                              QObject::trUtf8("Ошибка запуска приложения, не задан файл для печати"));
        return 1;
    }

    QString in_file=aList.at(1);

    if (app.sendMessage(QObject::trUtf8("Потребован повторный запуск приложения!"))
        || app.isRunning())
        return 0;

    QApplication::setQuitOnLastWindowClosed(true);

    qApp->setStyleSheet(" QPushButton:hover {background-color: black;} "
                        " QPushButton:hover {background-color: white;} "
                        " QPushButton { border-style: outset; border-width: 2px;"
                        "  border-radius: 10px; border-color: beige;"
                        "  font: bold 10px;  min-width: 10em; padding: 6px}"
                        );

    MainWindow client;   
    client.show();

    client.init ( qApp->applicationDirPath(),in_file );
    app.setActivationWindow(&client);

    QObject::connect(&app, SIGNAL(messageReceived(const QString&)),
                     &client, SLOT(appendStartMsg(const QString&)));

    return app.exec();
}
