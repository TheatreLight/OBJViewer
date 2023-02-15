#include "facade.h"

Facade::Facade() {}

void Facade::ReadFile(QString path) {
  FileReader reader(path);
  set_buffer(reader.get_sorted_vertices());
  set_faces_number(reader.get_faces_count());
  set_vertices_number(reader.get_vertices_count());
}
