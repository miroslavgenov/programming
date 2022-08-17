package com.miroslav.quizator.actor;

import java.util.ArrayList;

public class Quiz {
    ArrayList<Question> questions;
    int questionNumber;

    public void setQuestionNumber(int questionNumber) {
        this.questionNumber = questionNumber;
    }

    public int getCurrentQuestionNumber() {
        return questionNumber;
    }

    public Question getFirstQuestion(){

        return questions.get(getCurrentQuestionNumber());
    }
    public void incrementQuestionNumber(){
        this.questionNumber+=1;
    }
    public boolean isQuizCompleted(){
        return getCurrentQuestionNumber()==getQuestions().size()-1;
    }
    public ArrayList<Question> getQuestions() {
        return questions;
    }

    public Quiz(ArrayList<Question> questions){
        this.questions=questions;
        setQuestionNumber(0);

    }
}
















