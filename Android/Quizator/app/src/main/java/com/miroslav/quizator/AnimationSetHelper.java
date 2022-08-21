package com.miroslav.quizator;

import android.view.animation.Animation;
import android.view.animation.AnimationSet;

public class AnimationSetHelper {

    public static AnimationSet createAnimationSet(boolean shareInterpolator,int startOfOffset,Animation[] animationsToBeAdded){
        AnimationSet animationSet = new AnimationSet(shareInterpolator);
        animationSet.setStartOffset(startOfOffset);
        for(Animation animation:animationsToBeAdded){
            animationSet.addAnimation(animation);
        }
        return animationSet;

    }
}







































