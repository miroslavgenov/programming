package com.miroslav.simpleGymMemberManage.actors;


/**
 * Client class is main actor
 * @author Miroslav Genov
 */
public class Client {

    Integer client_id;
    String client_name;
    Integer client_card_id;

    /**
     *
      * @param client_id
     * @param client_name
     * @param client_card_id
     */
    public Client(Integer client_id, String client_name, Integer client_card_id) {
        this.client_id = client_id;
        this.client_name = client_name;
        this.client_card_id = client_card_id;
    }

    /**
     *
     * @return
     */
    public Integer getClient_id() {
        return client_id;
    }


    /**
     *
     * @param client_id
     */
    public void setClient_id(Integer client_id) {
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
    public Integer getClient_card_id() {
        return client_card_id;
    }


    /**
     *
     * @param client_card_id
     */
    public void setClient_card_id(Integer client_card_id) {
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



































