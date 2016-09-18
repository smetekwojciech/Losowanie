#include "group.h"

Group::Group()
{
    IsFull=false;
}

char Group::GetGroupID()
{
    return GroupID;
}

void Group::AddTeam(QString & TeamName)
{
   GroupTeamsList.push_front(TeamName);
}

void Group::SetGroupID(char id)
{
    GroupID=id;
}

void Group::ClearGroup()
{
    GroupTeamsList.clear();
}

int Group::CheckSize()
{
    return GroupTeamsList.size();
}

void Group::SetFull()
{
    IsFull=true;
}

void Group::SetEmpty()
{
    IsFull=false;
}

void Group::SetGroupNO(int no)
{
    GroupNO=no;
    if(no==0)
    {
        SetGroupID('A');
       // qDebug()<<"Grupa "<<GroupID;
    }
    if(no==1)
    {
        SetGroupID('B');
       // qDebug()<<"Grupa "<<GroupID;
    }
    if(no==2)
    {
        SetGroupID('C');
       // qDebug()<<"Grupa "<<GroupID;
    }
    if(no==3)
    {
        SetGroupID('D');
    }
    if(no==4)
    {
        SetGroupID('E');
    }
    if(no==5)
    {
        SetGroupID('F');
    }
    if(no==6)
    {
        SetGroupID('G');
    }
    if(no==7)
    {
        SetGroupID('H');
    }


}

QStringList Group::GetGroupTeamsList()
{
    return GroupTeamsList;
}
bool Group::CheckFull()
{
    if(IsFull==true){return true;}
    else {return false;}
}

bool Group::CheckEmpty()
{
    return GroupTeamsList.isEmpty();
}
