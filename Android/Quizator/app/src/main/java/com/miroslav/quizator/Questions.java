package com.miroslav.quizator;

import com.miroslav.quizator.actor.Question;

import java.util.ArrayList;
import java.util.Collections;

public class Questions {
    final int FIRST_QUESTION_INDEX = 0;
    int currentQuestionIndex;
    ArrayList<Question> questions;

    public Questions(){
        questions = new ArrayList<Question>();
        currentQuestionIndex =0;
    }

    public int getCurrentQuestionIndex(){
        return this.currentQuestionIndex;
    }

    public String[] getQuestionAnswersShuffled(){
        return questions.get(currentQuestionIndex).getQuestionAnswersShuffled();
    }

    public Question getFirstQuestion(){
        return questions.get(FIRST_QUESTION_INDEX);
    }

    public Question getCurrentQuestion(){
        return questions.get(currentQuestionIndex);
    }

    public int incrementCurrentQuestionIndexByOne(){
        return currentQuestionIndex+1;
    }

    public void setCurrentQuestionIndex(int value) {
        this.currentQuestionIndex = value;
    }

    public void shuffleQuestions(){
        Collections.shuffle(this.questions);
    }

    public void appendQuestion(Question questionToBeAppended){
        this.questions.add(questionToBeAppended);
    }


}





















































