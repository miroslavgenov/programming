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
    LinearLayout layoutQuestionRoot;
    LinearLayout layoutAnswersRoot;
    TextViewInitializer textViewInitializer;
    TextView textViewQuestionNumber;
    FragmentQuizatorMainBinding binding;
    RadioGroupHelper radioGroupHelper;


    public QuizatorMainXMLHelper(FragmentQuizatorMainBinding binding) {
        this.binding=binding;
        initializeInitializers();
    }
    void initializeInitializers(){
        imageButtonInitializer = new ImageButtonInitializer(binding);
        linearLayoutInitializer = new LinearLayoutInitializer(binding);
        textViewInitializer = new TextViewInitializer(binding);
    }

    public void initAllQuizatorMainXMLElements(){
        imageButtonToNextQuestion = imageButtonInitializer.getImageButtonToNextQuestionFromBinding();
        layoutQuestionRoot = linearLayoutInitializer.getLinearLayoutQuestionsRootFromBinding();
        layoutAnswersRoot = linearLayoutInitializer.getLinearLayoutAnswersRootFromBinding();
        textViewQuestionNumber = textViewInitializer.getTextViewQuestionNumberFromBinding();
        initRadioGroupHelper();
    }

    void initRadioGroupHelper() {
        this.radioGroupHelper = new RadioGroupHelper(binding);
    }

    public void setQuestionToUI(Question question){
        binding.setQuestion(question);
    }

    public void setQuestionNumberToUI(int number){
        setTextViewQuestionNumberText(number);
    }

    public void setTextViewQuestionNumberText(int questionNumber) {
        this.textViewQuestionNumber.setText(String.valueOf(questionNumber));
    }

    public String getCheckedAnswerFromPlayer(){
        return radioGroupHelper.getCheckedAnswerFromPlayer();
    }

    public ImageButton getImageButtonToNextQuestion() {
        return imageButtonToNextQuestion;
    }
}


















































