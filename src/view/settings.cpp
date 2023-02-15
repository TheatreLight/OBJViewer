#include "settings.h"

void Settings::ReadViewSettings() {
  std::ifstream in("settings.txt");
  std::string line;
  if (in.is_open()) {
    while (in) {
      getline(in, line);
      if (line.find("line_type_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        line_type_ = std::stoi(substring);
      } else if (line.find("vertex_type_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        vertex_type_ = std::stoi(substring);
      } else if (line.find("projection_type_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        projection_type_ = std::stoi(substring);
      } else if (line.find("line_width_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        line_width_ = std::stof(substring);
      } else if (line.find("vertex_size_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        vertex_size_ = std::stof(substring);
      } else if (line.find("back_red_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        color_back_.setRedF(std::stof(substring));
      } else if (line.find("back_green_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        color_back_.setGreenF(std::stof(substring));
      } else if (line.find("back_blue_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        color_back_.setBlueF(std::stof(substring));
      } else if (line.find("line_red_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        color_line_.setRedF(std::stof(substring));
      } else if (line.find("line_green_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        color_line_.setGreenF(std::stof(substring));
      } else if (line.find("line_blue_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        color_line_.setBlueF(std::stof(substring));
      } else if (line.find("vertex_red_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        color_vertex_.setRedF(std::stof(substring));
      } else if (line.find("vertex_green_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        color_vertex_.setGreenF(std::stof(substring));
      } else if (line.find("vertex_blue_") != std::string::npos) {
        std::string substring = line.substr(line.find("=") + 1);
        color_vertex_.setBlueF(std::stof(substring));
      }
    }
  }
  in.close();
}

void Settings::SaveViewSettings() {
  std::ofstream out;
  out.open("settings.txt");
  if (out.is_open()) {
    out << "line_type_=" << line_type_ << std::endl;
    out << "vertex_type_=" << vertex_type_ << std::endl;
    out << "projection_type_=" << projection_type_ << std::endl;
    out << "line_width_=" << line_width_ << std::endl;
    out << "vertex_size_=" << vertex_size_ << std::endl;
    out << "back_red_=" << color_back_.redF() << std::endl;
    out << "back_green_=" << color_back_.greenF() << std::endl;
    out << "back_blue_=" << color_back_.blueF() << std::endl;
    out << "line_red_=" << color_line_.redF() << std::endl;
    out << "line_green_=" << color_line_.greenF() << std::endl;
    out << "line_blue_=" << color_line_.blueF() << std::endl;
    out << "vertex_red_=" << color_vertex_.redF() << std::endl;
    out << "vertex_green_=" << color_vertex_.greenF() << std::endl;
    out << "vertex_blue_=" << color_vertex_.blueF() << std::endl;
  }
}
