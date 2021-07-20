#ifndef VIDEOSTORE_H
#define VIDEOSTORE_H
#include <string>
#include "VideoStore.h"
#include "NodeAdditionalFunction.h"
#include "VideoStoreNode.h"
using namespace std;

/*
   command line to create a .exe file 
   g++ VideoStore.cpp NodeAdditionalFunction.cpp VideoStoreNode.cpp  project.cpp -o project.exe
*/

class VideoStore
{
private:
    /* data */
    int File_size;
    int When;
    string File_user_input;
    string Line;
    string Name;
    string Direction;
    string Year;
    int ActorCount;
    string *Actor;
    string UserInputActor;
    string User_id;
    string Date;
    string Check_in_and_out;
    int Select;

    int User_input;
    int Count;

public:
    NodeAdditionalFunction Node;
    void run();
    string Remove_leading_trailing_space(string Data);
    void User_interface();
};

#endif

