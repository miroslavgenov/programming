#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/algorithms/greedyAlgorithms/activity/activity.h"
#include "/home/home/Desktop/programming/c++/algorithms/greedyAlgorithms/activity/ActivityMaker.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"

using namespace std;

int main(){
    vector<activity*> listWithActivities = {
        new activity{1,3},
        new activity{1,2},
        new activity{2,3},
        new activity{4,5},
        new activity{3,4},
        new activity{1,4},
        new activity{5,7},
        new activity{6,8}
    };

    ActivityMaker* am = new ActivityMaker(listWithActivities);
    am->makeActivityHistory();
    Printer::printActivities(am->getActivityHistory());
}