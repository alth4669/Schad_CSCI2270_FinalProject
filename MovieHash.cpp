#include "MovieHash.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <vector>

MovieHash::MovieHash()
{
    //ctor
    for(int x=0;x<5;x++){
        hashTable[x]=NULL;
    }
}

MovieHash::~MovieHash()
{
    //dtor
}

void MovieHash::insertMovie(std::string title, int startTime, int endTime, int index){
    HashElem *tmp=new HashElem;
    HashElem *node=new HashElem;
    node->title=title;
    node->startTime=startTime;
    node->endTime=endTime;
    node->next=NULL;
    node->previous=NULL;
    if(hashTable[index]==NULL){
        hashTable[index]=node;
    }
    else{
        tmp=hashTable[index];
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=node;
        node->previous=tmp;
        node->next=NULL;
    }
}

void MovieHash::printTableContents(){
    int i;
    HashElem *tmp=new HashElem;
    for(int x=0; x<5;x++){
        if(hashTable[x]!=NULL){
            tmp=hashTable[x];
            while(tmp!=NULL){
                cout<<tmp->title<<": "<<tmp->startTime<<" to "<<tmp->endTime<<endl;
                tmp=tmp->next;
            }
        }
    }
}

void MovieHash::findMovie(std::string name){
    int i;
    bool found=false;
    HashElem *tmp=new HashElem;
    for(int x=0; x<5;x++){
        if(hashTable[x]!=NULL){
            tmp=hashTable[x];
            while(tmp!=NULL){
                if(tmp->title==name){
                    cout<<name<<": from "<<tmp->startTime<<" to "<<tmp->endTime<<endl;
                    tmp=tmp->next;
                    found=true;
                }
                else{
                    tmp=tmp->next;
                }
            }
        }
    }
    if(found==false){
       cout<<"Movie not found."<<endl;
    }
}

void MovieHash::doubleFeature(std::string input1, std::string input2){
    int i;
    int z=0;
    int j=0;
    bool found1=false;
    bool found2=false;
    HashElem *tmp=new HashElem;
    for(int x=0; x<5;x++){
        if(hashTable[x]!=NULL){
            tmp=hashTable[x];
            while(tmp!=NULL){
                if(tmp->title==input1){
                    bool SoE=true;
                    addTime(z,tmp->startTime,tmp->endTime,SoE);
                    tmp=tmp->next;
                    z=z+2;
                    if(z==8){
                        z=0;
                    }
                    found1=true;
                }
                else if(tmp->title==input2){
                    bool SoE=false;
                    addTime(j,tmp->startTime,tmp->endTime,SoE);
                    tmp=tmp->next;
                    j=j+2;
                    if(j==8){
                        j=0;
                    }
                    found2=true;
                }
                else{
                    tmp=tmp->next;
                }
            }
        }
    }
    if(found1==false and found2==false){
       cout<<"1 or more movies not found."<<endl;
    }
    else{
        for(int a=0;a<5;a=a+2){
            bool compare=timeCompare(movieOne[a],movieOne[a+1],movieTwo[a],movieTwo[a+1]);
            if(compare==true){
                if(movieTwo[a]<movieOne[a]){
                    cout<<input1<<" from "<<movieTwo[a]<<"-"<<movieTwo[a+1]<<", and "<<input2<<" from "<<movieOne[a]<<"-"<<movieOne[a+1]<<endl;
                }
                else{
                    cout<<input1<<" from "<<movieOne[a]<<"-"<<movieOne[a+1]<<", and "<<input2<<" from "<<movieTwo[a]<<"-"<<movieTwo[a+1]<<endl;
                }
        }
      }
    }

}

bool MovieHash::timeCompare(int compareOne, int compareTwo, int compareThree, int compareFour){
    if(compareOne>compareThree and compareOne<compareFour){
        return false;
    }
    else if(compareTwo>compareThree and compareTwo<compareFour){
        return false;
    }
    else if(compareThree>compareOne and compareThree<compareTwo){
        return false;
    }
    else if(compareFour>compareOne and compareFour<compareTwo){
        return false;
    }
    else{
        return true;
    }
}

void MovieHash::addTime(int z, int startTime, int endTime, bool SoE){
    if(SoE==true){
        movieTwo[z]=startTime;
        z++;
        movieTwo[z]=endTime;
    }
    else if(SoE==false){
        movieOne[z]=startTime;
        z++;
        movieOne[z]=endTime;
    }
}

