package com.miroslav.simpleGymMemberManage;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import com.miroslav.simpleGymMemberManage.fragments.MyButtonEventLogicInterface;

public class LogInActivity extends AppCompatActivity implements MyButtonEventLogicInterface {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_log_in);
    }

    @Override
    public void doThisFromFragment() {

    }
}




















































