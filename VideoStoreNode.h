#ifndef VIDEOSTORENODE
#define VIDEOSTORENODE
#include <string>
#include "VideoStore.h"
#include "NodeAdditionalFunction.h"
#include "VideoStoreNode.h"

using namespace std;

class VideoStoreNode
{
private:

    string Name;
    string Director;
    string Year;
    int ActorCount;
    string *Actors;
    string User_id;
    string Date;
    string Check;
    VideoStoreNode* Next;

public:

    VideoStoreNode(string Nam, string Directo, string Yea, int ActorCout, string *Actor, string Chec, string User_i, string Dat);
    string GetName();
    string GetDirector();
    string GetYear();
    string* GetActor();
    int GetActorTotal();
    string GetUser_id();
    string GetDate();
    string GetCheck();
    VideoStoreNode* GetNext();

    void SetData(string Nam, string Directo, string Yea, int ActorCout, string* Actor, string Chec, string User_i, string Dat);
    void SetNextData(VideoStoreNode* Set_next);

};
#endif
