#pragma once

class ActivityMaker{
    public:
    std::vector<activity*> listWithActivities;
    std::vector<activity*> activityHistory;

    int getTheIndexOfTheMinimumActivityStartAndEnd();

    bool isThereACollision(activity* );

    ActivityMaker(std::vector<activity*> );

    void addActivityToHistory(int );

    void makeActivityHistory();

    std::vector<activity*> getActivityHistory();

};