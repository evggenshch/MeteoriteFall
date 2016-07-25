#ifndef ATM_TABLE_EDIT_DIALOG_H
#define ATM_TABLE_EDIT_DIALOG_H

#include <QDialog>

namespace Ui {
class atm_table_edit_dialog;
}

class atm_table_edit_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit atm_table_edit_dialog(QWidget *parent = 0);
    ~atm_table_edit_dialog();

private slots:
    void on_table_edit_deny_button_clicked();

    void on_table_edit_ok_button_clicked();

private:
    Ui::atm_table_edit_dialog *ui;
};

#endif // ATM_TABLE_EDIT_DIALOG_H
