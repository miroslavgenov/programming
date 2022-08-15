package com.miroslav.quizator;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;
import androidx.databinding.ViewDataBinding;

import android.graphics.drawable.AnimationDrawable;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;

import com.miroslav.quizator.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity implements Binding {

    private static final int LAYOUT_MAIN_ACTIVITY_ID = R.layout.activity_main;
//    private ViewDataBinding activityMainBinding;
        ActivityMainBinding activityMainBinding;
        ActivityMainBinding dataBindingUtilContent;
        AnimationDrawableHelper animationDrawableHelper;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        initActivityDataBindingUtilContent();
        setBinding();
        getWindow().getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_FULLSCREEN);


        animationDrawableHelper = new AnimationDrawableHelper(activityMainBinding.rootLayout.getBackground());


        //        LinearLayout layout = activityMainBinding.rootLayout;
//        AnimationDrawable animationDrawable = (AnimationDrawable) layout.getBackground();
//        animationDrawable.setEnterFadeDuration(10);
//        animationDrawable.setExitFadeDuration(5000);
//        animationDrawable.start();




    }


    @Override
    public void initActivityDataBindingUtilContent() {
        this.dataBindingUtilContent = DataBindingUtil.setContentView(this , LAYOUT_MAIN_ACTIVITY_ID);
    }

    @Override
    public void initFragmentDataBindingUtilContent(LayoutInflater inflater, ViewGroup container) {

    }

    @Override
    public void setBinding() {
        this.activityMainBinding = this.dataBindingUtilContent;
    }

    @Override
    public <T> T getBinding() {
        return (T)activityMainBinding;
    }
}




































