package com.miroslav.simpleGymMemberMenage;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;

import com.miroslav.simpleGymMemberMenage.databinding.ActivityMainMenuBinding;

public class MainMenuActivity extends AppCompatActivity implements MyActivityBindingInterface{
    ActivityMainMenuBinding activityMainMenuBinding;

    ImageButton imageButtonSearch;
    EditText editTextSearch;
    Button buttonAddClient;
    Button buttonAddCard;
    Button buttonActiveClient;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        main();
    }

    private void main() {
        setActivityBinding(DataBindingUtil.setContentView(this,R.layout.activity_main_menu));

    }



    //    SET
    @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {
        this.activityMainMenuBinding = (ActivityMainMenuBinding) DataBindingUtilContent;
    }
    //    GET
    ActivityMainMenuBinding getActivityMainMenuBinding(){
        return this.activityMainMenuBinding;
    }
}

















































