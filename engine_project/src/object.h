#pragma once

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

            Vector3 speed;
            Vector3 acceleration;

            float reflectionFactor = 1.0f;

            Object(std::string _label = "unamed") {
                translation = Vector3();
                rotation = Quaternion(1.0f,0.0f,0.0f,0.0f);
                scale = Vector3(1.0f, 1.0f, 1.0f);

                mesh = nullptr;

                label = _label;

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

            void setTranslation(Vector3 t) {
                translation =  t;
            }

            void rotateObject(Quaternion r) {
                rotation = r * rotation;
            }

            void setRotation(Quaternion r) {
                rotation = r;
            }

            void scaleObject(Vector3 s) {
                scale = scale + s;
            }

            void setScale(Vector3 s) {
                scale = s;
            }

            Matrix4 modelMatrix() {
                return (
                        math::translate(translation) *
                        rotation.toMatrix() *
                        math::scale(scale)
                       );
            }

            virtual void update() {
                std::cout << "Hey, I am an object!" << std::endl;
            }

            void calculateCollisionsWithBox(float xInf, float xSup, float yInf, float ySup, float zInf, float zSup) {
                float bounceAmount = 0.01f;

                if (translation.x < xInf) {
                    speed = Vector3(-speed.x * reflectionFactor, speed.y * reflectionFactor, speed.z * reflectionFactor);
                    acceleration = Vector3(-acceleration.x * reflectionFactor, acceleration.y  * reflectionFactor, acceleration.z * reflectionFactor);
                    translation.x = translation.x + bounceAmount;
                    return;
                }

                if (translation.x > xSup) {
                    speed = Vector3(-speed.x * reflectionFactor, speed.y * reflectionFactor, speed.z * reflectionFactor);
                    acceleration = Vector3(-acceleration.x * reflectionFactor, acceleration.y  * reflectionFactor, acceleration.z * reflectionFactor);
                    translation.x = translation.x - bounceAmount;
                    return;
                }

                if (translation.y < yInf) {
                    speed = Vector3(speed.x * reflectionFactor, -speed.y * reflectionFactor, speed.z * reflectionFactor);
                    acceleration = Vector3(acceleration.x * reflectionFactor, -acceleration.y  * reflectionFactor, acceleration.z * reflectionFactor);
                    translation.y = translation.y + bounceAmount;
                    return;
                }

                if (translation.y > ySup) {
                    speed = Vector3(speed.x * reflectionFactor, -speed.y * reflectionFactor, speed.z * reflectionFactor);
                    acceleration = Vector3(acceleration.x * reflectionFactor, -acceleration.y  * reflectionFactor, acceleration.z * reflectionFactor);
                    translation.y = translation.y - bounceAmount;
                    return;
                }

                if (translation.z < zInf) {
                    speed = Vector3(speed.x * reflectionFactor, speed.y * reflectionFactor, -speed.z * reflectionFactor);
                    acceleration = Vector3(acceleration.x * reflectionFactor, acceleration.y  * reflectionFactor, -acceleration.z * reflectionFactor);
                    translation.z = translation.z + bounceAmount;
                    return;
                }

                if (translation.z > zSup) {
                    speed = Vector3(speed.x * reflectionFactor, speed.y * reflectionFactor, -speed.z * reflectionFactor);
                    acceleration = Vector3(acceleration.x * reflectionFactor, acceleration.y  * reflectionFactor, -acceleration.z * reflectionFactor);
                    translation.z = translation.z - bounceAmount;
                    return;
                }
            }
    };
};
