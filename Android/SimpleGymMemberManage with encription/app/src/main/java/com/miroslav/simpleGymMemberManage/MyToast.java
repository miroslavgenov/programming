package com.miroslav.simpleGymMemberManage;

import android.content.Context;
import android.view.Gravity;
import android.widget.Toast;

public class MyToast {

    public static void makeToastSetMessageSetGravityCenterAndShowLong(Context appContext,String message){
        Toast toast;
        toast= Toast.makeText(appContext,message,Toast.LENGTH_LONG);
        toast.setGravity(Gravity.CENTER,0,0);
        toast.show();

    }
}













































