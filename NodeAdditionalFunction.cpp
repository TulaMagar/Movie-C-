#include <string>
#include <iostream>
#include <fstream>
#include "VideoStore.h"
#include "NodeAdditionalFunction.h"
#include "VideoStoreNode.h"

using namespace std;

/*
  sort the data by movie name
  and add each data to the head of the node
*/
void NodeAdditionalFunction::Add(string Name, string Director, string Year, int ActorCout, string* Actors, string Check, string User_id, string Date)
{
    if (Head == NULL) {
        VideoStoreNode* NewNode = new VideoStoreNode(Name, Director, Year, ActorCout, Actors, Check, User_id, Date);
        Head = NewNode;
    }
    else {
        VideoStoreNode* Current = Head;
        VideoStoreNode* Previous = NULL;
        Stop = false;
        while (Current != NULL && !Stop) {
            if (Current->GetName() > Name) {
                Stop = true;
            }
            else {
                Previous = Current;
                Current = Current->GetNext();
            }
        }
        VideoStoreNode* Temporary = new VideoStoreNode(Name, Director, Year, ActorCout, Actors, Check, User_id, Date);
        if (Previous == NULL)
        {
            Temporary->SetNextData(Head);
            Head = Temporary;
        }
        else
        {
            Temporary->SetNextData(Current);
            Previous->SetNextData(Temporary);
        }
    }
}


/*
    It will set old data to new data in the node
*/
void NodeAdditionalFunction::Updata_data(int Selected_number, string CheckMar, string User_d, string Dat)
{
    Position = 0;
    VideoStoreNode* Current = Head;

    while (Current != NULL) 
    {

        if (Position == Index + Selected_number - 1)
        {
            Current->GetCheck() = CheckMar;
            Current->GetUser_id() = User_d;
            Current->GetDate() = Dat;
            Current->SetData(Current->GetName(), Current->GetDirector(), Current->GetYear(), Current->GetActorTotal(), Current->GetActor(), Current->GetCheck() = CheckMar, Current->GetUser_id() = User_d,Current->GetDate() = Dat);
            
            for (int i = 0; i < Current->GetActorTotal(); i++)
            {
                JoinActors = JoinActors + Current->GetActor()[i] + " ";
            }

            cout << "\n";
            cout << Current->GetName() << " " + Current->GetDirector() << " " + Current->GetYear() + " ";
            cout << Current->GetActorTotal() << " " + JoinActors << Current->GetCheck();
            cout << " " + Current->GetUser_id() << " " + Current->GetDate() << endl;
            JoinActors = "";
        }

        Current = Current->GetNext();
        Position++;
    }
    Index = 0;
}


/*
    prefix search of movie name 

*/
void NodeAdditionalFunction::SearchName(string Item)
{
    VideoStoreNode* Current = Head;
    Found_count = 0;
    Display = 4;
    GiveNumber = 1;
    while (Current != NULL)
    {
        Count++;
        Name = To_lower_case(Current->GetName().substr(0, Item.length()));
        Item = To_lower_case(Item.substr(0, Item.length()));
        if ( Name == Item && Found_count < Display) // change User_input_data to userinput and
                                                    // From_node_data to current node data 
        {
            DataFound = "DataExist";
            if (GiveNumber == 1)
            {
                Count = Index;
            }
            for (int i = 0; i < Current->GetActorTotal(); i++)
            {
                JoinActors = JoinActors + Current->GetActor()[i] + " ";
            }

            cout << GiveNumber++ << ": ";
            cout << Current->GetName() << " " + Current->GetDirector() << " " + Current->GetYear() + " ";
            cout << Current->GetActorTotal() << " " + JoinActors << Current->GetCheck();
            cout << " " + Current->GetUser_id() << " " + Current->GetDate() << endl;
            JoinActors = "";
            Current = Current->GetNext();
            Found_count++;

            if (Display == Found_count)
            {
                string Option;
                cout << "Would you like to look more yes or no: ";
                cin >> Option;
                if (To_lower_case(Option) == "yes")
                {
                    Display = Display * 2;
                }
                else
                {
                    cout << "Thank you for looking DB in here" << endl;
                }
            }
        }
        else {
            Current->GetName();
            Current = Current->GetNext();

        }
    }
    Found_count = 0;
    Count = 0;
}


