#ifndef GROUP_H
#define GROUP_H
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QSaveFile>

class Group
{
public:
    Group();
    char GetGroupID();
    void AddTeam(QString & TeamName);
    void SetGroupNO(int no);
    void SetGroupID(char id);
    void ClearGroup();
    int CheckSize();
    void SetFull();
    void SetEmpty();
    bool CheckFull();
    bool CheckEmpty();
    QStringList GetGroupTeamsList();
private:
    QStringList GroupTeamsList;
    char GroupID;
    int GroupNO;
    bool IsFull;
};

#endif // GROUP_H
