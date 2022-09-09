package com.miroslav.quizator.initializer;

import android.widget.LinearLayout;

import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;

public class LinearLayoutInitializer extends QuizatorMainFragmentInitializer{

    public LinearLayoutInitializer(FragmentQuizatorMainBinding binding) {
        super(binding);
    }
    public LinearLayout getLinearLayoutAnswersRootFromBinding(){
        return super.binding.layoutAnswersRoot;
    }
    public LinearLayout getLinearLayoutQuestionsRootFromBinding(){
        return super.binding.layoutQuestionRoot;
    }
}






























