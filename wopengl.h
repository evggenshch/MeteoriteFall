#ifndef WOPENGL_H
#define WOPENGL_H

#include <QGLWidget>

class WOpengl : public QGLWidget
{
public:
    WOpengl();
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    double angle_x;
    double angle_z;
    double mouse_x;
    double mouse_y;
    double scale; // коэффициент масштабирования
   void mouseMoveEvent(QMouseEvent *me);
   void motion();
   void selfRotate();
   void console_information();
//    void WheelEvent(QWheelEvent *we);
    double angle;
     void rotate();
     QTimer *timer;
    void scene();
public slots:
    void tiktack();
    void closeEvent(QCloseEvent *event);
/*protected:
    bool eventFilter( QObject *obj, QEvent *ev ); */
};

#endif // WOPENGL_H
