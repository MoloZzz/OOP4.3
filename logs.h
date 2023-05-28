//
// Created by megao on 27.05.2023.
//

#ifndef OOP4_3_LOGS_H
#define OOP4_3_LOGS_H

#include <fstream>
#include <time.h>

using namespace std;

void log(string massage, string file){
    ofstream logsFile;

    logsFile.open(file,ios_base::app);

    if(!logsFile.is_open()){
        cout << "error with logs" <<endl;
    }

    logsFile << massage << endl;

    logsFile.close();

}


#endif //OOP4_3_LOGS_H
