#include <iostream>
#include "VideoStore.h"
#include "NodeAdditionalFunction.h"
#include "VideoStoreNode.h"
/*
   command line to create a .exe file 
   g++ VideoStore.cpp NodeAdditionalFunction.cpp VideoStoreNode.cpp  project.cpp -o project.exe
*/

/*
  main function. it will call the VideoStore function run
  to execute the program.
*/
int main()
{
    VideoStore *Store = new VideoStore();
    Store->run();
    delete Store;
}
