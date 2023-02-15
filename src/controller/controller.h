#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/facade.h"

namespace s21 {

class Controller {
public:
  explicit Controller(Facade *model);
  void ReadFile(QString path);
  float *get_pointer();
  int get_faces_number();
  int get_vertices_number();

private:
  Facade *model_;
};

} // namespace s21
#endif // CONTROLLER_H
