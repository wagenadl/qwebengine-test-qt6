// Widget.cpp

#include "Widget.h"

Widget::Widget() {
  view = new QWebEngineView(this);
  connect(view->page(), &QWebEnginePage::loadFinished,
	  this, &Widget::ploaded);
  connect(view->page(), &QWebEnginePage::contentsSizeChanged,
	  this, &Widget::presized);
  view->load(QUrl("http://www.startpage.net"));
}

Widget::~Widget() {
}

void Widget::presized(QSizeF const &s) {
  qDebug() << "preszied" << s;
}

void Widget::ploaded(bool ok) {
  qDebug() << "ploaded" << ok;
}
