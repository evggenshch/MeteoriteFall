#include "atm_table_edit_dialog.h"
#include "ui_atm_table_edit_dialog.h"
//#include "wopengl.cpp"
//#include "mainwindow.ui"

atm_table_edit_dialog::atm_table_edit_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::atm_table_edit_dialog)
{
    ui->setupUi(this);
}

atm_table_edit_dialog::~atm_table_edit_dialog()
{
    delete ui;
}

void atm_table_edit_dialog::on_table_edit_deny_button_clicked()
{
    delete ui;
}

void atm_table_edit_dialog::on_table_edit_ok_button_clicked()
{
    delete ui;
}
