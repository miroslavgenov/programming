package com.miroslav.quizator.actor;

import com.miroslav.quizator.Questions;

import java.util.ArrayList;

public class Quiz {
    Questions questionsForQuiz;

    public Quiz(Questions questionsForQuiz){
        this.questionsForQuiz = questionsForQuiz;
    }

    public Question getFirstQuestion(){
        return this.questionsForQuiz.getFirstQuestion();
    }

//    public Quiz(ArrayList<Question> questions) {
//        this.questions = questions;
//        setQuestionNumberToFirst(FIRST_QUESTION_NUMBER);
//    }

//    public void setQuestionNumberToFirst(int questionNumber) {
//        this.questionNumber = questionNumber;
//    }


//    public Question getFirstQuestion() {
//        return questions.get(FIRST_QUESTION_NUMBER);
//    }
//    public Question getQuestionBesideCurrentQuestionNumber(int currentQuestionNumber){
//        return getQuestions().get(currentQuestionNumber);
//    }

    //TODO : return int and use it to setQustioNumber
//    public void incrementQuestionNumber() {
//        this.questionNumber+= 1;
//    }

//    public boolean isQuizCompleted() {
//        return isCurrentQuestionNumberEqualToQuestionSizeMinusOne();
//    }

//    public boolean isCurrentQuestionNumberEqualToQuestionSizeMinusOne(){
//        return getCurrentQuestionIndex() == getQuestionsSizeMinusOne();
//    }

    public int getCurrentQuestionIndex() {
        return questionsForQuiz.getCurrentQuestionIndex();
    }

//    public int getQuestionsSizeMinusOne(){
//        return getQuestions().size()-1;
//    }

//    public ArrayList<Question> getQuestions() {
//        return questions;
//    }
}