void MovieHash::randomMovie(){
    int randomFilm = rand() % 5 + 0;
    int randomTime = rand() % 3 + 1;
    if(randomTime==1){
        cout<<"See "<<hashTable[randomFilm]->title<<" at "<<hashTable[randomFilm]->startTime<<endl;
    }
    else if(randomTime==2){
        cout<<"See "<<hashTable[randomFilm]->title<<" at "<<hashTable[randomFilm]->next->startTime<<endl;
    }
    else if(randomTime==3){
        cout<<"See "<<hashTable[randomFilm]->title<<" at "<<hashTable[randomFilm]->next->next->startTime<<endl;
    }
}

void MovieHash::randomDouble(){
    int random2=rand() % 5 + 0;
    int random1=rand() % 5 + 0;
    while(random1==random2){
        random1=rand() % 5 + 0;
    }
    randomDoubleFeature(hashTable[random1]->title,hashTable[random2]->title);
}

void MovieHash::randomDoubleFeature(std::string input1, std::string input2){
    int i;
    int z=0;
    int j=0;
    bool firstPick=false;
    bool found1=false;
    bool found2=false;
    HashElem *tmp=new HashElem;
    for(int x=0; x<5;x++){
        if(hashTable[x]!=NULL){
            tmp=hashTable[x];
            while(tmp!=NULL){
                if(tmp->title==input1){
                    bool SoE=true;
                    addTime(z,tmp->startTime,tmp->endTime,SoE);
                    tmp=tmp->next;
                    z=z+2;
                    if(z==8){
                        z=0;
                    }
                    found1=true;
                }
                else if(tmp->title==input2){
                    bool SoE=false;
                    addTime(j,tmp->startTime,tmp->endTime,SoE);
                    tmp=tmp->next;
                    j=j+2;
                    if(j==8){
                        j=0;
                    }
                    found2=true;
                }
                else{
                    tmp=tmp->next;
                }
            }
        }
    }
        for(int a=0;a<5;a=a+2){
            bool compare=timeCompare(movieOne[a],movieOne[a+1],movieTwo[a],movieTwo[a+1]);
            if(compare==true){
                if(firstPick==false){
                    if(movieTwo[a]<movieOne[a]){
                        cout<<input1<<" from "<<movieTwo[a]<<"-"<<movieTwo[a+1]<<", and "<<input2<<" from "<<movieOne[a]<<"-"<<movieOne[a+1]<<endl;
                        firstPick=true;
                    }
                    else{
                        cout<<input1<<" from "<<movieOne[a]<<"-"<<movieOne[a+1]<<", and "<<input2<<" from "<<movieTwo[a]<<"-"<<movieTwo[a+1]<<endl;
                        firstPick=true;
                    }
                }
        }
      }
}



void MovieHash::atThisTime(int time){
    int i;
    HashElem *tmp=new HashElem;
    for(int x=0; x<5;x++){
        if(hashTable[x]!=NULL){
            tmp=hashTable[x];
            while(tmp!=NULL){
                if(tmp->startTime==time){
                    cout<<tmp->title<<": from "<<tmp->startTime<<" to "<<tmp->endTime<<endl;
                }
                tmp=tmp->next;
            }
        }
    }
}

void MovieHash::enterConflict(string desc, int startTime, int endTime)
{
    conflict newConflict = conflict(desc, startTime, endTime);
    conflictList.push_back(newConflict);
}

void MovieHash::listConflicts()
{
    cout << "======Current Conflicts======" << endl;
    if (conflictList.size() == 0)
    {
        cout << "You currently have no conflicts listed." << endl;
    }
    else
    {
        for (int i=0; i<conflictList.size(); i++)
        {
            cout << "Starting time: " << conflictList[i].startTime << endl;
            cout << "Ending time: " << conflictList[i].endTime << endl;
            cout << "Description: " << conflictList[i].description << endl;
            cout << endl;
        }
    }
}

bool MovieHash::conflictCheck(HashElem* movie)
{
    for (int i=0; i<conflictList.size(); i++)
    {
        if (movie->startTime >= conflictList[i].startTime || movie->startTime <= conflictList[i].endTime)
        {
            return false;
        }
        else if (movie->endTime >= conflictList[i].startTime || movie->startTime <= conflictList[i].endTime)
        {
            return false;
        }
    }
    return true;
}