/*
    prefix search of movie director 

*/
void NodeAdditionalFunction::SearchDirector(string Item)
{
    VideoStoreNode* Current = Head;
    Found_count = 0;
    Display = 4;
    GiveNumber = 1;
    while (Current != NULL)
    {
        Count++;
        Director = To_lower_case(Current->GetDirector().substr(0, Item.length()));
        Item = To_lower_case(Item.substr(0, Item.length()));
        if (Director == Item && Found_count < Display) // change User_input_data to userinput and
                                                    // From_node_data to current node data 
        {
            DataFound = "DataExist";
            if (GiveNumber == 1)
            {
                Count = Index;
            }

            for (int i = 0; i < Current->GetActorTotal(); i++)
            {
                JoinActors = JoinActors + Current->GetActor()[i] + " ";
            }

            cout << GiveNumber++ << ": ";
            cout << Current->GetName() << " " + Current->GetDirector() << " " + Current->GetYear() + " ";
            cout << Current->GetActorTotal() << " " + JoinActors << Current->GetCheck();
            cout << " " + Current->GetUser_id() << " " + Current->GetDate() << endl;
            JoinActors = "";
            Current = Current->GetNext();
            Found_count++;
            if (Display == Found_count)
            {
                string Option;
                cout << "Would you like to look more yes or no: ";
                cin >> Option;
                if (To_lower_case(Option) == "yes")
                {
                    Display = Display * 2;
                }
                else
                {
                    cout << "Thank you for looking DB in here" << endl;
                }
            }
        }
        else {
            Current->GetDirector();
            Current = Current->GetNext();

        }
    }
    Found_count = 0;
    Count = 0;
}


/*
    prefix search of movie year

*/
void NodeAdditionalFunction::SearchYear(string Item)
{
    VideoStoreNode* Current = Head;
    Found_count = 0;
    Display = 4;
    GiveNumber = 1;
    while (Current != NULL)
    {
        Count++;
        Year = To_lower_case(Current->GetYear().substr(0, Item.length()));
        Item = To_lower_case(Item.substr(0, Item.length()));
        if (Year == Item && Found_count < Display) // change User_input_data to userinput and
                                                    // From_node_data to current node data 
        {
            DataFound = "DataExist";
            if (GiveNumber == 1)
            {
                Count =  Index;
            }
            for (int i = 0; i < Current->GetActorTotal(); i++)
            {
                JoinActors = JoinActors + Current->GetActor()[i] + " ";
            }

            cout << GiveNumber++ << ": ";
            cout << Current->GetName() << " " + Current->GetDirector() << " " + Current->GetYear() + " ";
            cout << Current->GetActorTotal() << " " + JoinActors << Current->GetCheck();
            cout << " " + Current->GetUser_id() << " " + Current->GetDate() << endl;
            JoinActors = "";
            Current = Current->GetNext();
            Found_count++;
            if (Display == Found_count)
            {
                string Option;
                cout << "Would you like to look more yes or no: ";
                cin >> Option;
                if (To_lower_case(Option) == "yes")
                {
                    Display = Display * 2;
                }
                else
                {
                    cout << "Thank you for looking DB in here" << endl;
                }
            }
        }
        else {
            Current->GetYear();
            Current = Current->GetNext();

        }
    }
    Found_count = 0;
    Count = 0;
}


/*
    prefix search of movie actors 

*/
void NodeAdditionalFunction::SearchActor(string Item)
{
    VideoStoreNode* Current = Head;
    Found_count = 0;
    Display = 4;
    GiveNumber = 1;
    while (Current != NULL)
    {
        Count++;
        for (int i = 0; i < Current->GetActorTotal(); i++)
        {
            Actor = To_lower_case(Current->GetActor()[i].substr(0, Item.length()));
            Item = To_lower_case(Item.substr(0, Item.length()));
            if (Actor == Item && Found_count < Display) // change User_input_data to userinput and
                                                        // From_node_data to current node data 
            {
                DataFound = "DataExist";
                DataFoundInActor = "DataExist";
                if (GiveNumber == 1)
                {
                    Count = Index;
                }
                for (int i = 0; i < Current->GetActorTotal(); i++)
                {
                    JoinActors = JoinActors + Current->GetActor()[i] + " ";
                }

                cout << GiveNumber++ << ": ";
                cout << Current->GetName() << " " + Current->GetDirector() << " " + Current->GetYear() + " ";
                cout << Current->GetActorTotal() << " " + JoinActors << Current->GetCheck();
                cout << " " + Current->GetUser_id() << " " + Current->GetDate() << endl;
                JoinActors = "";
                Found_count++;
                if (Display == Found_count)
                {
                    string Option;
                    cout << "Would you like to look more yes or no: ";
                    cin >> Option;
                    if (To_lower_case(Option) == "yes")
                    {
                        Display = Display * 2;
                    }
                    else
                    {
                        cout << "Thank you for looking DB in here" << endl;
                        break;
                    }
                }

            }
            
        }
        if (DataFoundInActor == "DataExist")
        {
            Current = Current->GetNext();
            DataFound = "";
        }
        else {
            Current->GetActor();
            Current = Current->GetNext();

        }
    }
    Found_count = 0;
    Count = 0;
}


/*
  covert the letter to lower case
*/
string NodeAdditionalFunction::To_lower_case(string Data)
{
    for (int i = 0; Data[i] != '\0'; i++)
    {
        if (Data[i] >= 'A' && Data[i] <= 'Z')
            Data[i] = Data[i] + 32;
    }
    return Data;
}

