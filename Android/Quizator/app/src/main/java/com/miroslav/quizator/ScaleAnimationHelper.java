package com.miroslav.quizator;

import android.view.animation.ScaleAnimation;

public class ScaleAnimationHelper {

    public static ScaleAnimation createAnimation(float fromScaleX, float toScaleX, float fromScaleY, float toScaleY, int animationDuration){
        ScaleAnimation scaleAnimation = new ScaleAnimation(fromScaleX,toScaleX,fromScaleY,toScaleY);
        scaleAnimation.setDuration(animationDuration);
        return scaleAnimation;
    }
}































