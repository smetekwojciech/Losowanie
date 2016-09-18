#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
// INIT

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    TeamsListed=new Teams;

    ui->setupUi(this);
    ui->TeamsList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->TeamsList,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showContextMenu( QPoint )));
    ui->NumberofTeamsBox->addItem("---");
    ui->NumberofTeamsBox->addItem("32");
    ui->NumberofTeamsBox->addItem("16");

    GroupsToDraw=NULL;
    AddButtonDisEn();
    DrawButtonDisEn();
}

MainWindow::~MainWindow()
{
    delete TeamsListed;
    delete ui;

}

void MainWindow::on_Add_clicked()
{   bool ok;
    QString input=QInputDialog::getText(this, tr("Wprowadz druzyny"),
                                        tr("Druzyna:"), QLineEdit::Normal,"..."
                                        , &ok);
    if(ok && !input.isEmpty())
    {
        TeamsListed->AddTeam(input);
        qDebug()<<"Added :"<<input<<endl;
        TeamsListed->PrintTeams();
        //qDebug()<<TeamsListed->TeamsToDrawList->first();

    }
    ui->TeamsList->clear();
    ui->TeamsList->addItems(TeamsListed->GetListOfTeams());

    AddButtonDisEn();
    DrawButtonDisEn();


}

void MainWindow::on_Clear_clicked()
{
    TeamsListed->ClearList();
    ui->TeamsList->clear();
    QMessageBox::information(this,"Czyszczenie","Wyczyszczono listę drużyn.",QMessageBox::Ok);
    AddButtonDisEn();
    DrawButtonDisEn();



}
void MainWindow::showContextMenu(const QPoint &pos)
{   // Metod that creates context menu with delete option

    QPoint globalPos=ui->TeamsList->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("Usuń",this,SLOT(deleteItem()));

    myMenu.exec(globalPos);


}

void MainWindow::deleteItem()
{   //Deleting element from teams list
    TeamsListed->DeleteItem(ui->TeamsList->currentRow());

    QListWidgetItem *item = (ui->TeamsList->takeItem(ui->TeamsList->currentRow()));
    delete item;
    AddButtonDisEn();
    //qDebug()<<"Po usunieciu :";
    //TeamsListed->PrintTeams();
}

void MainWindow::on_NumberofTeamsBox_currentIndexChanged(int index)
{

    if(index ==1)
    {

        ui->GrBox1->clear();
        ui->GrBox2->clear();
        NumberOfTeams=32;
        NumberOfGroups=NumberOfTeams/4;
        delete[] GroupsToDraw;
        GroupsToDraw=new Group[NumberOfGroups];


        for(int i=0;i<NumberOfGroups;i++)
        {
            GroupsToDraw[i].SetGroupNO(i);

            ui->GrBox1->addItem(static_cast<QString>(GroupsToDraw[i].GetGroupID()));
            ui->GrBox2->addItem(static_cast<QString>(GroupsToDraw[i].GetGroupID()));
        }
        ui->GrBox2->setCurrentIndex(1);
        //qDebug()<<"OK";


    }
    else if(index ==2)
    {

        ui->GrBox1->clear();
        ui->GrBox2->clear();
        NumberOfTeams=16;
        NumberOfGroups=NumberOfTeams/4;
        delete[] GroupsToDraw;
        GroupsToDraw=new Group[NumberOfGroups];


        for(int i=0;i<NumberOfGroups;i++)
        {
            GroupsToDraw[i].SetGroupNO(i);

            ui->GrBox1->addItem(static_cast<QString>(GroupsToDraw[i].GetGroupID()));
            ui->GrBox2->addItem(static_cast<QString>(GroupsToDraw[i].GetGroupID()));


        }
        ui->GrBox2->setCurrentIndex(1);

        if(TeamsListed->GetListOfTeams().size()>NumberOfTeams)
        {
            QMessageBox warning;

            int dif=(TeamsListed->GetListOfTeams().size())-(NumberOfTeams);
            QString msg=QString("Musisz usunąć %1 drużyn!").arg(dif);

            warning.setIcon(QMessageBox::Warning);
            warning.setText(msg);
            warning.exec();


        }
        //qDebug()<<"OK";
    }

    AddButtonDisEn();
    DrawButtonDisEn();
}

void MainWindow::AddButtonDisEn()
{   //Makes "Dodaj" disabled or enabled depending on a use case
    if(TeamsListed->GetListOfTeams().size()>=(NumberOfTeams)||ui->NumberofTeamsBox->currentIndex()==0)
        {
            ui->Add->setDisabled(true);
        }
    else
        {
            ui->Add->setEnabled(true);
        }

}

void MainWindow::DrawButtonDisEn()
{
    if(TeamsListed->GetListOfTeams().size()==(NumberOfTeams)!=0)
        {
            ui->Draw->setEnabled(true);
        }
    else
        {
            ui->Draw->setDisabled(true);
        }
}

void MainWindow::on_Draw_clicked()
{


    for(int i=0;i<NumberOfGroups;i++)
    {
        GroupsToDraw[i].ClearGroup();
        GroupsToDraw[i].SetEmpty();

    }

    //Drawing algoritm :
    for(int i=0;i<NumberOfTeams;i++)
    {
        int randomNumber=qrand()%NumberOfGroups;
        //qDebug()<<randomNumber;

        if(GroupsToDraw[randomNumber].CheckFull()==false)
        {
            GroupsToDraw[randomNumber].AddTeam(TeamsListed->GetTeam(i));
            if(GroupsToDraw[randomNumber].CheckSize()==4)
            {
                GroupsToDraw[randomNumber].SetFull();
            }
        }
        else
        {
            i--;
        }



    }
    //End of Drawing
    for(int i=0;i<NumberOfGroups;i++)
    {
        qDebug()<<GroupsToDraw[i].GetGroupTeamsList();

    }

    ui->GroupView1->addItems(GroupsToDraw[ui->GrBox1->currentIndex()].GetGroupTeamsList());
    ui->GroupView2->addItems(GroupsToDraw[ui->GrBox2->currentIndex()].GetGroupTeamsList());
}

void MainWindow::on_GrBox1_currentIndexChanged(int index)
{
    ui->GroupView1->clear();
    if(GroupsToDraw[index].CheckFull())
    {
        ui->GroupView1->addItems(GroupsToDraw[index].GetGroupTeamsList());
    }

}

void MainWindow::on_GrBox2_currentIndexChanged(int index)
{
    ui->GroupView2->clear();
    if(GroupsToDraw[index].CheckFull())
    {
        ui->GroupView2->addItems(GroupsToDraw[index].GetGroupTeamsList());
    }

}
