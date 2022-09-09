package com.miroslav.quizator;

import android.view.View;
import android.view.animation.AlphaAnimation;


public class AlphaAnimationHelper {
    public static  void makeAlphaAnimationAndStartTheAnimation(View targetViewToStartAnimation, int fromAlpha, int toAlpha, int animationDuration) {
        targetViewToStartAnimation.startAnimation(makeAlphaAnimation(fromAlpha, toAlpha, animationDuration));
    }

    static AlphaAnimation makeAlphaAnimation(int fromAlpha, int toAlpha, int animationDuration) {
        AlphaAnimation alphaAnimation = new AlphaAnimation(fromAlpha, toAlpha);
        alphaAnimation.setDuration(animationDuration);
        return alphaAnimation;
    }

}




























































