#include <QApplication>
#include <QWebEngineView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QSizePolicy>
#include <QPlainTextEdit>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window(nullptr);
    window.setGeometry(100,100,480,640);
    auto *webView = new QWebEngineView(&window);
    auto *HBox = new QHBoxLayout(&window);
    auto *textPlain = new QPlainTextEdit(&window);
    textPlain->setGeometry(0,0,(window.width()/2)-4,window.height());
    textPlain->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    webView->setGeometry(textPlain->x()+textPlain->width()+4,textPlain->y(),(window.width()/2)-4,window.height());
    webView->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    HBox->addWidget(textPlain,0);
    HBox->addWidget(webView,1);
    HBox->setSpacing(8);
    HBox->setAlignment(&window, Qt::AlignCenter );
    HBox->setStretch(0,1);
    HBox->setStretch(1,1);
    QObject::connect(textPlain, &QPlainTextEdit::textChanged, [&textPlain, &webView](){
         webView->setHtml(textPlain->toPlainText() );
    } );

    window.show();
    return a.exec();
}
