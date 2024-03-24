#pragma once

class Counter {
public:
    Counter();

    Counter(int value);

    void Increment();

    void Decrement();

    int GetValue();

private:
    int value_;

};

void InteractWithUser(Counter &c);