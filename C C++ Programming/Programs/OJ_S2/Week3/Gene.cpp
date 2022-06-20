#include <iostream>
#include <vector>
#include <map>

using namespace std;

const string D = "dominant";
const string R = "recessive";
const string N = "non-existent";

map<string , string> gene;
map<string , vector<string>> parent;

using namespace std;

class GENE{
    private:
        int Input;
    public:

        void getData();
        void findGene();
        void getGene(string child , string P1 , string P2);
        void printData();

        GENE(int input)
        {
            Input = input;
        }  
};

void GENE::getData()
{
    while (Input--)
    {
        string a , b;
        cin >> a >> b;

        if(b == D || b == R || b == N)
        {
            gene[a] = b;
        }else
        {
            parent[b].push_back(a);
        }
    }   
}

void GENE::getGene(string child , string P1 , string P2)
{
    if (gene.find(P1) == gene.end())
    {
        getGene(P1, parent[P1][0], parent[P1][1]);
    }

    if (gene.find(P2) == gene.end())
    {
        getGene(P2, parent[P2][0], parent[P2][1]);
    }

    if((gene[P1] == D && gene[P2] == D) ||
       (gene[P1] == D && gene[P2] == R) ||
       (gene[P1] == R && gene[P2] == D))
    {
        gene[child] = D;
    }else if(
       (gene[P1] == R && gene[P2] == R) ||
       (gene[P1] == D && gene[P2] == N) ||
       (gene[P1] == N && gene[P2] == D))

        gene[child] = R;
    else
    {
        gene[child] = N;
    }
}

void GENE::findGene()
{
    for(map<string , vector<string>> :: iterator itr = parent.begin(); itr != parent.end(); ++itr)
    {
        if (gene.find(itr->first) == gene.end())
        {
            getGene(itr->first , itr->second[0] , itr->second[1]);
        }
   }

}

void GENE::printData()
{
    for (map<string, string>::iterator itr = gene.begin(); itr != gene.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
    
}


int main()
{
    int samples;
    cin >> samples;
    GENE result(samples);

    result.getData();
    result.findGene();
    result.printData();

    
    return 0;
}