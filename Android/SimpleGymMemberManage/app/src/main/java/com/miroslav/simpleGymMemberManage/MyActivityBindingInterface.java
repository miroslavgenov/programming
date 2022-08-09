package com.miroslav.simpleGymMemberManage;


//TODO change the name of MyActivityBindingInterface  to MyActivityBindingImp

public interface MyActivityBindingInterface {
    <T> void setActivityBinding(T DataBindingUtilContent);
    <T> T getDataBindingUtilContentViewForThisActivity();
}
