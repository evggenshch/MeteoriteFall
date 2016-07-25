#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_mass_edit_textChanged();

    void on_mass_edit_textChanged(const QString &arg1);

    void on_planet_radius_edit_textChanged(const QString &arg1);

    void on_meteorite_radius_edit_textChanged(const QString &arg1);

    void on_meteorite_x0_edit_textChanged(const QString &arg1);

    void on_meteorite_y0_edit_textChanged(const QString &arg1);

    void on_meteorite_z0_edit_textChanged(const QString &arg1);

    void on_meteorite_v0x_edit_textChanged(const QString &arg1);

    void on_meteorite_v0y_edit_textChanged(const QString &arg1);

    void on_meteorite_v0z_edit_textChanged(const QString &arg1);

    void on_planet_mass_edit_textChanged(const QString &arg1);

    void on_meteorite_mass_edit_textChanged(const QString &arg1);

    void on_exit_open_triggered();

    void on_add_atm_layer_button_clicked();

    void on_atm_set_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
