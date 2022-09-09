package com.miroslav.quizator.actor;

public class Questor {
    Question questionGivenToPlayer;
    String questionAnswerPassedFromPlayer;

    public void setQuestionAnswerPassedFromPlayer(String checkedAnswerFromPlayer) {
        this.questionAnswerPassedFromPlayer = checkedAnswerFromPlayer;
    }

    public void setQuestionGivenToPlayer(Question questionGivenToPlayer) {
        this.questionGivenToPlayer = questionGivenToPlayer;
    }

    public boolean isPlayerAnswerCorrect() {
        return questionGivenToPlayer.getCorrectQuestionAnswer().equals(
                questionAnswerPassedFromPlayer);
    }
}






























