#include "Queue.h"

// Constructor & Destructor
Queue::Queue()
{
    this->head = nullptr;
    this->tail = nullptr;

    this->m_count = 0;
    this->m_max = 3;
}

Queue::~Queue()
{
    while (this->head != nullptr)
    {
        PowerUp* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

// Accessors
int Queue::size() const
{
    return this->m_count;
}

bool Queue::isEmpty() const
{
    return this->m_count == 0;
}

PowerUp* Queue::front()
{
    return this->head;
}

// Modifiers
void Queue::enqueue(PowerUp* PowerUp)
{
    if (this->m_count == this->m_max)
    {
        return;
    }

    if (this->isEmpty())
    {
        this->head = PowerUp;
        this->tail = PowerUp;
    }
    else
    {
        this->tail->next = PowerUp;
        this->tail = PowerUp;
    }

    this->m_count++;
}

void Queue::dequeue()
{
    if (this->isEmpty())
    {
        return;
    }

    PowerUp* temp = this->head;
    this->head = this->head->next;
    delete temp;

    this->m_count--;
}

// Functions
void Queue::clear()
{
    while (this->head != nullptr)
    {
        PowerUp* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }

    this->m_count = 0;
}

void Queue::updateAll()
{
    if (this->isEmpty())
    {
        return;
    }

    PowerUp* temp = this->head;

    float counter = 0.132f;
    while (temp != nullptr)
    {
        temp->update(counter);
        temp = temp->next;
        counter -= 0.05f;
    }
}

void Queue::renderAll(sf::RenderTarget* target)
{
    if (this->isEmpty())
    {
        return;
    }

    PowerUp* temp = this->head;
    while (temp != nullptr)
    {
        temp->render(target);
        temp = temp->next;
    }
}