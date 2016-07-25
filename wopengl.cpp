#include "wopengl.h"
#include "model.h"
#include "mainwindow.h"
#include <QtOpenGL>
#include <QGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <GL/glcorearb.h>
#include "math.h"
#include "qgl.h"
//#include <time.h>
#include <glm/gtc/matrix_transform.hpp>
#include <QThread>
#include <QTimer>
#include <gl_font.h>
#include "atmosphere.h"

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};



// Прозрачность -glBlendFunc(GL_ONE, GL_ONE);

/*

Ближайшие задачи:

1.Написать вращение вокруг своей оси
2.Поменять названия вкладок +
3.Написать камеру(масштабируемость) (домножать на коэффициент?) [можно улучшить, написав "свободную" камеру] glScalef(
4.Полностью прописать взаимодействие со внутренними объектами
5.Адекватно переименовать объекты
6.Перейти от сферической модели болида к модели многогранника
7.Запретить редактирование полей во время работы модели
8.Сделать разбор для степени 10 в массе
9.Вывод показателей скорости, координат в OpenGL

*/

// Привязка камеры к метеориту???

/*

  Этапы работы:

  I. Базовые отрисовка и интерфейс
  II. Базовая аэродинамика
  III. Базовая механика
  IV. Усложненная отрисовка
  V.Усложненная аэродинамика
  VI. Усложненная механика
  VII. Окончательная отрисовка

  */

extern bool opengl_execute_flag;


/* class WheelHandler : public QObject
{
public:
  WheelHandler( QGLWidget * glw ) : QObject( mt )
  {
    mt->installEventFilter( this );
  }
  bool eventFilter( QObject* watched, QEvent* e )
  {
     if ( !watched.inherits( "MyTable" ) ) return false;
     QGLWidget * mt = (QGLWidget*) watched;
     if ( e->type == QEvent::Wheel ) {
       mt->wheelEvent();
       return true;
     }
     return false;
  }

};   */

/* void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
} */

extern planet earth;
extern meteorite bolid;
extern planet default_earth;
extern meteorite default_bolid;
extern atmosphere earth_atm;
extern QTimer *motion_timer;
double ti = 0;

//Sleeper s;

WOpengl::WOpengl()
{
    QTimer *motion_timer = new QTimer(this);
    connect(motion_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    motion_timer->start(50);
}

/*void WOpengl::updateGL() {

} */

/*bool WOpengl::eventFilter( QObject *obj, QEvent *e )
{
    if ( e->type() == QEvent::Wheel ) {
        QMessageBox::information( NULL, "", "wheel event");
        return true;
    }
    else
    if ( e->type() == QEvent::KeyPress ) {
        QMessageBox::information( NULL, "", "key event");
        return TRUE;
    }
    else {
        return QGLWidget::eventFilter( obj, e );
    }
} */

void WOpengl::closeEvent(QCloseEvent *event) {
    bolid = default_bolid;
    earth = default_earth;
    event->accept();
}

void WOpengl::initializeGL()
{
    qglClearColor(Qt::black);


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void WOpengl::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, nWidth, nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
  //  glMatrixMode(GL_MODELVIEW);
}

void WOpengl::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    opengl_execute_flag = true;
    scene();
  //  count_step(bolid, earth);
    ++ti;
    if(ti > 360.0) {
        ti = 0.0;
    }
//    opengl_execute_flag = false;
    swapBuffers();
}

void WOpengl::scene()
{

    qglColor(Qt::blue);
    glBegin(GL_QUADS);
    GLUquadricObj *quadObj;
    quadObj = gluNewQuadric();

//    gluPerspective(40, 0, 0, 0);

    glPushMatrix();
     glColor3d(0,0,1);
     gluQuadricDrawStyle(quadObj,GLU_LINE); // устанавливаем
                              // стиль: сплошной

     glRotated(ti, 0.0, 0.0, 1.0);
     gluSphere(quadObj, (earth.radius / 100), 30, 30); // рисуем сферу
                                      // радиусом 0.5

     glRotated(-ti, 0.0, 0.0, 1.0);
    glPopMatrix();
    glPushMatrix();
     glTranslated((bolid.center.x / 100), (bolid.center.y / 100), (bolid.center.z / 100)); // сдвигаемся влево
   //  glRotated(45, 1,0,0); // поворачиваем
     glColor3d(0,1,0);
     gluQuadricDrawStyle(quadObj, GLU_POINT); // устанавливаем
                              // стиль: проволочный

   //  glRotated(ti, 0, 1, 0);
      glTranslated((-bolid.center.x / 100), (-bolid.center.y / 100), (-bolid.center.z / 100));
     gluSphere(quadObj, (bolid.radius / 100), 30, 30);
    // glRotated(-ti, 0, 1, 0);

     // здесь вывод текста

//     glFont = new oglFont(256, 256, 20, 35);
//     glFont->drawText(labelWidth, labelHeight, txt);

     //  motion_timer->start(500);

 /*   oglFont *glFont;
    glFont = new oglFont(256, 256, 20, 35);
    glFont->drawText(40, 15, "123"); */

    glPopMatrix();
    glEnd();
}

