#ifndef CLASSSTREAMER_H
#define CLASSSTREAMER_H

#include <QObject>
#include <QFile>
#include <QByteArray>
#include <QIODevice>
#include "httpserver/httplistener.h"
#include "myrequesthandler.h"
#include <QTimer>
#include <QPixmap>
#include <QImage>
#include <QGuiApplication>
#include <QScreen>
#include <QWidget>
#include <QPushButton>
#include "httpserver/httprequesthandler.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QBuffer>
#include <QEventLoop>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QGridLayout;
class QGroupBox;
class QHBoxLayout;
class QLabel;
class QPushButton;
class QSpinBox;
class QVBoxLayout;


using namespace stefanfrings;
class MyRequestHandler : public HttpRequestHandler
{
public:
    MyRequestHandler(QObject * 	parent = NULL	);
    void service(HttpRequest &request, HttpResponse &response);
    //bool check = false;


};
class ClassStreamer : public QObject
{
    Q_OBJECT
public:
    explicit ClassStreamer(QObject *parent = nullptr);
    //~ClassStreamer();
    void run();
private:

    QFile base; // файл для открытия шаблона клиентской веб страницы
    QByteArray baseData; // буфер для хранения шаблона клиентской веб страницы
    //MyRequestHandler* handler;
    QNetworkAccessManager *networkManager;
    QSettings* settings;
    QPixmap originalPixmap;
    QTimer *timer;

    void deletethis();
private slots:
    // рандом бои старты и стопы
    void setfinish(QNetworkReply*);
};



class Screenshot : public QWidget
{
    Q_OBJECT

public:
    Screenshot();


protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void shootScreen();
    void updateCheckBox();
    void stopScreen();
    void startScreen();

private:
    void updateScreenshotLabel();
    QPixmap originalPixmap;
    QTimer *timer;
    QLabel *screenshotLabel;
    QSpinBox *delaySpinBox;
    QCheckBox *hideThisWindowCheckBox;
    QPushButton *newScreenshotButton;
};




#endif // CLASSSTREAMER_H
