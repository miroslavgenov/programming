package com.miroslav.simpleGymMemberManage;

public interface MyActivityBindingInterface {
    <T> void setActivityBinding(T DataBindingUtilContent);
    <T> T getDataBindingUtilContentViewForThisActivity();
}
