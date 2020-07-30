#include "board.hpp"

using namespace std;

    board::board(){//domyslny konstruktor tworzacy pole o boku 3
        this->player='O';//domyslnie zaczyna kolko
        this->moves=9;
        this->grid=new char[size*size+1];
        memset(grid,' ',size*size+1);
    }

    board::board(int board_size, int elements_in_line){//konstruktor z parametrem rozmiaru i dlugosci linii
        this->player='O';//domyslnie zaczyna kolko

        this->moves=size*size;
        this->grid=new char[size*size+1];
        memset(grid,' ',size*size+1);
    }

    board::board(const board &b){
        this->moves=b.moves;
        this->player=b.player;
        this->winner=b.winner;
        this->size=b.size;
        this->elements_in_line=b.elements_in_line;
        grid=new char[size*size+1];
        for(int i=0;i<=size*size;i++){
            grid[i]=b.grid[i];
        }
    }

    board::~board(){
    delete &this->grid;
    }

    void board::print(){
        for(int i=0;i<size*size;i+=size){
            cout<<" ";
            for(int j=1;j<=size;j++){
                    if(j==size)
                        cout<<grid[j+i];
                    else
                        cout<<grid[j+i]<<" | ";
            }
            cout<<endl;

            if(i<size*size-size){
                for(int k=0;k<size;k++){
                    cout<<"---";
                }
                for(int k=0;k<size-1;k++)
                    cout<<"-";
                cout<<endl;
            }
        }
    }

    void board::write_state(char* state){
    this->grid=state;
    }

    char board::toggle_player(){//zmiana gracza
        if(player=='X')
            player='O';
        else
            player='X';
        return player;
        }



    bool board::move(int index){//ruch gracza
        moves--;
        if(grid[index]==' '){
            grid[index]=player;
            toggle_player();
            return false;
        }
        else
            return true;
    }

    bool board::possible_move(){//sprawdzanie zapelnienia planszy
        if(moves!=0)
            return true;
        else{
            cout<<"Remis\n";
            return false;
        }
    }

    bool board::win(){//sprawdzanie czy jest sytuacja wygranej
        int step_tab[]={1, size, size+1, size-1};//kroki w bok, kroki w dol, kroki na ukos \ i /

        for(int i=1;i<=size*size-2;i++){//koniec sprawdzania dla ostatniego rzedu o dlugosci 3
                if( grid[i]!=' '){
                    for(int j=0;j<4;j++){//sprawdzanie w kazdym z trzech kierunkow
                    /*1.Przy sprawdzaniu w bok, nastepny element nie moze byc w nastepnym wierszu
                    */

                    if( ((j==0) && ( (i-i%size)==(i+elements_in_line-i%size) || (i+elements_in_line-1)%size==0)  ) ||
                       ( (j==2) && (i%size<=elements_in_line) && (i%size>0) ) ||
                       ( (j==3) && ((i%size>=elements_in_line) || (i%size==0)) ) ||
                       (j==1)){

                        if(grid[i]==grid[i+step_tab[j]]){//jesli dwa sasiadujace pola maja taki sam znak
                            int step=step_tab[j];//pomocnicza zmienna kroku
                            int h1=i+step;//pomocnicza zmienna pozycji
                            int h2=2;//pomocnicza zmienna reprezentujaca dlugosc napotkanej linii
                            while(1){
                                if(grid[h1]==grid[h1+step]){
                                    h2++;
                                    h1+=step;
                                    if(h2==elements_in_line){
                                        winner=toggle_player();
                                        return false;
                                    }
                                }
                                else
                                    break;

                            }

                        }
                    }
                }
            }
        }
        return true;
    }
