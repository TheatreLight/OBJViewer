#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QtWidgets/QWidget>

#include "QtGifImage/include/QtGifImage/qgifimage.h"
#include "controller/controller.h"
#include "glview.h"
#include "model/filereader.h"
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(Controller *controller, QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_pushButton_clicked();
  void on_zoom_slider_sliderMoved(int position);
  void on_translate_x_slider_sliderMoved(int position);
  void on_translate_y_slider_sliderMoved(int position);
  void on_translate_z_slider_sliderMoved(int position);
  void on_rotate_x_slider_sliderMoved(int position);
  void on_rotate_y_slider_sliderMoved(int position);
  void on_rotate_z_slider_sliderMoved(int position);
  void on_verticalSlider_sliderMoved(int position);
  void on_savedefault_clicked();
  void on_backcolor_clicked();
  void on_linecolor_clicked();
  void on_linesoliddotted_currentIndexChanged(int index);
  void on_thinline_sliderMoved(int position);
  void on_vertexcolor_clicked();
  void on_vertexnonecircle_currentIndexChanged(int index);
  void on_thinvertex_sliderMoved(int position);
  void on_projectiontype_currentIndexChanged(int index);
  void on_savejpeg_clicked();

private:
  Ui::MainWindow *ui;
  QFileDialog file_dialog_;
  Controller *controller_;
  Settings *view_settings_;
  Settings *settings_;
  QTimer *timer_;
  QString filename;
  QGifImage *gif_;
  QImage *photo_;
  int time_{};
  //  QString qfile_name_;
};
} // namespace s21
#endif // MAINWINDOW_H
