#include <iostream>
#include <string>

using namespace std;

void store(string (*board)[8]);

int main()
{
    /*Print B R Board*/
//     string board[8][8];

//     store(board);

//    for (int i = 0; i < 8; i++)
//    {
//        for (int j = 0; j < 8; j++)
//        {
//            cout << board[i][j] << " ";
//        }
//        cout << endl;
//    }

    /*Sort Grade*/
    int grades[8] , rank = 1;
    string names[8];

    for (int i = 0; i < 8; i++)
    {
        cin >> names[i];
    }

    for (int i = 0; i < 8; i++)
    {
        cin >> grades[i];
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            if(grades[i] > grades[j]){
                int temp = grades[i];
                string name = names[i];
                grades[i] =  grades[j];
                grades[j] = temp;
                names[i] = names[j];
                names[j] = name;
            }
        }
    }

    for (int i = 7; i >= 0; i--)
    {
        cout << "Rank: " << rank++ << " " << names[i] << " \t" << grades[i] << endl;
    }
    


    
    

   
    

    return 0;
}

void store(string (*board)[8]){

    bool choice = true;

    for (int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++){
            if(i % 2 == 0){
               
                if(choice){
                    board[i][j] = "B";
                    choice = false;
                }else{
                    board[i][j] = "R";
                    choice = true;
                }
            }else{
                if(choice){
                    board[i][j] = "R";
                    choice = false;
                }else{
                    board[i][j] = "B";
                    choice = true;
                }
            }
        }
    }
    
}

