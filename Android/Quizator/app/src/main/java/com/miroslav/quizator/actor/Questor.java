package com.miroslav.quizator.actor;

import android.util.Log;

public class Questor {

    Question questionGivenToPlayer;
    String questionAnswerPassedFromPlayer;

    public Questor() {
    }

    public void setQuestionAnswerPassedFromPlayer(String checkedAnswerFromPlayer) {
        this.questionAnswerPassedFromPlayer = checkedAnswerFromPlayer;
    }

    public void setQuestionGivenToPlayer(Question questionGivenToPlayer) {
        this.questionGivenToPlayer = questionGivenToPlayer;
    }

    public static  boolean isPlayerAnswerCorrect(Question questionGivenToPlayer , String questionAnswerPassedFromPlayer){
        Log.d("MyQue",questionGivenToPlayer.getCorrectQuestionAnswer()+ "  "+ questionAnswerPassedFromPlayer);
        return questionGivenToPlayer.getCorrectQuestionAnswer().equals(
                questionAnswerPassedFromPlayer);
    }

    public boolean isPlayerAnswerCorrect() {
        return questionGivenToPlayer.getCorrectQuestionAnswer().equals(
                questionAnswerPassedFromPlayer);
    }
}






























