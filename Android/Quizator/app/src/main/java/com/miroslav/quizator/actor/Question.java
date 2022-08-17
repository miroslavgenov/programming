package com.miroslav.quizator.actor;


public class Question {
    String questionTitle;
    String[] questionAnswers;
    String question;

    public Question(String questionTitle,String question,String[] questionAnswers){
        setQuestionTitle(questionTitle);
        setQuestion(question);
        setQuestionAnswers(questionAnswers);

    }

    public void setQuestionTitle(String questionTitle) {
        this.questionTitle = questionTitle;
    }

    public void setQuestion(String question) {
        this.question = question;
    }

    public void setQuestionAnswers(String[] questionAnswers) {
        this.questionAnswers=questionAnswers;
    }

    public String getQuestionTitle() {
        return questionTitle;
    }
    public String getCorrectQuestionAnswer(){
        return this.questionAnswers[0];
    }
    public String getQuestion() {
        return question;
    }

    public String[] getQuestionAnswers() {
        return questionAnswers;
    }
}























































