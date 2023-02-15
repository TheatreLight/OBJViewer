#include "mainwindow.h"

#include "ui_mainwindow.h"



MainWindow::MainWindow(Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller),
      view_settings_(&Settings::GetInstance()) {
  ui->setupUi(this);
  view_settings_->ReadViewSettings();
  this->ui->thinline->setValue(view_settings_->get_line_width());
  this->ui->thinvertex->setValue(view_settings_->get_vertex_size());
  this->ui->linesoliddotted->setCurrentIndex(view_settings_->get_line_type());
  this->ui->vertexnonecircle->setCurrentIndex(
      view_settings_->get_vertex_type());
  this->ui->projectiontype->setCurrentIndex(
      view_settings_->get_projection_type());
}

MainWindow::~MainWindow() {
  controller_ = nullptr;
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  QString path = file_dialog_.getOpenFileName(this, tr("Open a file"), "",
                                              tr("Obj(*.obj)"));
  controller_->ReadFile(path);
  ui->openGLWidget->set_default();
  on_savedefault_clicked();
  ui->openGLWidget->set_pointer(controller_->get_pointer());
  ui->openGLWidget->set_count(controller_->get_faces_number());
  std::string name_of_file = path.toLocal8Bit().constData();
  size_t p = name_of_file.find_last_of('/');
  name_of_file = name_of_file.substr(p + 1, name_of_file.size() - p - 5);
  filename = QString::fromStdString(name_of_file);
  ui->filename_label->setText(filename);
  ui->polygons_label->setText(QString::number(controller_->get_faces_number()));
  ui->vertex_label->setText(
      QString::number(controller_->get_vertices_number()));
  ui->openGLWidget->update();
}

void MainWindow::on_zoom_slider_sliderMoved(int position) {
  float scale = (float)position / 500;
  ui->openGLWidget->set_scale(scale);
  ui->openGLWidget->update();
}

void MainWindow::on_translate_x_slider_sliderMoved(int position) {
  float trans = (float)position / 10;
  ui->openGLWidget->set_trans_x(trans);
  ui->openGLWidget->update();
}

void MainWindow::on_translate_y_slider_sliderMoved(int position) {
  float trans = (float)position / 10;
  ui->openGLWidget->set_trans_y(trans);
  ui->openGLWidget->update();
}

void MainWindow::on_translate_z_slider_sliderMoved(int position) {
  float trans = (float)position;
  ui->openGLWidget->set_trans_z(trans);
  ui->openGLWidget->update();
}

void MainWindow::on_rotate_x_slider_sliderMoved(int position) {
  float rotation = (float)position;
  ui->openGLWidget->set_rot_x(rotation);
  ui->openGLWidget->update();
}

void MainWindow::on_rotate_y_slider_sliderMoved(int position) {
  float rotation = (float)position;
  ui->openGLWidget->set_rot_y(rotation);
  ui->openGLWidget->update();
}

void MainWindow::on_rotate_z_slider_sliderMoved(int position) {
  float rotation = (float)position;
  ui->openGLWidget->set_rot_z(rotation);
  ui->openGLWidget->update();
}

void MainWindow::on_verticalSlider_sliderMoved(int position) {
  ui->openGLWidget->set_angle((float)position);
  ui->openGLWidget->update();
}

void MainWindow::on_savedefault_clicked() {
  ui->zoom_slider->setSliderPosition(500);
  ui->translate_x_slider->setSliderPosition(0);
  ui->translate_y_slider->setSliderPosition(0);
  ui->translate_z_slider->setSliderPosition(0);
  ui->rotate_z_slider->setSliderPosition(0);
  ui->rotate_x_slider->setSliderPosition(0);
  ui->rotate_y_slider->setSliderPosition(0);
  ui->thinline->setSliderPosition(0);
  ui->thinvertex->setSliderPosition(0);
  ui->verticalSlider->setSliderPosition(0);
  ui->vertexnonecircle->setCurrentText("none");
  ui->linesoliddotted->setCurrentText("solid");
  ui->projectiontype->setCurrentText("Central");
  view_settings_->set_color_line(QColor(255, 255, 255));
  view_settings_->set_color_back(QColor(0, 0, 0));
  view_settings_->set_color_vertex(QColor(255, 255, 255));
  view_settings_->set_vertex_size(1);
  view_settings_->set_line_width(1);
}

// type of projection
void MainWindow::on_projectiontype_currentIndexChanged(int index) {
  view_settings_->set_projection_type(index);
}

// vertex settings
void MainWindow::on_vertexnonecircle_currentIndexChanged(int index) {
  view_settings_->set_vertex_type(index);
}

// vertex thickness
void MainWindow::on_thinvertex_sliderMoved(int position) {
  view_settings_->set_vertex_size(position / 10.);
}

// colors
// background color
void MainWindow::on_backcolor_clicked() {
  QColor color_back = QColorDialog::getColor(Qt::white, this, "Choose a color");
  if (color_back.isValid())
    view_settings_->set_color_back(color_back);
}

// line color
void MainWindow::on_linecolor_clicked() {
  QColor color_line = QColorDialog::getColor(Qt::white, this, "Choose a color");
  if (color_line.isValid())
    view_settings_->set_color_line(color_line);
}

// line width
void MainWindow::on_thinline_sliderMoved(int position) {
  view_settings_->set_line_width(position / 10.);
}

// line type
void MainWindow::on_linesoliddotted_currentIndexChanged(int index) {
  view_settings_->set_line_type(index);
}

// vertex color
void MainWindow::on_vertexcolor_clicked() {
  QColor color_vertex =
      QColorDialog::getColor(Qt::white, this, "Choose a color");
  if (color_vertex.isValid())
    view_settings_->set_color_vertex(color_vertex);
}

void MainWindow::on_savejpeg_clicked() {
  QString image_path = QFileDialog::getExistingDirectory();
  QString name = filename;
  ui->openGLWidget->grabFramebuffer().save(image_path + "/" + name + ".jpeg",
                                           NULL, 100);
}

