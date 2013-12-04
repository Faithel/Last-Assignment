//David Strickland
//Faith Van Wig
//Class and Section: CS53 D
//Date: December  4, 2013
//Final Assignment, OOP, Bar people vs. Comic people


#include "bus.h"
#include <iostream>
#include <string>

using namespace std;

const int PEOPLE = 20;


void business::addCustomer(customer c)
{
  
  m_sizeCusts++;
  return;
}
 
void sell_stuff(Customer cust[])
{
  bool success;
  float money;
  int item;
  
  for (int i = 0; i < m_sizeCusts; i++)
  {
    item = rand()% NUM_OF_ITEMS - 1;
    
    if (cust[i].buy_something(m_items[item]) == success)
    {
      money = addCash(items[i].m_price)
      //transfer product to the customer (in array) and transfer funds
    }
  }
  return;
}



void customers_leave (Customer street[], int numOfCusts)
{
  for (int i = 0; i < numOfCusts; i++)
  {
    street[i].setMoney(m_custs[i].m_money);
    street[i].setItems(m_custs[i].m_things[m_numThings]);
  }
  m_custs[] = {};
  numOfCusts = 0;
  return;
}  

/*  
Business::Business(const string name)
:m_name(name)
{
  for(int i = 0; i < NUM_OF_ITEMS; i++)
  {
    //unneeded, inlined, only sets business name 
  }  
}
*/

#endif
