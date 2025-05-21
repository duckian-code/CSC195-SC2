//
// Created by anabelle on 20/05/25.
//

#ifndef MEAT_H
#define MEAT_H
#include "Food.h"


class Meat : public Food {
public:
    Meat(bool red_meat) {
        is_red_meat = is_red_meat;
    }

    void Consume() override;
protected:
    bool is_red_meat;
};



#endif //MEAT_H
