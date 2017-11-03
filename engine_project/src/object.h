#ifndef OBJECT_H
#define OBJECT_H

#include "GL/glew.h"
#include "GL/freeglut.h"

#include "mesh.h"
#include "matrixfactory.h"
#include "quaternion.h"

namespace engine {
    using math::Quaternion;
    using math::Matrix4;

    class Object {
        public: 
            Vector3 translation;
            Quaternion rotation;
            Vector3 scale;

            Mesh* mesh;

            std::string label;

            Vector3 direction;
            Vector3 speed;
            Vector3 acceleration;

            Object(std::string _label = "unamed") {
                translation = Vector3();
                rotation = Quaternion(1.0f,0.0f,0.0f,0.0f);
                scale = Vector3(1.0f, 1.0f, 1.0f);

                mesh = nullptr;

                label = _label;
                
                direction = Vector3();
                speed = Vector3();
                acceleration = Vector3();
            }

            void setMesh(Mesh* _mesh) {
                mesh = _mesh;
            }

            void draw() {
                if (mesh == nullptr) {
                    std::cout << "Object " << label << " has no mesh set" << std::endl;
                    return;
                }

                glBindVertexArray(mesh->vaoId);
                glDrawArrays(GL_TRIANGLES,0,(GLsizei)mesh->vertices.size());
            }

            void translateObject(Vector3 t) {
                translation = translation + t;
            }

            void rotateObject(Quaternion r) {
                rotation = r * rotation;
            }

            void scaleObject(Vector3 s) {
                scale = scale + s;
            }

            Matrix4 modelMatrix() {
                return (
                        math::translate(translation) *
                        rotation.toMatrix() *
                        math::scale(scale)
                       );
            }

            void update() {
            }
    };
};

#endif
