//
// Created by anabelle on 19/05/25.
//

#ifndef FOOD_H
#define FOOD_H



class Food {
public:
    Food() {
        m_calories = 0;
    }

    // destructor
    ~Food() {

    }
    Food(int calories) {
        m_calories = calories;
    }

    void Consume();
    int GetCalories(){return m_calories;}
    void SetCalories(int calories){m_calories = calories;}
protected:
    int m_calories;
};



#endif //FOOD_H
