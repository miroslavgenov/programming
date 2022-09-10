package com.miroslav.quizator;

import com.miroslav.quizator.actor.*;
import com.miroslav.quizator.initializer.GameUtilInitializer;
// TODO MAKE GAME UTILIZER PRIVET HERE only to be used for QuizGame class but not in the class

public class QuizGame {
    Player quizPlayer;
    Questor quizQuestor;
    Quiz quiz;
    QuizatorMainXMLHelper quizatorMainXMLHelper;

    public QuizGame(QuizatorMainXMLHelper quizatorMainXMLHelper){
        this.quizatorMainXMLHelper = quizatorMainXMLHelper;
        this.quizQuestor = GameUtilInitializer.createQuestor();
        this.quizPlayer = GameUtilInitializer.createPlayer();
        this.quiz = GameUtilInitializer.createQuiz();
        loadFirstQuestion();
    }

    public void loadFirstQuestion(){
        quizatorMainXMLHelper.setQuestionNumberToUI(quiz.getCurrentQuestionIndex());
        quizatorMainXMLHelper.setQuestionToUI(quiz.getFirstQuestion());
    }

    public void quizGameLogic() {
        setQuestorAnswerAndQuestionToCheck();

        shouldGoToNextQuestion();
    }

    private void setQuestorAnswerAndQuestionToCheck() {
        quizQuestor.setQuestionAnswerPassedFromPlayer(quizatorMainXMLHelper.getCheckedAnswerFromPlayer());
        quizQuestor.setQuestionGivenToPlayer(quiz.getCurrentQuestion());
    }

    private void shouldIncreasePlayerScore() {
        if(quizQuestor.isPlayerAnswerCorrect()){
            quizPlayer.setScore(quizPlayer.incrementScoreByOne());
        }
    }

	//TODO change the name of shouldGoToNextQuestion
    private void shouldGoToNextQuestion() {
        shouldIncreasePlayerScore();
        if(!quiz.isQuizComplete()){
            toNextQuestion();
        }
    }
    private void toNextQuestion() {
        quiz.setCurrentQuestionIndex(quiz.incrementCurrentQuestionIndexByOne());
        quizatorMainXMLHelper.setTextViewQuestionNumberText(quiz.getCurrentQuestionIndex());
        quizatorMainXMLHelper.setQuestionToUI(quiz.getCurrentQuestion());
    }

    public int getPlayerScore(){
        return quizPlayer.getScore();
    }

    public boolean isQuizCompleted(){
        return quiz.isQuizComplete();
    }

}






















