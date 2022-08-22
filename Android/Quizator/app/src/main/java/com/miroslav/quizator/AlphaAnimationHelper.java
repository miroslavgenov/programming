package com.miroslav.quizator;

import android.view.View;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.miroslav.quizator.actor.Question;
import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;

public class AlphaAnimationHelper {
    LinearLayout layoutQuestionRoot;
    LinearLayout layoutAnswersRoot;
    AlphaAnimation fadeInForQuestionAndAnswersRootLayout;
    AlphaAnimation fadeOutForQuestionAndAnswersRootLayout;
    FragmentQuizatorMainBinding fragmentQuizatorMainBinding;
    Question question;
    final int ANIMATION_DURATION = 1000;

    

    public AlphaAnimationHelper(View targetViewToStartAnimation, int fromAlpha, int toAlpha, int animationDuration) {
        targetViewToStartAnimation.startAnimation(createAlphaAnimation(fromAlpha,toAlpha,animationDuration));
    }

    public AlphaAnimationHelper(View layoutQuestionRoot, View layoutAnswersRoot,
            FragmentQuizatorMainBinding fragmentQuizatorMainBinding ) {
        this.layoutQuestionRoot = (LinearLayout) layoutQuestionRoot;
        this.layoutAnswersRoot = (LinearLayout) layoutAnswersRoot;
        this.fragmentQuizatorMainBinding = fragmentQuizatorMainBinding;
        fadeInForQuestionAndAnswersRootLayout = createAlphaAnimation(1,0,ANIMATION_DURATION);
        fadeOutForQuestionAndAnswersRootLayout = createAlphaAnimation(0,1,ANIMATION_DURATION/2);
    }

    public static AlphaAnimation createAlphaAnimation(int fromAlpha, int toAlpha, int animationDuration) {
        AlphaAnimation alphaAnimation = new AlphaAnimation(fromAlpha,toAlpha);
        alphaAnimation.setDuration(animationDuration);
        return alphaAnimation;
    }

    public void setFragmentQuizatorMainBinding(FragmentQuizatorMainBinding fragmentQuizatorMainBinding) {
        this.fragmentQuizatorMainBinding = fragmentQuizatorMainBinding;
    }

    public void setQuestionForAnimation(Question question) {
        this.question = question;
    }

    public Question getQuestion() {
        return question;
    }

     public void startAnimation() {
        layoutQuestionRoot.startAnimation(fadeInForQuestionAndAnswersRootLayout);
        layoutAnswersRoot.startAnimation(fadeInForQuestionAndAnswersRootLayout);

    }

}




























































