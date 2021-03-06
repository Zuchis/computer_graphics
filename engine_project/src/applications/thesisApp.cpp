#include "../engine.h"
#include "../objects.h" 

#include <algorithm>
#include <time.h>
#include <unistd.h>

using namespace engine;

using std::vector;

FPSCamera* camera;

float xInf = -20.0f;
float xSup =  20.0f;
float yInf = -20.0f;
float ySup =  20.0f;
float zInf = -20.0f;
float zSup =  20.0f;

int frameCounter = 0;
int totalFrames = 1000;

size_t nObjects;

struct timespec time_diff(struct timespec start, struct timespec end) {
    struct timespec temp;
    if ((end.tv_nsec-start.tv_nsec)<0) {
        temp.tv_sec = end.tv_sec-start.tv_sec-1;
        temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
    } else {
        temp.tv_sec = end.tv_sec-start.tv_sec;
        temp.tv_nsec = end.tv_nsec-start.tv_nsec;
    }
    return temp;
}

void timekeeper_tic  (struct timespec *t1) {
    clock_gettime(CLOCK_MONOTONIC_RAW, t1);
}

double time_diff_double(struct timespec start, struct timespec end) {
    return time_diff(start, end).tv_sec + 1e-9 * time_diff(start, end).tv_nsec;
}

struct timespec draw_t1;
struct timespec draw_t2;

struct timespec update_t1;
struct timespec update_t2;

struct timespec colision_t1;
struct timespec colision_t2;

//FILE *drawF     = fopen("tests/draw.log", "w+");
//FILE *updateF   = fopen("tests/update.log", "w+");
//FILE *colisionF = fopen("tests/colision.log", "w+");
FILE *fpsF      = fopen("tests/fps.log", "w+");

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
    std::string sphere("objects/sphere.obj");
    std::string parallelogram("objects/tamParalel.obj");
    std::string suzanneStr("objects/suzanne.obj");

    Mesh* square = new Mesh(tamSquare);
    Mesh* ball = new Mesh(sphere);
    Mesh* parallel = new Mesh(parallelogram);
    Mesh* suzanne = new Mesh(suzanneStr);

    square->create();
    ball->create();
    parallel->create();
    suzanne->create();

    MeshManager::instance()->add("square",square);
    MeshManager::instance()->add("sphere",ball);
    MeshManager::instance()->add("parallel",parallel);
    MeshManager::instance()->add("suzanne",suzanne);

    checkOpenGLError("ERROR: Could not create VAOs and VBOs.");
}

void createObjects()
{
    Mesh* squareMesh = MeshManager::instance()->get("square");
    Mesh* ballMesh = MeshManager::instance()->get("sphere");
    Mesh* parallelMesh = MeshManager::instance()->get("parallel");
    Mesh* suzanneMesh = MeshManager::instance()->get("suzanne");

    Plane* plane = new Plane("plane");
    plane->setMesh(squareMesh);
    plane->speed = Vector3(0.001f, 0.002f, 0.003f);

    Sphere* ball = new Sphere("ball");
    ball->setMesh(ballMesh);
    ball->speed = Vector3(0.01f, 0.02f, 0.03f);

    Parallelogram* parallel = new Parallelogram("parallel");
    parallel->setMesh(parallelMesh);
    parallel->speed = Vector3(0.005f, 0.01f, 0.015f);

    Suzanne* suzanne = new Suzanne("suzanne");
    suzanne->setMesh(suzanneMesh);
    suzanne->speed = Vector3(0.015f, 0.025f, 0.0315f);

    ObjectManager::instance()->add("plane", plane);
    ObjectManager::instance()->add("ball", ball);
    ObjectManager::instance()->add("parallel", parallel);
    ObjectManager::instance()->add("suzanne", suzanne);
}

float nextRandom(float lo, float hi) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = hi - lo;
    float r = random * diff;
    return lo + r;
}

SceneNode* root;

vector<SceneNode*> planeNodes;
vector<SceneNode*> sphereNodes;
vector<SceneNode*> parallelNodes;
vector<SceneNode*> suzanneNodes;

