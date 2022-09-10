package com.miroslav.quizator.initializer;

import android.widget.ImageButton;
import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;

public class ImageButtonInitializer extends QuizatorMainFragmentInitializer{
    public ImageButtonInitializer(FragmentQuizatorMainBinding binding) {
        super(binding);
    }

    public ImageButton getImageButtonToNextQuestionFromBinding(){
        return super.binding.imageButtonToNextQuestion;
    }

}


































