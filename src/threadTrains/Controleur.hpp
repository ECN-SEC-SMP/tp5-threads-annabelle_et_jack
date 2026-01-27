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
    this->sens = true; // true = B->A , false = A->B
    this->val = 0; // nombre de trains sur la voie actuellement
    this->compt = 0; // compteur de trains qui passes dans le meme sens
  }

  bool controlinEnB(int numero) 
  {
    // Premier train sur la voie
    if (this->val == 0)
    {
        this->sens = true;  
        this->compt = 0;     
    }

    // Max 2 trains sur la voie en meme temps
    if (this->val >= 2 && this->sens == true)
    {
      return false;
    } 

    // Limite a 3 trains consécutifs dans un sens
    if (this->sens == true && this->compt >= 3)
    {
      return false;
    }

    // Autorisation de passer
    this->val++;
    this->compt++;
    return true;

  }

  bool controlinEnA(int numero)
  {
    // Premier train sur la voie
    if (this->val == 0)
    {
      this->sens = false;
      this->compt = 0;     
    }

    // Max 2 trains sur la voie en meme temps   
    if (this->val >= 2 && this->sens == false)
    {
      return false;
    }
    
    // Limite a 3 trains consécutifs dans un sens
    if (this->sens == false && this->compt >=3)
    {
      return false;
    }

    // Autorisation de passer
    this->val++;
    this->compt++;
    return true;
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
  int compt;
};

#endif // CONTROLEUR_HPP
