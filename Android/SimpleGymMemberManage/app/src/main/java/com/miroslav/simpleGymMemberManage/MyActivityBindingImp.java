package com.miroslav.simpleGymMemberManage;




public interface MyActivityBindingImp {
    <T> void setActivityBinding(T DataBindingUtilContent);
    <T> T getDataBindingUtilContentViewForThisActivity();
}
