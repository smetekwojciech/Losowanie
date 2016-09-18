#include "teams.h"

Teams::Teams()
{

}
Teams::~Teams()
{
    TeamsToDrawList.clear();

}

void Teams::AddTeam(QString & team)
{
    TeamsToDrawList.append(team);
}
void Teams::PrintTeams()
{
    for(int i=0;i<TeamsToDrawList.size();i++)
    {
        qDebug()<<TeamsToDrawList.at(i);
    }

}

QStringList Teams::GetListOfTeams()
{
    return TeamsToDrawList;
}

QString Teams::GetTeam(int index)
{
    return TeamsToDrawList.at(index);
}

void Teams::ClearList()
{
    TeamsToDrawList.clear();
}


void Teams::DeleteItem(int index)
{
    TeamsToDrawList.removeAt(index);
}
