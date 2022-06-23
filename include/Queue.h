#ifndef QUEUE_H
#define QUEUE_H

#include "PowerUp.h"

class Queue
{
private:
    PowerUp* head;
    PowerUp* tail;

    int m_count;
    int m_max;

    float pos_x;

public:
    // Constructor & Destructor
    Queue();
    ~Queue();

    // Accessors
    int size() const;
    bool isEmpty() const;
    PowerUp* front();

    // Modifiers
    void enqueue(PowerUp* PowerUp);
    void dequeue();

    // Functions
    void clear();
    void updateAll();
    void renderAll(sf::RenderTarget* target);
};


#endif