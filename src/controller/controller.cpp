#include "controller.h"

namespace s21 {
Controller::Controller(Facade *model) : model_(model) {}

void Controller::ReadFile(QString path) { model_->ReadFile(path); }

float *Controller::get_pointer() { return model_->get_sorted().data(); }

int Controller::get_faces_number() { return model_->get_faces_number(); }

int Controller::get_vertices_number() { return model_->get_vertices_number(); }

} // namespace s21
