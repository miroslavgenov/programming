package com.miroslav.quizator.initializer;

import android.widget.TextView;

import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;
import com.miroslav.quizator.initializer.QuizatorMainFragmentInitializer;

public class TextViewInitializer extends QuizatorMainFragmentInitializer {
    public TextViewInitializer(FragmentQuizatorMainBinding binding) {
        super(binding);
    }

    public TextView getTextViewQuestionNumberFromBinding(){
        return super.binding.textViewQuestionNumber;
    }

}
















































