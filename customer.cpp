//David Strickland
//Faith Van Wig
//Class and Section: CS53 D
//Date: December 4, 2013
//Final Assignment, OOP, Bar people vs. Comic people

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "customer.h"

using namespace std;

const int NUM = 24001, SMILE = 101;


Customer::Customer()
:m_numThings (0)
{
  srand(time(NULL));
  m_happiness = rand % SMILE;
  m_money = static_cast <float> (rand % NUM) / 100.00;
}

Customer::Customer(const string name, const float money, const int happiness, const int
         store)
:m_numThings (0), m_name (name), m_happiness (happiness), m_store (store),
 m_money (money) {}

bool Customer::buy_stuff(const product item)
{
  int chance, item;
  bool buy, confirm;

  chance = rand % 101;

  if (chance < 50)
     buy = true;
  else if (chance >= 50)
     buy = false;

//decide if they will buy something (done)
//choose a random product from the business
//if they can afford it, bus gets money, cust loses money, +product to pocket, +15 happiness,
//if they can't afford it, happiness -10 
    
    
    if (item.m_price <= m_money)
    {
      m_happiness += 15;
      modMoney(-item.m_price);
      m_things[m_numThings].m_price = item.m_price;
      m_things[m_numThings].m_name = item.m_name;
      m_numThings++;
      confirm = true;
    }
    
    else
    {
      m_happiness -= 10;
      confirm = false;
    }
  }

  else
    m_happiness -= 10;

  return confirm;
}

Product Customer::setItems(const Product thing)
{
  m_things[m_numThings].m_name = thing.m_name;
  m_things[m_numThings].m_price = thing.m_price;
  m_numThings++;
  return m_things[m_numThings -1];
}

void Customer::pelt(Customer victim)
{
  if (m_numThings == 0)
  {
    m_happiness -= 25;
  }

  else
  {
    m_happiness += 5;
    victim.m_happiness -= 20;
    m_numThings--;
  }

  return;
}

void Customer::steal(Customer victim)
{
  if (victim.m_numThings == 0)
    m_happiness -= 5;
  else if (victim.m_numThings != 0 && m_numThings < (POCKET_SIZE - 1))
  {
    m_happiness += 25;
    victim.m_numThings -= 20;
    m_things[m_numThings] = victim.m_things[victim.m_numThings];
    m_numThings++;
    victim.m_numThings--;
  }

  else if (victim.m_numThings != 0 && m_numThings >= (POCKET_SIZE - 1))
    m_happiness -= 5;

  return;
}

ostream& operator<< (ostream& out, const Customer& python)
{
  out << python.m_name << " has $" << python.m_money << " and purchases: ";
  if (python.m_numThings == 0)
    out << "none";
  for (int i = 0; i < python.m_numThings; i++)
  {
    cout << python.m_things[i].m_name << ((i < python.m_numThings - 1)? ", " : "");
  }
  cout << endl;
  return out;
}

Custromer Customer::operator= (Customer& person)
{
  person.setHappy(m_happiness);
  person.setMoney(m_money);
  person.setName(m_name);
  person.setPref(m_store);
  person.setNumThings(m_numThings);
  for(int i = 0, i < m_numThings; i++)
  {
    person.things[i].m_name = m_things[i].m_name;
    person.things[i].m_price = m_things[i].m_price;
  }
  
  return person;
}
