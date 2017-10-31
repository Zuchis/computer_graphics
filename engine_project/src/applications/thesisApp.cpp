#include "../engine.h"

using namespace engine;

void createShaderProgram()
{
    ShaderProgram *program = new ShaderProgram();

    program->compileShaderFromFile("shaders/vertexShaderSceneManagement.vert",ShaderType::VERTEX);

    program->compileShaderFromFile("shaders/fragmentShaderSceneManagement.frag",ShaderType::FRAGMENT);

    program->bindAttribLocation(VERTICES,"in_Position");
    program->bindAttribLocation(TEXCOORDS,"in_TexCoords");
    program->bindAttribLocation(NORMALS,"in_Normal");
    program->addUniformBlock("Camera", UBO_BP);

    program->link();

    ShaderProgramManager::instance()->add("default",program);

    //checkOpenGLError("ERROR: Could not create shaders.");
}

void createMeshes()
{

    std::string tamSquare("objects/tamSquare.obj");

    Mesh *square = new Mesh(tamSquare);

    square->create();

    MeshManager::instance()->add("square",square);

    checkOpenGLError("ERROR: Could not create VAOs and VBOs.");
}

SceneNode *ground;
SceneNode* root;

void createSceneGraph() {
    SceneGraph* scenegraph = new SceneGraph();
    scenegraph->setCamera(new ArcballCamera(UBO_BP));

    scenegraph->getCamera()->setProjectionMatrix(
            math::Perspective(30.0f, winWidth / winHeight, 0.1f, 100.0f));

    Mesh* squareMesh = MeshManager::instance()->get("square");

    root = scenegraph->getRoot();
    root->setShaderProgram(ShaderProgramManager::instance()->get("default"));

    ground = scenegraph->createNode("ground");
    ground->setMesh(squareMesh);
    ground->setModelMatrix(math::translate(Vector3(0.0f,0.0f,0.0f)) *
            Quaternion(0.0f,Vector3(-1.0f,0.0f,0.0f)).toMatrix() *
            math::scale(Vector3(4.0f,3.0f,0.4f)));

    SceneGraphManager::instance()->add("squirrel",scenegraph);
}

void setViewProjectionMatrix() {
    Matrix4 translation = math::translate(Vector3(0.0f,0.0f,(cameraDistance * -1)));
    Matrix4 rotation    = rotationQuaternion.toMatrix();
    SceneGraphManager::instance()->get("squirrel")->getCamera()->setViewMatrix(translation * rotation);
}

void drawScene()
{
    setViewProjectionMatrix();
    SceneGraphManager::instance()->get("squirrel")->draw();

    glUseProgram(0);
    glBindVertexArray(0);
}

void display()
{
    ++FrameCount;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    computeTime();
    drawScene();
    glutSwapBuffers();
}

void init(int argc, char* argv[])
{
    engine_init(argc,argv);
    glutDisplayFunc(display);

    createMeshes();

    createShaderProgram();

    createSceneGraph();
}

int main(int argc, char* argv[])
{
    init(argc, argv);
    glutMainLoop();
    exit(EXIT_SUCCESS);
}
