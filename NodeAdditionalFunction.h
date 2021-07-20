#ifndef NODEADDITIONALFUNCTION
#define NODEADDITIONALFUNCTION
#include "VideoStore.h"
#include "NodeAdditionalFunction.h"
#include "VideoStoreNode.h"
#include <string>

class NodeAdditionalFunction
{

private:
	string Name;
	string Director;
	string Year;
	string Actor;

	string JoinActors;
	string DataFoundInActor;

	int Index;
	int Count;
	int GiveNumber;
	int Found_count;
	int Display;
	bool Stop;
	int Position;

	
public:
	string DataFound;
	VideoStoreNode *Head;



	void SearchName(string Item);
	void SearchDirector(string Item);
	void SearchYear(string Item);
	void SearchActor(string Item);
	void Add(string Name, string Director, string Year, int ActorCout, string *Actors, string Check, string User_id, string Date);

	void Updata_data(int Selected_number, string CheckMark, string User_id, string Date);
	string To_lower_case(string Data);
};
#endif

