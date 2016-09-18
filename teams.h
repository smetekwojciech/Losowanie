#ifndef TEAMS_H
#define TEAMS_H
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QDir>

class Teams
{
public:
    Teams();
    void DeleteItem(int index);
    void ClearList();
    void AddTeam(QString & team);
    void PrintTeams();
    QStringList GetListOfTeams();
    QString GetTeam(int index);
    ~Teams();


private:
    QStringList TeamsToDrawList;


};

#endif // TEAMS_H
