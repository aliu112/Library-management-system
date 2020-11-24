#include "owedDebts.h"
#include <fstream>
#include <stdio.h>

OwedDebts::OwedDebts(){
    amount=0;
}
void OwedDebts::addPayment(int num){
    int flag=0;
    int counter =1;
    int numInList=0;

    ifstream x;
    x.open("NumInList.txt");
    x >> numInList;
    x.close();
    int tempDebt =0;

    ifstream debtFile;
    debtFile.open("debtsList.txt");

    ofstream debtFile2;
    debtFile2.open("debtsListTemp.txt",std::ofstream::app);
    

    while(!debtFile.eof())
    {
        debtFile >> tempDebt;
        if(counter == numInList)
        {
            debtFile2 << num << '\n';
        }
        else 
        {
            debtFile2 << tempDebt << '\n';
        }
        ++counter;
        
    }
    debtFile2.close();
    debtFile.close();

    
    remove( "debtsList.txt" );

    char debtOldName[] ="debtsListTemp.txt";
    char debtNewName[] ="debtsList.txt";

    rename(debtOldName,debtNewName);

}
void OwedDebts::removePayment(){

}

int OwedDebts::GetAmountOwed(){
    int numInList=0;
    ifstream x;
    x.open("NumInList.txt");
    x >> numInList;
    x.close();

    ifstream debtFile;
    debtFile.open("debtsList.txt");
    int returnTemp=0;
    for(int i=0; i< numInList; i++)
    {
        debtFile >> returnTemp;
    }
    debtFile.close();
    return returnTemp;
}
