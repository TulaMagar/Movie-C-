#include <iostream>
#include <fstream>
#include "VideoStore.h"
#include "NodeAdditionalFunction.h"
#include "VideoStoreNode.h"
#include <string>

using namespace std;
/*
   command line to create a .exe file 
   g++ VideoStore.cpp NodeAdditionalFunction.cpp VideoStoreNode.cpp  project.cpp -o project.exe
*/


/*
   Add file data to the node.
*/
void VideoStore::run()
{
    cout << "Please, name a file to load and read the data: ";
    cin >> File_user_input;
    ifstream File(File_user_input.c_str());

    File >> File_size >> When;

    for (int Begin = 0; Begin < File_size; Begin++)
    {
        File >> Name >> Direction >> Year >> ActorCount;
        Actor = new string[ActorCount];
        for (int i = 0; i < ActorCount; i++)
        {
            File >> Actor[i];
        }
        File >> Check_in_and_out;

        if (Check_in_and_out == "in")
        {
            User_id = "";
            Date = "";
            Node.Add(Name, Direction, Year, ActorCount, Actor, Check_in_and_out, User_id, Date);
        }
        else if (Check_in_and_out == "out")
        {
            File >> User_id >> Date;
            Node.Add(Name, Direction, Year, ActorCount, Actor, Check_in_and_out, User_id, Date);
        }
    }
    File.close();

    VideoStore::User_interface();

}


/*
   user interface.
*/
void VideoStore::User_interface()
{

    while (true)
    {
        cout << "Please, choose a title: "
            "\n  1 - Search by name: "
            "\n  2 - Search by director: "
            "\n  3 - Search by year: "
            "\n  4 - Search by actor: "
            "\n  5 - Menu: "
            "\n  6 - Upload new file: "
            "\n  0 - exit: " << endl;

        cin >> User_input;
        if (User_input == 0)
        {
            break;
        }
        switch (User_input)
        {
        case 1:
        {
            Name = "";
            cout << "Enter a movie name: ";
            cin >> Name;
            if (Name == "5")
            {
                break;
            }
            else
            {
                Node.SearchName(Name);
                if (Node.DataFound == "DataExist")
                {
                    Node.DataFound = "";
                    cout << "\n" << "Would you like to check out or in: ";
                    cin >> Check_in_and_out;

                    if (Node.To_lower_case(Check_in_and_out) == "out")
                    {
                        cout << "Enter a display number from above movie list: ";
                        cin >> Select;

                        cout << "Enter a 4 digit user id: ";
                        cin >> User_id;

                        cout << "Enter a today date: ";
                        cin >> Date;
                        Node.Updata_data(Select, Check_in_and_out, User_id, Date);
                        cout << "\nThank you for checking out\n" << endl;
                    }
                    else if (Node.To_lower_case(Check_in_and_out) == "in")
                    {
                        User_id = "";
                        Date = "";
                        cout << "Enter a display number from above movie list: ";
                        cin >> Select;
                        Node.Updata_data(Select, Check_in_and_out, User_id, Date);
                        cout << "\nThank you for checking in\n" << endl;
                    }
                    else if (Check_in_and_out == "5")
                    {
                        break;
                    }
                    break;
                }
                else if (Node.DataFound == "")
                {
                    cout << "\nData not found\n" << endl;
                }
            }
            break;
        }
        case 2:
        {
            cout << "Enter a movie director name: ";
            cin >> Direction;
            if (Direction == "5")
            {
                break;
            }
            else
            {
                Node.SearchDirector(Direction);
                if (Node.DataFound == "DataExist")
                {
                    Node.DataFound = "";
                    cout << "\n" << "Would you like to check out or in: ";
                    cin >> Check_in_and_out;

                    if (Node.To_lower_case(Check_in_and_out) == "out")
                    {
                        cout << "Enter a display number from above movie list: ";
                        cin >> Select;

                        cout << "Enter a 4 digit user id: ";
                        cin >> User_id;

                        cout << "Enter a today date: ";
                        cin >> Date;
                        Node.Updata_data(Select, Check_in_and_out, User_id, Date);
                        cout << "\nThank you for checking out\n" << endl;
                    }
                    else if (Node.To_lower_case(Check_in_and_out) == "in")
                    {
                        User_id = "";
                        Date = "";
                        cout << "Enter a display number from above movie list: ";
                        cin >> Select;
                        Node.Updata_data(Select, Check_in_and_out, User_id, Date);
                        cout << "\nThank you for checking in\n" << endl;
                    }
                    else if (Check_in_and_out == "5")
                    {
                        break;
                    }
                    break;
                }
                else if (Node.DataFound == "")
                {
                    cout << "Data not found" << endl;
                }
            }
            break;
        }
        case 3:
        {
            cout << "Enter a year: ";
            cin >> Year;
            if(Year == "5")
            {
                break;
            }
            else
            {
                Node.SearchYear(Year);
                if (Node.DataFound == "DataExist")
                {
                    Node.DataFound = "";
                    cout << "\n" << "Would you like to check out or in: ";
                    cin >> Check_in_and_out;

                    if (Node.To_lower_case(Check_in_and_out) == "out")
                    {
                        cout << "Enter a display number from above movie list: ";
                        cin >> Select;

                        cout << "Enter a 4 digit user id: ";
                        cin >> User_id;

                        cout << "Enter a today date: ";
                        cin >> Date;
                        Node.Updata_data(Select, Check_in_and_out, User_id, Date);
                        cout << "\nThank you for checking out\n" << endl;
                    }
                    else if (Node.To_lower_case(Check_in_and_out) == "in")
                    {
                        User_id = "";
                        Date = "";
                        cout << "Enter a display number from above movie list: ";
                        cin >> Select;
                        Node.Updata_data(Select, Check_in_and_out, User_id, Date);
                        cout << "\nThank you for checking in\n" << endl;
                    }
                    else if (Check_in_and_out == "5")
                    {
                        break;
                    }
                    break;
                }
                else if (Node.DataFound == "")
                {
                    cout << "Data not found" << endl;
                }
            }

            break;
        }
        case 4:
        {
            cout << "Enter a movie actor name: ";
            cin >> UserInputActor;
            if (UserInputActor == "5")
            {
                break;
            }
            else
            {
                Node.SearchActor(UserInputActor);
            }

            cout << "\n" << "Would you like to check out or in: ";
            cin >> Check_in_and_out;

            if (Node.To_lower_case(Check_in_and_out) == "out")
            {
                cout << "Enter a display number from above movie list: ";
                cin >> Select;

                cout << "Enter a 4 digit user id: ";
                cin >> User_id;

                cout << "Enter a today date: ";
                cin >> Date;

                Node.Updata_data(Select, Check_in_and_out, User_id, Date);
                cout << "\nThank you for checking out\n" << endl;
            }
            else if (Node.To_lower_case(Check_in_and_out) == "in")
            {
                User_id = "";
                Date = "";
                cout << "Enter a display number from above movie list: ";
                cin >> Select;
                Node.Updata_data(Select, Check_in_and_out, User_id, Date);
                cout << "\nThank you for checking in\n" << endl;
            }
            else if (Check_in_and_out == "5")
            {
                break;
            }
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            run();
            cout << "Data have been merged \n";
            
        }
        }
    }

}

