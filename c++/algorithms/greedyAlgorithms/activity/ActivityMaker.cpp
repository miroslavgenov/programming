#include "/home/home/Desktop/programming/c++/algorithms/greedyAlgorithms/activity/ActivityMaker.h"

ActivityMaker::ActivityMaker(std::vector<activity*> _listWithActivities){
    this->listWithActivities = _listWithActivities;
}

int ActivityMaker::getTheIndexOfTheMinimumActivityStartAndEnd(){
    int index = -1;
    int minStart,minEnd;

    if(listWithActivities.empty() == false){
        minStart = listWithActivities[0]->startAt;
        minEnd = listWithActivities[0]->endAt;
        for(int i=0;i<listWithActivities.size();i++){
            if(minStart>=listWithActivities[i]->startAt && minEnd>=listWithActivities[i]->endAt){
                index = i;
            }
        }
    }

    return index;
}

bool ActivityMaker::isThereACollision(activity* m){
    for(int i=0;i<activityHistory.size();i++){
        if(activityHistory[i]->startAt == m->startAt){
            return true;
        }
    }

    return false;
}


void ActivityMaker::addActivityToHistory(int index){
    activityHistory.push_back(new activity{
        listWithActivities[index]->startAt,
        listWithActivities[index]->endAt
    });
}

void ActivityMaker::makeActivityHistory(){
    int index;

    while(listWithActivities.empty()==false){
        index = getTheIndexOfTheMinimumActivityStartAndEnd();

        if(isThereACollision(listWithActivities[index]) ==false){
            addActivityToHistory(index);
        }

        listWithActivities.erase(listWithActivities.begin()+index);
    }
}

std::vector<activity*> ActivityMaker::getActivityHistory(){
    return activityHistory;
}