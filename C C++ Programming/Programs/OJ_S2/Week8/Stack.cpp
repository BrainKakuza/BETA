#include <iostream>

class container
{
protected:
    int *box;
    int len;
    void copy(int *from, int *to, int l)
    {
        for (int i = 0; i < l; i++)
            to[i] = from[i];
    }

public:
    container() : box(NULL), len(1) {}
    container(int l)
    {
        int *tmp = new int[l];
        this->len = l;
        this->box = tmp;
    }
    container(const container &a)
    {
        int *tmp = new int[a.len];
        copy(a.box, tmp, a.len);
        this->len = a.len;
    }
    bool reallocate(int l)
    {
        int *tmp = new int[l];
        if (!tmp)
            return false;
        copy(this->box, tmp, this->len);
        delete box;
        this->box = tmp;
        this->len = l;
        return true;
    }
};

class stack : private container
{
private:
    int top;
public:
    stack() : container(), top(-1) {}

    stack(int l) : container(l), top(-1) {}

    stack(const stack &a) : container(a)
    {
        len = a.len;
        top = a.top;
        box = a.box;
    }

    bool push(int data)
    {
        if (top == len - 1)
        {
            return false;
        }
        else
        {
            top += 1;
            box[top] = data;
            return true;
        }
    }

    int *pop()
    {
        if (top == -1)
        {
            return NULL;
        }
        else
        {
            int num = box[top];
            int *point = new int;
            *point = num;
            top--;

            return point;
        }
    }

    bool increase()
    {
        len *= 2;
        reallocate(len);
        return true;
    }

    int getLen()
    {
        return len;
    }
};

int main()
{
    stack s1(3);
    s1.push(5);
    s1.push(10);
    s1.push(10);
    s1.pop();

    return 0;
}