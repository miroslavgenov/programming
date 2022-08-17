package com.miroslav.quizator;

import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.view.animation.AnimationSet;
import android.view.animation.ScaleAnimation;

public class QuestionNumberAnimationHelper {
//    ScaleAnimation scaleAnimation = new ScaleAnimation(scaleAnimationFromX,scaleAnimationToX,scaleAnimationFromY,scaleAnimationToY);
//    scaleAnimation.setDuration(400);

    AlphaAnimation alphaAnimation = new AlphaAnimation(1,0);
//    alphaAnimation.setDuration(100);

    AnimationSet animationSet = new AnimationSet(true);
//        animationSet.setStartOffset(450);
//        animationSet.addAnimation(scaleAnimation);
//        animationSet.addAnimation(alphaAnimation);

//        scaleAnimation.setAnimationListener(new Animation.AnimationListener() {
//        @Override
//        public void onAnimationStart(Animation animation) {
//
//        }
//
//        @Override
//        public void onAnimationEnd(Animation animation) {
//
//            textViewQuestionNumber.startAnimation(scaleAnimation1);
//
//            textViewQuestionNumber.setText(String.valueOf(quiz.getQuestionNumber()));
//        }
//
//        @Override
//        public void onAnimationRepeat(Animation animation) {
//
//        }
//    });
}
