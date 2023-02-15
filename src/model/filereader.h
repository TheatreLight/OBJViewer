#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFile>
#include <QString>
#include <cctype>
#include <vector>

class FileReader {
public:
  explicit FileReader(QString path);
  std::vector<float> &get_sorted_vertices();
  int get_faces_count();
  int get_vertices_count();

private:
  void ReadFile(QString path);
  void LineHandler(QByteArray line);
  void SortVertices();
  void VertexBufferBuild(QByteArray line);
  void FacesBufferBuild(QByteArray line);
  bool isVertexLine(QByteArray line);
  bool isFacesLine(QByteArray line);
  std::vector<float> vertices;
  std::vector<int> faces;
  std::vector<float> sorted_vertices;
};

#endif // FILEREADER_H
