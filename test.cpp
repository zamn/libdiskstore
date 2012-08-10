#include <iostream>
#include <fstream>
#include "store.h"
#include "yaml-cpp/yaml.h"

int main(void) {
  // Sets up parser object for config file
  std::ifstream fin("config.yml");
  YAML::Parser parser(fin);
  YAML::Node doc;
  parser.GetNextDocument(doc);

  // Reads the path to write the blocks to in the filesystem
  std::string write_path;
  doc["write-path"] >> write_path;

  // Creates store object and tests functions
  Store s(write_path);
  s.open();

  return 0;
}
