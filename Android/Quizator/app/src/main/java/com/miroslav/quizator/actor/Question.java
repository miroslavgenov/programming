package com.miroslav.quizator.actor;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Question {
    String questionTitle;
    String[] questionAnswers;
    String[] questionAnswersShuffled;
    String question;


    public Question(String questionTitle, String question, String[] questionAnswers) {
        setQuestionTitle(questionTitle);
        setQuestion(question);
        setQuestionAnswers(questionAnswers);
        questionAnswersShuffled = new String[questionAnswers.length];

        for(int i=0;i<questionAnswersShuffled.length;i++){
            questionAnswersShuffled[i]=questionAnswers[i];
        }
        Collections.shuffle(Arrays.asList(questionAnswersShuffled));


    }

    public void setQuestionTitle(String questionTitle) {
        this.questionTitle = questionTitle;
    }

    public void setQuestion(String question) {
        this.question = question;
    }

    public void setQuestionAnswers(String[] questionAnswers) {
        this.questionAnswers = questionAnswers;
    }

    public String[] getQuestionAnswersShuffled() {
       return questionAnswersShuffled;
    }

    public String getQuestionTitle() {
        return questionTitle;
    }

    public String getCorrectQuestionAnswer() {
        return this.questionAnswers[0];
    }

    public String getQuestion() {
        return question;
    }

    public String[] getQuestionAnswers() {
        return questionAnswers;
    }
}














































