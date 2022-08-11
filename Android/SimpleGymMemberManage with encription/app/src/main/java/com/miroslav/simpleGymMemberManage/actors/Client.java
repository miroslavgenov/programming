package com.miroslav.simpleGymMemberManage.actors;


/**
 * Client class is main actor
 * @author Miroslav Genov
 */
public class Client {

    int client_id;
    String client_name;
    int client_card_id;

    /**
     *
      * @param client_id
     * @param client_name
     * @param client_card_id
     */
    public Client(int client_id, String client_name, int client_card_id) {
        this.client_id = client_id;
        this.client_name = client_name;
        this.client_card_id = client_card_id;
    }

    /**
     *
     * @return
     */
    public int getClient_id() {
        return client_id;
    }


    /**
     *
     * @param client_id
     */
    public void setClient_id(int client_id) {
        this.client_id = client_id;
    }


    /**
     *
     * @return
     */
    public String getClient_name() {
        return client_name;
    }


    /**
     *
     * @param client_name
     */
    public void setClient_name(String client_name) {
        this.client_name = client_name;
    }


    /**
     *
     * @return
     */
    public int getClient_card_id() {
        return client_card_id;
    }


    /**
     *
     * @param client_card_id
     */
    public void setClient_card_id(int client_card_id) {
        this.client_card_id = client_card_id;
    }


    /**
     *
     * @return
     */
    @Override
    public String toString() {
        return client_id + " " + client_name + " " + client_card_id;

    }


}



































