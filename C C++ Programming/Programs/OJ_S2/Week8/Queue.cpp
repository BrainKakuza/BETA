#include <iostream>

class container
{
protected:
    int *box;
    int len;
    void copy(int *from, int *to, int l)
    {
        for(int i=0; i<l; i++)
            to[i] = from[i];
    }
public:
    container(): box(NULL), len(1) {}
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
        if(!tmp)
            return false;
        copy(this->box, tmp, this->len);
        delete box;
        this->box = tmp;
        this->len = l;
        return true;
    }
};

class queue: private container
{
private:
    int index;
public:
    queue(): container() , index(-1){}

    queue(int l): container(l) , index(-1){}

    queue(const queue &a): container(a)
    {
        box = a.box;
        len = a.len;
        index = a.index;
    }

    bool enqueue(int data)
    {
        if(index == len - 1)
        {
            return false;
        }else
        {
            index++;
            box[index] = data;
            return true;
        }
    }

    int *dequeue()
    {
        if(index == -1)
        {
            return NULL;
        }else
        {
            int * point = new int;
            int answer = box[0];
            *point = answer;
            
            for (int i = 0; i < index + 1; i++)
            {
                box[i] = box[i + 1];
            }

            index--;
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

    // void print()
    // {
    //     for (int i = 0; i < index + 1; i++)
    //     {
    //         std::cout << box[i] << " ";
    //     }
    //     std::cout << std::endl;
    // }
};

int main()
{    
    queue q(5);
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(15);
    q.dequeue();

    q.getLen();


    return 0;
}