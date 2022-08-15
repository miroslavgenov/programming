package com.miroslav.sceneandtransition;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.transition.ChangeBounds;
import android.transition.Explode;
import android.transition.Fade;
import android.transition.Scene;
import android.transition.Slide;
import android.transition.Transition;
import android.transition.TransitionManager;
import android.transition.TransitionSet;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;

public class MainActivity extends AppCompatActivity {

    private Scene scene1;
    private Scene scene2;
    private Scene scene3;
    private Scene scene4;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        scene1 =Scene.getSceneForLayout((ViewGroup) findViewById(R.id.rootLayout),R.layout.scene_1,this);
        scene2 =Scene.getSceneForLayout((ViewGroup) findViewById(R.id.rootLayout),R.layout.scene_2,this);
        scene3 =Scene.getSceneForLayout((ViewGroup) findViewById(R.id.rootLayout),R.layout.scene_3,this);
        scene4 =Scene.getSceneForLayout((ViewGroup) findViewById(R.id.rootLayout),R.layout.scene_4,this);
        scene1.enter();
    }

    public void onClick1(View view) {
        Transition slide= new Slide(Gravity.END);
        TransitionManager.go(scene2,slide);

    }
    public void onClick2(View view){
        Transition explode = new Explode();
        TransitionManager.go(scene3,explode);
    }
    public void onClick3(View view){
        Transition fade = new Fade(Fade.IN);
        TransitionManager.go(scene4,fade);
    }



    public void onClick4(View view) {
//        Transition changeBounds = new ChangeBounds();
//        TransitionManager.go(scene1,changeBounds);
        Transition slide = new Slide();
        Transition fade = new Fade();
        TransitionSet transitionSet = new TransitionSet();
        transitionSet.addTransition(fade).addTransition(slide);
        TransitionManager.go(scene1,transitionSet);
    }
}



























































