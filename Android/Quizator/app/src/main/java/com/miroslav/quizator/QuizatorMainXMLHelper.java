package com.miroslav.quizator;

import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.miroslav.quizator.actor.Question;
import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;

public class QuizatorMainXMLHelper {
    ImageButton imageButtonToNextQuestion;
    LinearLayout layoutQuestionRoot;
    LinearLayout layoutAnswersRoot;
    TextView textViewQuestionNumber;
    FragmentQuizatorMainBinding binding;
    RadioGroupHelper radioGroupHelper;


    public QuizatorMainXMLHelper(FragmentQuizatorMainBinding binding) {
        this.binding=binding;
    }
    public void initAllQuizatorMainXMLElements(){
        setImageButtonToNextQuestion(binding.imageButtonToNextQuestion);
        setLayoutQuestionRoot(binding.layoutQuestionRoot);
        setLayoutAnswersRoot(binding.layoutAnswersRoot);
        setTextViewQuestionNumber(binding.textViewQuestionNumber);
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

    public void setImageButtonToNextQuestion(ImageButton imageButtonToNextQuestion) {
        this.imageButtonToNextQuestion = imageButtonToNextQuestion;
    }

    public void setLayoutQuestionRoot(LinearLayout layoutQuestionRoot) {
        this.layoutQuestionRoot = layoutQuestionRoot;
    }

    public void setLayoutAnswersRoot(LinearLayout layoutAnswersRoot) {
        this.layoutAnswersRoot = layoutAnswersRoot;
    }

    public void setTextViewQuestionNumber(TextView textViewQuestionNumber) {
        this.textViewQuestionNumber = textViewQuestionNumber;
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


















































