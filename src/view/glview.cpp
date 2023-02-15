#include "glview.h"

GLView::GLView(QWidget *parent)
    : QOpenGLWidget(parent), settings_(&Settings::GetInstance()) {
}

void GLView::initializeGL() {
  glClearDepth(1.0);
  glEnable(GL_CULL_FACE);
  glEnable(GL_DEPTH_TEST);
}

void GLView::paintGL() {
  glClearDepth(1.0);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClearColor(settings_->get_color_back().redF(),
               settings_->get_color_back().greenF(),
               settings_->get_color_back().blueF(), 1);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glScalef(scale_, scale_, scale_);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (settings_->get_projection_type() == 0)
    glOrtho(-20, 20, -12, 16, -20, 180);
  // glFrustum(-1.5, 1.5, -0.8, 0.8, 5, 100);
  else
    // gluPerspective(100, 1.2, 0.1, 1000.0);
    glFrustum(-1.5, 1.5, -0.8, 0.8, 5, 100);
  glTranslatef(trans_x, trans_y, trans_z);
  glRotatef(angle_, rot_x, rot_y, rot_z);
  glEnableClientState(GL_VERTEX_ARRAY);

  glVertexPointer(3, GL_FLOAT, 0, pointer_);

  glColor3f(settings_->get_color_line().redF(),
            settings_->get_color_line().greenF(),
            settings_->get_color_line().blueF());

  if (settings_->get_line_type() == 0) {
    glDisable(GL_LINE_STIPPLE);
    glDrawArrays(GL_LINES, 0, count_);
    glDrawArrays(GL_LINES_ADJACENCY, 0, count_);
  } else {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(4, 0x00FF);
    glDrawArrays(GL_LINES, 0, count_);
    glDrawArrays(GL_LINES_ADJACENCY, 0, count_);
  }

  if (settings_->get_vertex_type() == 1) {
    glDisable(GL_POINT_SMOOTH);
    glPointSize(settings_->get_vertex_size());
    glColor3f(settings_->get_color_vertex().redF(),
              settings_->get_color_vertex().greenF(),
              settings_->get_color_vertex().blueF());
    glPointSize(settings_->get_vertex_size());
    glDrawArrays(GL_POINTS, 0, count_);
  }

  if (settings_->get_vertex_type() == 2) {
    glEnable(GL_POINT_SMOOTH);
    glPointSize(settings_->get_vertex_size());
    glColor3f(settings_->get_color_vertex().redF(),
              settings_->get_color_vertex().greenF(),
              settings_->get_color_vertex().blueF());

    glPointSize(settings_->get_vertex_size());

    glDrawArrays(GL_POINTS, 0, count_);
  }
  glDrawArrays(GL_LINES, 0, count_);
  glDisableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glLineWidth(settings_->get_line_width());
}
