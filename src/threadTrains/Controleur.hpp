#ifndef CONTROLEUR_HPP
#define CONTROLEUR_HPP

#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

class Controleur
{
public:
  Controleur(int valeur_initiale) : val(valeur_initiale)
  {
    this->sens = true;
  }

  bool controlinEnB(int numero)
  {
    if (this->val == 0)
    {
      this->val++;
      this->sens = true;
      return true;
    }
    else if (this->val > 0 && this->sens == true && )
    {
      this->val++;
      return true;
    }
    return false;
  }

  bool controlinEnA(int numero)
  {
    if (this->val == 0)
    {
      this->val++;
      this->sens = false;
      return true;
    }
    else if (this->val > 0 && this->sens == false)
    {
      this->val++;
      return true;
    }
    return false;
  }

  bool controloutEnB(int numero)
  {
    this->val--;
    return true;
  }

  bool controloutEnA(int numero)
  {
    this->val--;
    return true;
  }

private:
  bool sens;
  int val;
};

#endif // CONTROLEUR_HPP
