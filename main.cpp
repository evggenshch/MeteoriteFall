#include "mainwindow.h"
#include "model.h"
#include <QApplication>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "planet.h"
#include "atmosphere.h"
//#define execute_condition count_distance(met, earth)


/* double count_distance () {   // реализовать с помощью шаблонов

} */

planet earth;
meteorite bolid;
planet default_earth;
meteorite default_bolid;
atmosphere earth_atm;
bool opengl_execute_flag = false;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    meteorite met;
    earth.mass = 0;
    double fall_time = 0;

    /* while(execute_condition) {
      fall_time += step;
    } */


    return a.exec();
}

