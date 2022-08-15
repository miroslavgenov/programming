package com.miroslav.quizator;

import android.graphics.drawable.AnimationDrawable;
import android.graphics.drawable.Drawable;

/**
 * For now this class is used only to animate MainActivity layout background gradient animation
 */

public class AnimationDrawableHelper {
    AnimationDrawable animationDrawable;
    int enterFadeDuration=10;
    int exitFadeDuration=5000;
    public AnimationDrawableHelper(Drawable background){
        animationDrawable = (AnimationDrawable) background;
        animationDrawable.setEnterFadeDuration(enterFadeDuration);
        animationDrawable.setExitFadeDuration(exitFadeDuration);
        animationDrawable.start();
    }


}






























