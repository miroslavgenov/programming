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

    public void setFragmentQuizatorMainBinding(FragmentQuizatorMainBinding fragmentQuizatorMainBinding) {
        this.fragmentQuizatorMainBinding = fragmentQuizatorMainBinding;
    }

    public void setQuestion(Question question) {
        this.question = question;
    }

    public Question getQuestion() {
        return question;
    }



    public AlphaAnimationHelper(View targetViewToStartAnimation , int fromAlpha,int toAlpha , int animationDuration){
        AlphaAnimation alphaAnimation = new AlphaAnimation(fromAlpha,toAlpha);
        alphaAnimation.setDuration(animationDuration);
        targetViewToStartAnimation.startAnimation(alphaAnimation);
    }

    public AlphaAnimationHelper(LinearLayout layoutQuestionRoot, LinearLayout layoutAnswersRoot,
                                FragmentQuizatorMainBinding fragmentQuizatorMainBinding){
        this.layoutQuestionRoot = layoutQuestionRoot;
        this.layoutAnswersRoot = layoutAnswersRoot;
        this.fragmentQuizatorMainBinding  = fragmentQuizatorMainBinding;

        fadeInForQuestionAndAnswersRootLayout = new AlphaAnimation(1,0);
        fadeInForQuestionAndAnswersRootLayout.setDuration(ANIMATION_DURATION);

        fadeOutForQuestionAndAnswersRootLayout = new AlphaAnimation(0,1);
        fadeOutForQuestionAndAnswersRootLayout.setDuration(ANIMATION_DURATION/2);


        fadeInForQuestionAndAnswersRootLayout.setAnimationListener(new Animation.AnimationListener() {
            @Override
            public void onAnimationStart(Animation animation) {

            }

            @Override
            public void onAnimationEnd(Animation animation) {
                fragmentQuizatorMainBinding.setQuestion(getQuestion());
                layoutQuestionRoot.startAnimation(fadeOutForQuestionAndAnswersRootLayout);
                layoutAnswersRoot.startAnimation(fadeOutForQuestionAndAnswersRootLayout);
            }

            @Override
            public void onAnimationRepeat(Animation animation) {

            }
        });

    }
    public void startAnimation(){
        layoutQuestionRoot.startAnimation(fadeInForQuestionAndAnswersRootLayout);
        layoutAnswersRoot.startAnimation(fadeInForQuestionAndAnswersRootLayout);
    }


}
















































