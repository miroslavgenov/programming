package com.miroslav.quizator.actor;

public class Questor {

    Question questionGivenToPlayer;
    String questionAnswerPassedFromPlayer;

    public Questor() {
    }

    public void setQuestionAnswerPassedFromPlayer(String questionAnswerPassedFromPlayer) {
        this.questionAnswerPassedFromPlayer = questionAnswerPassedFromPlayer;
    }

    public void setQuestionGivenToPlayer(Question questionGivenToPlayer) {
        this.questionGivenToPlayer = questionGivenToPlayer;
    }

    public static  boolean isPlayerAnswerCorrect(Question questionGivenToPlayer , String questionAnswerPassedFromPlayer){
        return questionGivenToPlayer.getCorrectQuestionAnswer().equals(
                questionAnswerPassedFromPlayer);
    }

    public boolean isPlayerAnswerCorrect() {
        return questionGivenToPlayer.getCorrectQuestionAnswer().equals(
                questionAnswerPassedFromPlayer);
    }
}
