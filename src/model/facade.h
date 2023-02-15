#ifndef FACADE_H
#define FACADE_H

#include "model/filereader.h"
#include "view/settings.h"

class Facade {
public:
  Facade();
  void ReadFile(QString path);
  void set_buffer(const std::vector<float> &input_buffer) {
    sorted_ = input_buffer;
  }
  void set_faces_number(const int number) { faces_number_ = number; }
  void set_vertices_number(const int vert_number) {
    vertices_number_ = vert_number;
  }
  std::vector<float> &get_sorted() { return sorted_; }
  int get_faces_number() { return faces_number_; }
  int get_vertices_number() { return vertices_number_; }

private:
  std::vector<float> sorted_;
  int faces_number_ = 0;
  int vertices_number_ = 0;
};

#endif // FACADE_H