void WOpengl::rotate()
{
 //Проверяем переполнение (360 градусов)
 (angle_x > 360)? angle_x = 0 : 0;
 (angle_z > 360)? angle_z = 0 : 0;
 //Проверяем переполнение (0 градусов)
 (angle_x < 0)? angle_x = 360: 0;
 (angle_z < 0)? angle_z = 360: 0;


 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();


 //Очищаем экран
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


 //Делаем поворот системы
 glRotated(angle_x,1,0,0);
 glRotated(angle_z,0,1,0);


 //Вызываем функцию отрисовки
// paintGL();
}

/*void WOpengl::motion()
{
   count_step(bolid, earth);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
} */

/* void WOpengl::selfRotate () {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
} */

void WOpengl::mouseMoveEvent(QMouseEvent*me)
{
/*Проверка сильно большого отклонения - например, чтобы сцена не
самовращалась при сворачивании-розварачивании окна, при
перемещении на большое расстояние курсора с отпускнием и т.д.
Не есть обязательным - но так естественнее */
if(abs(me->x()-mouse_x)>=20)
  mouse_x=me->x();
if(abs(me->y()-mouse_y)>=20)
  mouse_y=me->y();


//Меняем угол поворота в зависимости от положения мыши
angle_x += (mouse_y-me->y())/2;
angle_z += (mouse_x-me->x())/2;


/*Сохраняем текущее значение координат курсора для возможности определения
 скорости их изменения. */
mouse_x = me->x();
mouse_y = me->y();


//Вызываем метод, который обработает поворот и выведет обновленное изображение
rotate();
}

void WOpengl::console_information() {
    printf("%lf/n", bolid.center.x);
}


/*void WOpengl::WheelEvent(QWheelEvent *we)  // не перехватывается
{
int num_degrees = we->delta() / 8;

earth.radius = 10;

//if(num_degrees > 5) { // защита от случайной прокрутки
  scale += num_degrees;
//}

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

paintGL();
} */

/* glBegin(GL_QUADS);
 glVertex3f (0.51, 0.51, 0.51);
 glVertex3f (-0.51, 0.51, 0.51);
 glVertex3f (-0.51, -0.51, 0.51);
 glVertex3f (0.51, -0.51, 0.51);
 glEnd(); */

/*    GLUquadricObj *quadObj;
 quadObj = gluNewQuadric();
 gluQuadricDrawStyle(quadObj, GLU_FILL);

 gluSphere(quadObj, 2,10,10); */
/* glBegin(GL_POINTS);
 auxSolidSphere(1);
 glEnd(); */

//GLUquadricObj *quadObj;
//glClear(GL_DEPTH_BUFFER_BIT or GL_COLOR_BUFFER_BIT);
//glPushMatrix();
//quadObj = gluNewQuadric();
//gluQuadricDrawStyle(quadObj, GLU_FILL);
//glColor3f(1,0,0);
//gluSphere(quadObj, 2,10,10);
//glRotatef(3, 0,1,0);
//gluDeleteQuadric(quadObj);
//glPopMatrix();




//  glRotated(-45, 1,0,0);
//  glTranslated(1,0,0);

  //gluCylinder(quadObj, 0.5, 0.75, 1, 15, 15);
 // while(true) {
 //     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 //     gluSphere(quadObj, (earth.radius / 100), 30, 30);
 //     glRotated(15, 0, 0, 0);
 //     sleep(1000);
//  }
