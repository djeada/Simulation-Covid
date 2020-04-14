#include "mobility_model.h"

#include <stddef.h>
#include <assert.h>
#include "mobility_model.h"
#include "person.h"

//random move at random times to random places
//popular places go to specific places

MobilityModel::MobilityModel(){
    person = NULL;
}

void MobilityModel::setPerson(Person *p){
    assert(p != NULL);
    person = p;
}

