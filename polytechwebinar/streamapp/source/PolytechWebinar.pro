QT += widgets network
requires(qtConfig(filedialog))

HEADERS             = screenshot.h \
    httpserver/httpconnectionhandler.h \
    httpserver/httpconnectionhandlerpool.h \
    httpserver/httpcookie.h \
    httpserver/httpglobal.h \
    httpserver/httplistener.h \
    httpserver/httprequest.h \
    httpserver/httprequesthandler.h \
    httpserver/httpresponse.h \
    httpserver/httpsession.h \
    httpserver/httpsessionstore.h \
    httpserver/staticfilecontroller.h \
    classstreamer.h \
    sockettest.h

    myrequesthandler.h
SOURCES             = main.cpp \
                      screenshot.cpp \
    httpserver/httpconnectionhandler.cpp \
    httpserver/httpconnectionhandlerpool.cpp \
    httpserver/httpcookie.cpp \
    httpserver/httpglobal.cpp \
    httpserver/httplistener.cpp \
    httpserver/httprequest.cpp \
    httpserver/httprequesthandler.cpp \
    httpserver/httpresponse.cpp \
    httpserver/httpsession.cpp \
    httpserver/httpsessionstore.cpp \
    httpserver/staticfilecontroller.cpp \
    classstreamer.cpp \
    sockettest.cpp
#INCLUDEPATH += F:/yudemin00/_QT/screenshot\QtWebApp\QtWebApp\httpserver
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/desktop/screenshot
INSTALLS += target

FORMS +=

DISTFILES += \
    httpserver/httpserver.pri
