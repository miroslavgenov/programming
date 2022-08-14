package com.miroslav.simpleGymMemberManage;

import android.content.Context;
import android.view.Gravity;
import android.widget.Toast;


public class MyToast {
    Toast toast;
    int gravity;
    int duration;
    Context appContext;
    String message;


    public MyToast(Context appContext,String message){
        setAppContext(appContext);
        setMessage(message);
        setDuration(Toast.LENGTH_LONG);
        setGravity(Gravity.CENTER);

        initToast(getDuration());
    }

    public void setAppContext(Context appContext) {
        this.appContext = appContext;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public void setDuration(int duration) {
        this.duration = duration;
    }

    public void setGravity(int gravity) {
        this.gravity = gravity;
    }

    public void initToast(int duration) {
        //TODO

        this.setToast(Toast.makeText(getAppContext(),getMessage(),duration));
        this.getToast().setGravity(this.getGravity(),0,0);
    }
    public void show(){
        this.getToast().show();
    }

    public void setToast(Toast toast) {
        this.toast = toast;
    }

    public Toast getToast() {
        return toast;
    }

    public Context getAppContext() {
        return appContext;
    }



    public String getMessage() {
        return message;
    }





    public int getGravity() {
        return gravity;
    }



    public int getDuration() {
        return duration;
    }

    //TODO ...
    // make constructor and reduce the abstraction of the method makeToastSetMessageSetGravityCenterAndShowLong
//    public static void makeToastSetMessageSetGravityCenterAndShowLong(Context appContext,String message){
//        Toast toast;
//        toast= Toast.makeText(appContext,message,Toast.LENGTH_LONG);
//        toast.setGravity(Gravity.CENTER,0,0);
//        toast.show();
//    }
}













































