// Widget.h

#ifndef WIDGET_H

#define WIDGET_H

#include <QWebEngineView>
#include <QWebEnginePage>

class Widget: public QWidget {
  Q_OBJECT;
public:
  Widget();
  virtual ~Widget();
private slots:
  void presized(QSizeF const &);
  void ploaded(bool);
private:
  QWebEngineView *view;

};

#endif