void createSceneGraph() {
    size_t i;
    float lo = xInf + 1;
    float hi = xSup - 1;
    float x, y, z;

    std::string iter;

    Mesh* squareMesh = MeshManager::instance()->get("square");
    Mesh* ballMesh = MeshManager::instance()->get("sphere");
    Mesh* parallelMesh = MeshManager::instance()->get("parallel");
    Mesh* suzanneMesh = MeshManager::instance()->get("suzanne");

    SceneGraph* scenegraph = new SceneGraph();
    //camera = new ArcballCamera(UBO_BP);
    scenegraph->setCamera(new ArcballCamera(UBO_BP));

    scenegraph->getCamera()->setProjectionMatrix(
        math::Perspective(30.0f, winWidth / winHeight, 0.1f, 1000.0f));

    root = scenegraph->getRoot();
    root->setShaderProgram(ShaderProgramManager::instance()->get("default"));

    for (i = 0; i < nObjects; i++) {
        iter = std::to_string(i);

        x = nextRandom(lo, hi);
        y = nextRandom(lo, hi);
        z = nextRandom(lo, hi);

        Plane* plane = new Plane("plane" + iter);
        plane->setMesh(squareMesh);
        plane->speed = Vector3(0.001f, 0.002f, 0.003f);
        plane->setTranslation(Vector3(x, y, z));
        plane->setRotation(Quaternion(0.0f,Vector3(-1.0f,0.0f,0.0f)));
        plane->setScale(Vector3(5.0f, 0.5f, 5.0f));

        planeNodes.push_back(scenegraph->createNode("plane"));
        planeNodes[i]->setObject(plane);

        ObjectManager::instance()->add("plane" + iter, plane);

        x = nextRandom(lo, hi);
        y = nextRandom(lo, hi);
        z = nextRandom(lo, hi);

        Sphere* sphere = new Sphere("ball" + iter);
        sphere->setMesh(ballMesh);
        sphere->speed = Vector3(0.01f, 0.02f, 0.03f);
        sphere->setTranslation(Vector3(x,y,z));
        sphere->setRotation(Quaternion(0.0f,Vector3(-1.0f,0.0f,0.0f)));
        sphere->setScale(Vector3(1.0f, 1.0f, 1.0f));

        sphereNodes.push_back(scenegraph->createNode("ball"));
        sphereNodes[i]->setObject(sphere);

        ObjectManager::instance()->add("sphere" + iter, sphere);

        x = nextRandom(lo, hi);
        y = nextRandom(lo, hi);
        z = nextRandom(lo, hi);

        Parallelogram* parallel = new Parallelogram("parallel" + iter);
        parallel->setMesh(parallelMesh);
        parallel->speed = Vector3(0.005f, 0.01f, 0.015f);
        parallel->setTranslation(Vector3(x,y,z));
        parallel->setRotation(Quaternion(0.0f,Vector3(-1.0f,0.0f,0.0f)));
        parallel->setScale(Vector3(1.0f,1.0f,0.0f));

        parallelNodes.push_back(scenegraph->createNode("parallel"));
        parallelNodes[i]->setObject(parallel);

        ObjectManager::instance()->add("parallel" + iter, parallel);

        x = nextRandom(lo, hi);
        y = nextRandom(lo, hi);
        z = nextRandom(lo, hi);

        Suzanne* suzanne = new Suzanne("suzanne" + iter);
        suzanne->setMesh(suzanneMesh);
        suzanne->speed = Vector3(0.015f, 0.025f, 0.0315f);
        suzanne->setTranslation(Vector3(x,y,z));
        suzanne->setRotation(Quaternion(0.0f,Vector3(-1.0f,0.0f,0.0f)));
        suzanne->setScale(Vector3(1.0f,1.0f,1.0f));

        suzanneNodes.push_back(scenegraph->createNode("parallel"));
        suzanneNodes[i]->setObject(suzanne);

        ObjectManager::instance()->add("suzanne" + iter, suzanne);
    }

    SceneGraphManager::instance()->add("default",scenegraph);
}

//void setViewProjectionMatrix() 
//{
    //Matrix4 viewMatrix = camera->getViewMatrix();

    //camera->setProjectionMatrix(
        //math::Perspective(math::toRadians(camera->zoom), winWidth / winHeight, 0.1f, 1000.0f));

    //camera->setViewMatrix(viewMatrix);
//}

