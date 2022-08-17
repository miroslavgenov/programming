package com.miroslav.quizator.actor;

public class Player {
    int score;
    public Player(){}

    public int getScore() {
        return score;
    }

    //TODO : return int and use it to set the score
    public void incrementScoreByOne(){
        this.score+=1;
    }

    public void setScore(int score) {
        this.score = score;
    }
}
