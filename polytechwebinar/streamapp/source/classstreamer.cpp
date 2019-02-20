#include "classstreamer.h"
#include "myrequesthandler.h"
#include <QPixmap>
#include <QImage>
#include <QGuiApplication>
#include <QScreen>
#include <QString>
#include <QDebug>
#include <QApplication>
#include <QBuffer>
#include <QtWidgets>






ClassStreamer::ClassStreamer(QObject *parent) : QObject(parent)
{
    settings=new QSettings("configfile.ini",QSettings::IniFormat);
    qDebug() << "*** " << settings->allKeys();
    //qDebug() << "*** " << settings->value("listener/port").toString();
    //qDebug() << "*** " << settings->value("listener/port").toInt();
    //handler=new MyRequestHandler(qApp);
    //listener=new HttpListener(settings,handler,qApp );


    networkManager = new QNetworkAccessManager(this);
        connect(networkManager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(setfinish(QNetworkReply*)));
    run();

};

void ClassStreamer::deletethis()
{
    delete this;
};

void ClassStreamer::run()
{
    QUrl serviceUrl=QUrl("http://stream.std-573.ist.mospolytech.ru/setframe");
    QByteArray byteArray;
    //while(true) {

        QEventLoop loop;
        connect(networkManager,SIGNAL(finished(QNetworkReply*)),
                &loop,SLOT(quit()));


        QScreen *screen = QGuiApplication::primaryScreen();
        while(true)
        {
            QPixmap originalPixmap = screen->grabWindow(0);
            QImage image = originalPixmap.toImage(); //

            QBuffer buffer(&byteArray);
            image.save(&buffer, "JPG"); // writes the image in PNG format inside the buffer

            QNetworkRequest request(serviceUrl);

            request.setHeader(QNetworkRequest::ContentTypeHeader, "text/html;");
            //request.setHeader(QNetworkRequest::Access-Control-Allow-Origin,"*");
            QNetworkReply *reply = networkManager->post(request, byteArray.toBase64());
            // включить EVENTLOOP
            qDebug() << "frame_sent__"<<reply;
            //qDebug() << reply;
            loop.exec();

        }
};

void ClassStreamer::setfinish(QNetworkReply *reply){
   /* if(reply->error()){
            // Сообщаем об этом и показываем информацию об ошибках
            qDebug() << "ERROR";
            qDebug() << reply->errorString();
        } else {
        if (global_check == 0){}else{
            //response.setHeader("Content-Type","text/html;");
            //response.setHeader("Access-Control-Allow-Origin","*");
            QScreen *screen = QGuiApplication::primaryScreen();
            QPixmap originalPixmap = screen->grabWindow(0);
            QImage image = originalPixmap.toImage(); //
            QByteArray byteArray;
            QBuffer buffer(&byteArray);
            image.save(&buffer, "PNG"); // writes the image in PNG format inside the buffer

            //response.write(byteArray.toBase64());
            //pathInfo = request.getPath();
            qDebug() << "frame_sent";

            }

             // Посылаем сигнал о завершении получения файла
            }


*/
};

MyRequestHandler::MyRequestHandler(QObject *parent)
    :HttpRequestHandler (parent)
{
//fghfghfghfghgfh
}

