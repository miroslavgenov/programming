package com.miroslav.quizator;

import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.miroslav.quizator.actor.Question;
import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;
import com.miroslav.quizator.initializer.ImageButtonInitializer;
import com.miroslav.quizator.initializer.LinearLayoutInitializer;
import com.miroslav.quizator.initializer.TextViewInitializer;

public class QuizatorMainXMLHelper {
    ImageButton imageButtonToNextQuestion;
    ImageButtonInitializer imageButtonInitializer;
    LinearLayoutInitializer linearLayoutInitializer;
    TextViewInitializer textViewInitializer;
    LinearLayout layoutQuestionRoot;
    LinearLayout layoutAnswersRoot;
    TextView textViewQuestionNumber;
    FragmentQuizatorMainBinding binding;
    RadioGroupHelper radioGroupHelper;


    public QuizatorMainXMLHelper(FragmentQuizatorMainBinding binding) {
        this.binding=binding;
        imageButtonInitializer = new ImageButtonInitializer(binding);
        linearLayoutInitializer = new LinearLayoutInitializer(binding);
        textViewInitializer = new TextViewInitializer(binding);
    }
    public void initAllQuizatorMainXMLElements(){
        imageButtonToNextQuestion = imageButtonInitializer.initImageButtonToNextQuestion();
        layoutQuestionRoot = linearLayoutInitializer.initLinearLayoutQuestionsRoot();
        layoutAnswersRoot = linearLayoutInitializer.initLinearLayoutAnswersRoot();
        textViewQuestionNumber = textViewInitializer.initTextViewQuestionNumber();
        initRadioGroupHelper();
    }
    public void setQuestionToUI(Question question){
        binding.setQuestion(question);
    }
    public void setQuestionNumberToUI(int number){
        setTextViewQuestionNumberText(number);
    }

    public void initRadioGroupHelper() {
        this.radioGroupHelper = new RadioGroupHelper(binding.radioGroupAnswers);
    }

    public RadioGroupHelper getRadioGroupHelper() {
        return radioGroupHelper;
    }

    public void setTextViewQuestionNumberText(int questionNumber) {
        this.textViewQuestionNumber.setText(String.valueOf(questionNumber));
    }

    public void setBinding(FragmentQuizatorMainBinding binding) {
        this.binding = binding;
    }

    public FragmentQuizatorMainBinding getBinding() {
        return binding;
    }

    public ImageButton getImageButtonToNextQuestion() {
        return imageButtonToNextQuestion;
    }

    public LinearLayout getLayoutAnswersRoot() {
        return layoutAnswersRoot;
    }

    public LinearLayout getLayoutQuestionRoot() {
        return layoutQuestionRoot;
    }

    public TextView getTextViewQuestionNumber() {
        return textViewQuestionNumber;
    }
}


















































