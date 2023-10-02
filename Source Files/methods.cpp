#include "../HeaderFiles/headers.h"


using namespace std;

void Journal::Print(Journal *journal){
    for(int i = 0; i < N; i++){
        cout<< journal[i].name << "\t " << journal[i].year << "\t "<< journal[i].circulation << endl;
    }
}
