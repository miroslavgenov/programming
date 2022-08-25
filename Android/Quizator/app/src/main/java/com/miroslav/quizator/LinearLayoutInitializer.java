package com.miroslav.quizator;

import android.widget.LinearLayout;

import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;

public class LinearLayoutInitializer extends QuizatorMainFragmentInitializer{

    public LinearLayoutInitializer(FragmentQuizatorMainBinding binding) {
        super(binding);
    }
    public LinearLayout initLinearLayoutAnswersRoot(){
        return super.binding.layoutAnswersRoot;
    }
    public LinearLayout initLinearLayoutQuestionsRoot(){
        return super.binding.layoutQuestionRoot;
    }
}






























