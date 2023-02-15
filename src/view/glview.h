#ifndef GLVIEW_H
#define GLVIEW_H

#include "settings.h"

#include <QColorDialog>
#include <QOpenGLWidget>

class GLView : public QOpenGLWidget {
  Q_OBJECT

public:
  explicit GLView(QWidget *parent = nullptr);
  void initializeGL() override;
  void paintGL() override;

  void set_pointer(float *pointer) { pointer_ = pointer; }
  void set_count(int count) { count_ = count; }

  void set_default() {
    scale_ = 1;
    trans_x = 0;
    trans_y = 0;
    trans_z = -6;
    rot_x = 0;
    rot_y = 0;
    rot_z = 0;
    angle_ = 0;
  }

  void set_scale(float scale) { scale_ = scale; }
  void set_trans_x(float x) { trans_x = x; }
  void set_trans_y(float y) { trans_y = y; }
  void set_trans_z(float z) { trans_z = z; }
  void set_rot_x(float x) { rot_x = x; }
  void set_rot_y(float y) { rot_y = y; }
  void set_rot_z(float z) { rot_z = z; }
  void set_angle(float angle) { angle_ = angle; }

private:
  float *pointer_ = nullptr;
  int count_ = 0;
  float scale_ = 1;
  float trans_x = 0;
  float trans_y = 0;
  float trans_z = -6;
  float rot_x = 0;
  float rot_y = 0;
  float rot_z = 0;
  float angle_ = 0;

  Settings *settings_;
};

#endif // GLVIEW_H
