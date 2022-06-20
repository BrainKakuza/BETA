#include <iostream>

using namespace std;

class Motor
{
    double energy, resistance, current;

public:
    Motor(double E, double R, double I) : energy(E), resistance(R), current(I) {}
    double runnableTime() const
    {
        return energy / (resistance * current * current);
    }
};

class Engine
{
    double energy, performance;

public:
    Engine(double E, double P) : energy(E), performance(P) {}
    double runnableTime() const
    {
        return energy / performance;
    }
};

class Hybrid : public Motor, public Engine
{
private:
    double energy;
public:
    Hybrid(double ME, double MR, double MI, double EE, double EP) : Motor(ME, MR, MI), Engine(EE, EP), energy(ME)
    {
    }
    
    double runnableTime() const
    {
        double runtimeOne = Engine::runnableTime();
        double runtimeTwo = Motor::runnableTime();

        if((runtimeOne == 0 && runtimeTwo == 0) || (runtimeOne == 0 && runtimeTwo != 0) || (runtimeOne != 0 && runtimeTwo == 0))
        {
            return 0;
        }else if(runtimeOne > runtimeTwo)
        {
            return runtimeOne;
        }else if(runtimeTwo > runtimeOne)
        {
            return runtimeTwo;
        }else if(runtimeOne == runtimeTwo)
        {
            return runtimeOne;
        }


    }
};

int main(void)
{
    

    return 0;
}