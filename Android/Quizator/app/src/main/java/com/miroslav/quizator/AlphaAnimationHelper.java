package com.miroslav.quizator;

import android.view.View;
import android.view.animation.AlphaAnimation;

public class AlphaAnimationHelper {
	// TODO remove this constructur and replace it with static
    public AlphaAnimationHelper(View targetViewToStartAnimation, int fromAlpha, int toAlpha, int animationDuration) {
        targetViewToStartAnimation.startAnimation(createAlphaAnimation(fromAlpha, toAlpha, animationDuration));
    }

    public static AlphaAnimation createAlphaAnimation(int fromAlpha, int toAlpha, int animationDuration) {
        AlphaAnimation alphaAnimation = new AlphaAnimation(fromAlpha, toAlpha);
        alphaAnimation.setDuration(animationDuration);
        return alphaAnimation;
    }

}




























































