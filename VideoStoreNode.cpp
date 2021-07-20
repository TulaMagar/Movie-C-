#include <string>
#include <iostream>
#include <fstream>
#include "VideoStore.h"
#include "NodeAdditionalFunction.h"
#include "VideoStoreNode.h"

using namespace std;

/*
    build a Video Store node in this .cpp file
*/


/* 
    build a VideoStoreNode constructor and assign
    each argument to VideoStoreNode member variable 
*/
VideoStoreNode::VideoStoreNode(string Nam, string Directo, string Yea, int ActorCout, string *Actor, string Chec, string User_i, string Dat)
{
    Name = Nam;
    Director = Directo;
    Year = Yea;
    ActorCount = ActorCout;
    Actors = Actor;
    Check = Chec;
    User_id = User_i;
    Date = Dat;
    Next = NULL;
}


/*
    it will get Name from the node
*/
string VideoStoreNode::GetName()
{
    return Name;
}

/*
    it will get Director from the node
*/
string VideoStoreNode::GetDirector()
{
    return Director;
}

/*
    it will get Year from the node
*/
string VideoStoreNode::GetYear()
{
    return Year;
}


/*
    it will get Actors from the node which is array
*/
string* VideoStoreNode::GetActor()
{
    return Actors;
}

/*
    it will get total actors number from the node
*/
int VideoStoreNode::GetActorTotal()
{
    return ActorCount;
}

/*
    it will get user_id from the node
*/
string VideoStoreNode::GetUser_id()
{
    return User_id;
}

/*
    it will get Date from the node
*/
string VideoStoreNode::GetDate()
{
    return Date;
}

/*
    it will get check mark out or in from the node
*/
string VideoStoreNode::GetCheck()
{
    return Check;
}

/*
    it will get next data from the node
*/
VideoStoreNode* VideoStoreNode::GetNext()
{
    return Next;
}

/*
    it will set data to the node
*/
void VideoStoreNode::SetData(string Nam, string Directo, string Yea, int ActorCout, string *Actor, string Chec, string User_i, string Dat)
{
    Name = Nam;
    Director = Directo;
    Year = Yea;
    ActorCount = ActorCout;
    Actors = Actor;
    Check = Chec;
    User_id = User_i;
    Date = Dat;
}

/*
    it will set next node
*/
void VideoStoreNode::SetNextData(VideoStoreNode* Set_next)
{
    Next = Set_next;
}