void MyRequestHandler::service(HttpRequest& request, HttpResponse& response)
{
    // Get a request parameters

  /*  QFile base("base.html"); // создаем объект класса QFile
            QByteArray baseData; // Создаем объект класса QByteArray, куда мы будем считывать данные
            if (!base.open(QIODevice::ReadOnly|QIODevice::Text)) // Проверяем, возможно ли открыть наш файл для чтения
                return; // если это сделать невозможно, то завершаем функцию
            baseData = base.readAll(); //считываем все данные с файла в объект data
    qDebug() << "base: " << baseData;

    QFile stream("getFrame.html"); // создаем объект класса QFile
            QByteArray getFrame; // Создаем объект класса QByteArray, куда мы будем считывать данные
            if (!stream.open(QIODevice::ReadOnly|QIODevice::Text)) // Проверяем, возможно ли открыть наш файл для чтения
                 return; // если это сделать невозможно, то завершаем функцию
            getFrame = stream.readAll(); //считываем все данные с файла в объект data

    QByteArray username=request.getParameter("username");


*/


/*  разкоммитить если всё плохо от сих...
    qDebug() << "Path = " <<
               request.getPath();
          qDebug() << "Method = " << request.getMethod();
           qDebug() << "Parameters = " <<  request.getParameterMap();
    // Set a response header

    // Generate the HTML document
    //check = false;
    QString pathInfo = request.getPath();
    if (global_check == 0){}else{
        response.setHeader("Content-Type","text/html;");
        response.setHeader("Access-Control-Allow-Origin","*");
        QScreen *screen = QGuiApplication::primaryScreen();
        QPixmap originalPixmap = screen->grabWindow(0);
        QImage image = originalPixmap.toImage(); //
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        image.save(&buffer, "PNG"); // writes the image in PNG format inside the buffer
        response.write(byteArray.toBase64());
        pathInfo = request.getPath();
        qDebug() << "frame_sent";
        }
...и до сих */
}

Screenshot::Screenshot()
    :  screenshotLabel(new QLabel(this))
{
    screenshotLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    screenshotLabel->setAlignment(Qt::AlignCenter);

    const QRect screenGeometry = QApplication::desktop()->screenGeometry(this);
    screenshotLabel->setMinimumSize(screenGeometry.width() / 8, screenGeometry.height() / 8);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(screenshotLabel);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(shootScreen()));

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    newScreenshotButton = new QPushButton(tr("Start Screenshot"), this);
    connect(newScreenshotButton, &QPushButton::clicked, this, &Screenshot::startScreen);
    buttonsLayout->addWidget(newScreenshotButton);
    QPushButton *saveScreenshotButton = new QPushButton(tr("Stop Screenshot"), this);
    connect(saveScreenshotButton, &QPushButton::clicked, this, &Screenshot::stopScreen);
    buttonsLayout->addWidget(saveScreenshotButton);
    QPushButton *quitScreenshotButton = new QPushButton(tr("Quit"), this);
    quitScreenshotButton->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(quitScreenshotButton, &QPushButton::clicked, this, &QWidget::close);
    buttonsLayout->addWidget(quitScreenshotButton);
    buttonsLayout->addStretch();
    mainLayout->addLayout(buttonsLayout);

    setWindowTitle(tr("Screenshot"));
    resize(300, 200);

}
//! [0]

//! [1]
void Screenshot::resizeEvent(QResizeEvent * /* event */)
{
    QSize scaledSize = originalPixmap.size();
    scaledSize.scale(screenshotLabel->size(), Qt::KeepAspectRatio);
    if (!screenshotLabel->pixmap() || scaledSize != screenshotLabel->pixmap()->size())

//! [1]
    updateScreenshotLabel();
}
//! [2]

//! [3]

//! [4]
void Screenshot::shootScreen()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
        screen = window->screen();
    if (!screen)
        return;

    if (delaySpinBox->value() != 0)
        QApplication::beep();

    originalPixmap = screen->grabWindow(0);
    updateScreenshotLabel();

    newScreenshotButton->setDisabled(false);
    if (hideThisWindowCheckBox->isChecked())
        show();
}
//! [4]

void Screenshot::startScreen()
{
//global_check = 1;
//timer->start(500);
   qDebug()<<"Start_butt_pressed";

}

void Screenshot::stopScreen()
{
//global_check = 0;
//timer->stop();
    qDebug()<<"stop_butt_pressed";
}



//! [6]
void Screenshot::updateCheckBox()
{
    if (delaySpinBox->value() == 0) {
        hideThisWindowCheckBox->setDisabled(true);
        hideThisWindowCheckBox->setChecked(false);
    } else {
        hideThisWindowCheckBox->setDisabled(false);
    }
}
//! [6]


//! [10]
void Screenshot::updateScreenshotLabel()
{
    screenshotLabel->setPixmap(originalPixmap.scaled(screenshotLabel->size(),
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation));

}
