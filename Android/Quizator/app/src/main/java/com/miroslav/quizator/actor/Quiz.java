package com.miroslav.quizator.actor;

import java.util.ArrayList;

public class Quiz {
    ArrayList<Question> questions;
    int questionNumber;
    final int FIRST_QUESTION_NUMBER = 0;


    public Quiz(ArrayList<Question> questions) {
        this.questions = questions;
        setQuestionNumber(FIRST_QUESTION_NUMBER);

    }

    public void setQuestionNumber(int questionNumber) {
        this.questionNumber = questionNumber;
    }


    public Question getFirstQuestion() {
        return questions.get(FIRST_QUESTION_NUMBER);
    }
    public Question getQuestionBesideCurrentQuestionNumber(int currentQuestionNumber){
        return getQuestions().get(currentQuestionNumber);
    }

    //TODO : return int and use it to setQustioNumber
    public void incrementQuestionNumber() {
        this.questionNumber+= 1;
    }

    public boolean isQuizCompleted() {
        return isCurrentQuestionNumberEqualToQuestionSizeMinusOne();
    }

    public boolean isCurrentQuestionNumberEqualToQuestionSizeMinusOne(){
        return getCurrentQuestionNumber() == getQuestionsSizeMinusOne();
    }

    public int getCurrentQuestionNumber() {
        return questionNumber;
    }

    public int getQuestionsSizeMinusOne(){
        return getQuestions().size()-1;
    }

    public ArrayList<Question> getQuestions() {
        return questions;
    }
}































