package com.miroslav.quizator;

import android.widget.TextView;

import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;

public class TextViewInitializer extends QuizatorMainFragmentInitializer{
    public TextViewInitializer(FragmentQuizatorMainBinding binding) {
        super(binding);
    }

    public TextView initTextViewQuestionNumber(){
        return super.binding.textViewQuestionNumber;
    }

}
















































