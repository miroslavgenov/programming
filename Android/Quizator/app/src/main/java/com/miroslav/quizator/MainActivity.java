package com.miroslav.quizator;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.graphics.drawable.AnimationDrawable;
import android.graphics.drawable.TransitionDrawable;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        getWindow().getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_FULLSCREEN);

        Button btn  = findViewById(R.id.button);
        ConstraintLayout constraintLayout = findViewById(R.id.root_layout);
        AnimationDrawable animationDrawable = (AnimationDrawable) constraintLayout.getBackground();
        animationDrawable.setEnterFadeDuration(10);
        animationDrawable.setExitFadeDuration(5000);
        animationDrawable.start();

        TransitionDrawable transitionDrawable = (TransitionDrawable) btn.getBackground();
        btn.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View view, MotionEvent motionEvent) {
                if(motionEvent.getAction()==MotionEvent.ACTION_DOWN){
                    transitionDrawable.startTransition(50);
                }else if(motionEvent.getAction()== MotionEvent.ACTION_UP){
                    transitionDrawable.reverseTransition(50);
                }
                return false;
            }
        });



    }
}




































