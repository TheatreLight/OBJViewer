#include <QApplication>
#include <locale>

#include "controller/controller.h"
#include "model/facade.h"
#include "view/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  setlocale(LC_NUMERIC, "C");
  Facade model;
  Controller controller(&model);
  MainWindow w(&controller);
  w.show();
  return a.exec();
}
