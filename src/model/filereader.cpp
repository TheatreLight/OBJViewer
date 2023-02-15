#include "filereader.h"

#include "qdebug.h"

namespace s21 {
FileReader::FileReader(QString path) { ReadFile(path); }

void FileReader::ReadFile(QString path) {
  QFile file(path);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Can't open the file";
    return;
  }
  while (!file.atEnd()) {
    QByteArray line = file.readLine();
    LineHandler(line);
  }
}

void FileReader::LineHandler(QByteArray line) {
  if (isVertexLine(line)) {
    VertexBufferBuild(line);
  } else if (isFacesLine(line)) {
    FacesBufferBuild(line);
  }
}

void FileReader::SortVertices() {
  if (vertices.empty() || faces.empty()) {
    qDebug() << "One of vectors is empty";
    return;
  }
  for (const auto &elem : faces) {
    int index = elem * 3 - 3;
    sorted_vertices.push_back(vertices[index]);
    sorted_vertices.push_back(vertices[index + 1]);
    sorted_vertices.push_back(vertices[index + 2]);
  }
}

std::vector<float> &FileReader::get_sorted_vertices() {
  if (vertices.empty() || faces.empty()) {
    qDebug() << "One of vectors is empty";
    return sorted_vertices;
  }
  SortVertices();
  return sorted_vertices;
}

int FileReader::get_faces_count() {
  if (faces.empty())
    qDebug() << "Faces is empty";
  return faces.size();
}

int FileReader::get_vertices_count() {
  if (vertices.empty())
    qDebug() << "Vertices is empty";
  return vertices.size() / 3;
}

void FileReader::VertexBufferBuild(QByteArray line) {
  QByteArray temp_v;
  for (const auto &elem : line) {
    if (std::isdigit(elem) || elem == '-' || elem == '.') {
      temp_v.push_back(elem);
    }
    if ((elem == ' ' || elem == '\n') && !temp_v.isEmpty()) {
      float f = temp_v.toFloat();
      vertices.push_back(f);
      temp_v.clear();
    }
  }
}

void FileReader::FacesBufferBuild(QByteArray line) {
  QByteArray temp_f;
  for (auto elem : line) {
    if (std::isdigit(elem) || elem == '/')
      temp_f.push_back(elem);
    if ((elem == ' ' || elem == '\n') && !temp_f.isEmpty()) {
      QByteArray q;
      for (auto it : temp_f) {
        if (it == '/')
          break;
        q.push_back(it);
      }
      int i = q.toInt();
      faces.push_back(i);
      temp_f.clear();
    }
  }
}

bool FileReader::isVertexLine(QByteArray line) {
  return (line[0] == 'v' && line[1] == ' ') ? true : false;
}

bool FileReader::isFacesLine(QByteArray line) {
  return line[0] == 'f' && line[1] == ' ' ? true : false;
}
} // namespace s21
