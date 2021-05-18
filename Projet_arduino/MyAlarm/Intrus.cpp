#include <cstdlib>
#include "Intrus.h"

using namespace std;

// Surcharge de l'opérateur +=
Intrus & Intrus::operator += (const Intrus & operande) {
  compteur += operande.compteur;
  return (*this);
}
