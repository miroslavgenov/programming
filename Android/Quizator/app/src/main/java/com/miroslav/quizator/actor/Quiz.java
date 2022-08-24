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

    public int getCurrentQuestionIndex() {
        return questionsForQuiz.getCurrentQuestionIndex();
    }

    public int toNextQuestionNumber(){
        questionsForQuiz.setCurrentQuestionIndex(questionsForQuiz.incrementCurrentQuestionIndexByOne());
        return questionsForQuiz.getCurrentQuestionIndex();
    }
    public boolean isQuizComplete(){
        return getCurrentQuestionIndex() == questionsForQuiz.getQuestionSize()-1;
    }
    public Question getCurrentQuestion(){
        return questionsForQuiz.getCurrentQuestion();
    }

}































