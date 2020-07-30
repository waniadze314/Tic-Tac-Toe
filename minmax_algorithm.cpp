#include "minmax_algorithm.hpp"
#define DEPTH 5//maksymalna glebokosc wywolania rekurencyjnego
#define WIN_DEPTH DEPTH//glebokosc natychmiastowej wygranej
#define LOSE_DEPTH DEPTH-1//glebokosc natychmiastowej przegranej
//Funkcja wywolywana rekurencyjnie, badajaca wszystkie sciezki za pomoca strategii minimax, dla jakiego posuniecia komputer zmaksymalizuje wygrana
void minimax(board state, int depth, char sign, int &val){//stan gry, glebokosc przeszukiwania, znak odpowiadajacy komputerowi, zmienna

    if(depth==0)
        return;
    else{
        if(state.win()){//jesli stan nie oznacza wygranej
            for(int i=1;i<=state.size_of();i++){
                board current_state(state);//stan wyjsciowy jest kopowany, bo przy kazdej iteracji potrzeba analizy stanu przed wykonaniem ruchu
                if(current_state.grid_state(i)==' '){
                    current_state.move(i);//jesli pole jest wolne -> wykonaj ruch na to pole i sprawdz sciezke
                    minimax(current_state, depth-1, sign, val);
                }
            }
        }
        else if(state.winner_is()==sign && depth==WIN_DEPTH)
            val+=10000;
        else if(state.winner_is()!=sign && depth==LOSE_DEPTH)
            val-=10000;
        else if(state.winner_is()==sign)
            val+=10;
        else
            val-=10;
    }
}

int best_move(board state){
    int index=0; //najlepsze pole do wykonania ruchu, domyslnie poza plansza, kod bledu
    int greatest_value = -32000; //najwieksza znaleziona wartosc
    char current_player=state.player_is();//aktualny znak komputera, potrzebny w celu ró¿nicowania wyników funkcji minimax
    for(int i=1;i<=state.size_of();i++){
        if(state.grid_state(i)==' '){
            board temp_state(state);
            temp_state.move(i);
            int temp=0;//zmienna tymczasowa przechowujaca wartosc danego ruchu
            minimax(temp_state, DEPTH, current_player, temp);
            if(temp>=greatest_value){
                greatest_value=temp;
                index=i;
            }

        }
    }
        return index;
}
