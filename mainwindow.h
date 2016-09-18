#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QInputDialog>
#include <QMessageBox>

#include "teams.h"
#include "group.h"

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
    void on_Add_clicked();

    void showContextMenu(const QPoint &pos);

    void deleteItem();

    void on_Clear_clicked();

    void on_NumberofTeamsBox_currentIndexChanged(int index);

    void AddButtonDisEn();

    void DrawButtonDisEn();

    void on_Draw_clicked();

    void on_GrBox1_currentIndexChanged(int index);

    void on_GrBox2_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Teams * TeamsListed;
    Group * GroupsToDraw;
    int NumberOfTeams;
    int NumberOfGroups;


};

#endif // MAINWINDOW_H
