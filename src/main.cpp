#include <QApplication>
#include <locale>

#include "controller/controller.h"
#include "model/facade.h"
#include "view/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  setlocale(LC_NUMERIC, "C");
  s21::Facade model;
  s21::Controller controller(&model);
  s21::MainWindow w(&controller);
  w.show();
  return a.exec();
}
