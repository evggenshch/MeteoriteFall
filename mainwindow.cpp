#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wopengl.h"
#include "model.h"
#include "atmosphere.h"
#include <QTimer>
#include <QButtonGroup>
//#include "main.cpp"

extern planet earth;
extern meteorite bolid;
extern planet default_earth;
extern meteorite default_bolid;
extern atmosphere earth_atm;
extern bool opengl_execute_flag;
extern QTimer *motion_timer;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    WOpengl *opengl_window = new WOpengl;
    opengl_window->show();
  //  motion_timer->start(1000);
}


void MainWindow::on_planet_mass_edit_textChanged(const QString &arg1)
{
    earth.mass = arg1.toDouble();
 //   earth.radius = ui->mass_edit->text().toDouble();
}

void MainWindow::on_meteorite_mass_edit_textChanged(const QString &arg1)
{
    bolid.mass = arg1.toDouble();
}

/*void MainWindow::on_planet_radius_edit_textChanged(const QString &arg1)
{

} */

void MainWindow::on_planet_radius_edit_textChanged(const QString &arg1)
{
    default_earth.radius = earth.radius = arg1.toDouble();
}

void MainWindow::on_meteorite_radius_edit_textChanged(const QString &arg1)
{
    default_bolid.radius = bolid.radius = arg1.toDouble();
}

void MainWindow::on_meteorite_x0_edit_textChanged(const QString &arg1)
{
    default_bolid.center.x = bolid.center.x = arg1.toDouble();
}

void MainWindow::on_meteorite_y0_edit_textChanged(const QString &arg1)
{
    default_bolid.center.y = bolid.center.y = arg1.toDouble();
}

void MainWindow::on_meteorite_z0_edit_textChanged(const QString &arg1)
{
    default_bolid.center.z = bolid.center.z = arg1.toDouble();
}

void MainWindow::on_meteorite_v0x_edit_textChanged(const QString &arg1)
{
    default_bolid.v.x = bolid.v.x =  arg1.toDouble();
}

void MainWindow::on_meteorite_v0y_edit_textChanged(const QString &arg1)
{
    default_bolid.v.y = bolid.v.y = arg1.toDouble();
}

void MainWindow::on_meteorite_v0z_edit_textChanged(const QString &arg1)
{
    default_bolid.v.z = bolid.v.z = arg1.toDouble();
}

void MainWindow::on_exit_open_triggered() {
      exit(0);
}

void MainWindow::on_add_atm_layer_button_clicked()
{
    double cur_density;
    double cur_height;
    double cur_gamma; // соотношение теплоемкостей c_p/c_v
    ui->atm_set_tableWidget->setRowCount(ui->atm_set_tableWidget->rowCount() + 1);
    //QTableWidgetItem cur;
    cur_density = ui->atm_set_tableWidget->item(ui->atm_set_tableWidget->rowCount(), 1)->text().toDouble();
    cur_height = ui->atm_set_tableWidget->item(ui->atm_set_tableWidget->rowCount(), 2)->text().toDouble();
    cur_gamma = ui->atm_set_tableWidget->item(ui->atm_set_tableWidget->rowCount(), 3)->text().toDouble();
    earth_atm.add_atm_layer(atm_layer(cur_density, cur_height, cur_gamma));
}

void MainWindow::on_atm_set_tableWidget_itemChanged(QTableWidgetItem *item)
{
    switch(item->column()) {
    case 1: {
        earth_atm.layers[item->row() - 1].height = item->text().toDouble();
        break;
    }
    case 2: {
        earth_atm.layers[item->row() - 1].gamma = item->text().toDouble();
        break;
    }
    case 3: {
        earth_atm.layers[item->row() - 1].density = item->text().toDouble();
        break;
    }
    default: {
        break;
    }
    }
}
