//David Strickland
//Faith Van Wig
//Class and Section: CS53 D
//Date: December 4, 2013
//Final Assignment, OOP, Bar people vs. Comic people

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <cstdlib>

using namespace std;

const int POCKET_SIZE = 20;

struct Product
{
  string m_name;
  float m_price;
};

class Customer
{
  private:
    Product m_things[POCKET_SIZE];
    int m_numThings;
    string m_name;
    int m_happiness;
    int m_store;
    float m_money;

  public:
    Customer();
    Customer(const string name, const float money, const int happiness,
             const int store);
    //Desc:
    //Pre: none
    //Post:
    bool buy_stuff(const Business shop);
    //Desc:
    //Pre: none
    //Post:
    string getName() const {return m_name;}
    //Desc:
    //Pre: none
    //Post:
    float getMoney() const {return m_money;}
    //Desc:
    //Pre: none
    //Post:
    float modMoney(const float money) {return m_money -= money;}
    //Desc:
    //Pre: none
    //Post:
    float setMoney(const float money) {return m_money = money;}
    //Desc:
    //Pre: none 
    //Post:    
    string setName(const string name) {return m_name = name;}
    //Desc:
    //Pre: none
    //Post:
    int getPref() const {return m_store;}
    //Desc:
    //Pre: none
    //Post:    
    int setPref(const int store) {return m_store = store;}
    //Desc:
    //Pre: none
    //Post:   
    Product setItems(const Product thing); 
    //Desc:
    //Pre: none
    //Post:    
    void pelt(Customer victim);
    //Desc:
    //Pre: none
    //Post:
    void steal(Customer victim);
    //Desc: Accessor. 
    //Pre: none
    //Post: Returns happiness of customer
    int getHappy() const {return m_happiness;}
    //Desc: 
    //Pre: none
    //Post: 
    int setHappy(const int newHappy) {return m_happiness = newHappy;} 
  
  friend ostream& operator<< (ostream& out, const Customer& python);
};

#endif
