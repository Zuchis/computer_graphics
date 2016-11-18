#ifndef OBJECTLOADER_H
#define OBJECTLOADER_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "matrixfactory.h"

using math::Vector3;
using math::Vector2;

namespace engine {

    class ObjectLoader {

        public:
           bool texcoordsLoaded, normalsLoaded; 
           std::vector<float*> vertices, normals;
           std::vector<Vector3> vertexData, normalData;
           std::vector<float*> texcoords;
           std::vector<Vector2> texcoordData;
           std::vector<unsigned int> vertexIdx, texcoordIdx, normalIdx;

           ObjectLoader() {}

           void parseVertex(std::stringstream& sin) {
               Vector3 v = Vector3();
               sin >> v.x >> v.y >> v.z;
               std::cout << v << std::endl;
               vertexData.push_back(v);
           }

           void parseTexcoord(std::stringstream& sin) {
               Vector2 v = Vector2();
               sin >> v.x >> v.y;
               texcoordData.push_back(v);
           }

           void parseNormal(std::stringstream& sin) {
               Vector3 v = Vector3();
               sin >> v.x >> v.y >> v.z;
               normalData.push_back(v);
           }

           void parseFace(std::stringstream& sin) {
            std::string token;
            for(int i = 0; i < 3; i++) {
                    std::getline(sin, token, '/');
                    if(token.size() > 0) vertexIdx.push_back(std::stoi(token));
                    std::getline(sin, token, '/');
                    if(token.size() > 0) texcoordIdx.push_back(std::stoi(token));
                    std::getline(sin, token, ' ');
                    if(token.size() > 0) normalIdx.push_back(std::stoi(token));
                }
           }

           void parseLine(std::stringstream& sin){
               std::string s;
               sin >> s;
               if(s.compare("v") == 0)
                   parseVertex(sin);
                else if(s.compare("vt") == 0)
                    parseTexcoord(sin);
                else if(s.compare("vn") == 0)
                    parseNormal(sin);
                else if(s.compare("f" ) == 0)
                    parseFace(sin);
           }

           void loadMeshData(std::string& filename) {
                std::ifstream ifile(filename);
                while(ifile.good()) {
                    std::string line;
                    std::getline(ifile, line);
                    std::stringstream sin(line);
                    parseLine(sin);
                }
                texcoordsLoaded = (texcoordIdx.size() > 0);
                normalsLoaded = (normalIdx.size() > 0);
           }

            void processMeshData(){
                for(unsigned int i = 0; i < vertexIdx.size(); i++ ) {
                        unsigned int vi = vertexIdx[i];
                        Vector3 v = vertexData[vi - 1];
                        vertices.push_back(v.getData());
                        if(texcoordsLoaded) {
                                unsigned int ti = texcoordIdx[i];
                                Vector2 t = texcoordData[ti - 1];
                                texcoords.push_back(t.getData());
                        }
                        if(normalsLoaded) {
                                unsigned int ni = normalIdx[i];
                                Vector3 n = normalData[ni - 1];
                                normals.push_back(n.getData());
                        }
                }
            }

            ~ObjectLoader() {
                vertexData.clear();
                texcoordData.clear();
                normalData.clear();
                vertexIdx.clear();
                texcoordIdx.clear();
                normalIdx.clear();
            }


    };

};

#endif