void setViewProjectionMatrix() {
    Matrix4 translation = math::translate(Vector3(0.0f,0.0f,(cameraDistance * -1)));
    Matrix4 rotation    = rotationQuaternion.toMatrix();
    SceneGraphManager::instance()->get("default")->getCamera()->setViewMatrix(translation * rotation);
}

void updateAccelerations() {
    auto objects = ObjectManager::instance()->getObjects();
    auto it = objects.begin();
    float x, y, z;
    float lo = -0.01f;
    float hi = 0.01f;
    for(it = objects.begin(); it != objects.end(); it++) {
        x = nextRandom(lo, hi);
        y = nextRandom(lo, hi);
        z = nextRandom(lo, hi);
        it->second->acceleration = Vector3(x, y, z);
    }
}

float lastTime = 0;
float currentTime = 0;

float timeForEnding = 12;

void drawScene()
{
    setViewProjectionMatrix();


    timekeeper_tic(&draw_t1);

    SceneGraphManager::instance()->get("default")->draw();

    timekeeper_tic(&draw_t2);

    //fprintf(drawF, "%f\n", time_diff_double(draw_t1, draw_t2) * 1000);

    glUseProgram(0);
    glBindVertexArray(0);
}

void computeCameraMovement() 
{
    if(KeyBuffer::instance()->isKeyDown('w'))
        camera->computeKeyboardInputs(FORWARD,deltaTime);

    if(KeyBuffer::instance()->isKeyDown('s'))
        camera->computeKeyboardInputs(BACKWARD,deltaTime);

    if(KeyBuffer::instance()->isKeyDown('a'))
        camera->computeKeyboardInputs(LEFT,deltaTime);

    if(KeyBuffer::instance()->isKeyDown('d'))
        camera->computeKeyboardInputs(RIGHT,deltaTime);

    //if(zoomFactor != 0.0f)
        //camera->computeMouseScroll(zoomFactor);

    if (deltaX != 0 || deltaY != 0)
        camera->computeMouseMovement(deltaX, -deltaY);
    
}

void computeInputs() 
{
    computeCameraMovement();
}

void computePhysics()
{
    //updateAccelerations();


    timekeeper_tic(&update_t1);

    ObjectManager::instance()->updateObjects();

    timekeeper_tic(&update_t2);

    //fprintf(updateF, "%f\n", time_diff_double(update_t1, update_t2) * 1000);

    timekeeper_tic(&colision_t1);

    ObjectManager::instance()->calculateObjectsCollisionsWithBox(xInf, xSup, yInf, ySup, zInf, zSup);

    timekeeper_tic(&colision_t2);

    //fprintf(colisionF, "%f\n", time_diff_double(colision_t1, colision_t2) * 1000);
}

void display()
{
    currentTime = timeSinceStart();
    if (currentTime - lastTime >= timeForEnding) {
        std::cout << "Parando após " << timeForEnding << " segundos" << std::endl;
        glutDestroyWindow(currentWindow);
        exit(0);
    } else {
        ++FrameCount;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        computeTime();
        computePhysics();
        drawScene();
        glutSwapBuffers();
        frameCounter++;
    }
}

//void display()
//{
    //if (frameCounter <= totalFrames + 1) {
        //++FrameCount;
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //computeTime();
        //computePhysics();
        //drawScene();
        //glutSwapBuffers();
        //frameCounter++;
    //} else {
        //std::cout << "Parando após " << totalFrames << " execuções" << std::endl;
        //glutDestroyWindow(currentWindow);
        //exit(0);
    //}
//}
//

void timer(int value)
{
    std::ostringstream oss;
    oss << winCaption << ": " << FrameCount << " FPS @ (" << winWidth << "x" << winHeight << ")";
    std::string s = oss.str();
    glutSetWindow(currentWindow);
    glutSetWindowTitle(s.c_str());

    if (FrameCount != 0) {
        fprintf(fpsF, "%d\n", FrameCount);
    }

    FrameCount = 0;
    glutTimerFunc(1000, timer, 0);
}

void init(int argc, char* argv[])
{
    nObjects = atoi(argv[1]);
    engine_init(argc,argv);
    glutTimerFunc(0,timer,0);
    glutDisplayFunc(display);

    createMeshes();

    createShaderProgram();

    createObjects();

    createSceneGraph();
}

int main(int argc, char* argv[])
{
    init(argc, argv);
    glutMainLoop();
    exit(EXIT_SUCCESS);
}
