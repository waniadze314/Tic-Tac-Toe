/*Gra w kolko i krzyzyk. Na poczatku nalezy wybrac kto ma zaczac, czlowiek czy komputer. Nastepnie wykonywany jest domyslny poczatkowy ruch i generowane jest drzewo gry dla okreslonego stanu*/
#define DEPTH 5//glebokos przeszukiwania
#include "board.hpp"
#include "minmax_algorithm.hpp"
void init_game(){
std::cout<<"Podaj rozmiar planszy (minimalnie 3x3): ";
std::cin>>board::size;
std::cout<<"Podaj liczbe elementow w linii (minimalnie 3): ";
std::cin>>board::elements_in_line;
}
int main(){
//Ustawienia poczatkowe
int size, player_index, computer_index, line, player_one/*, computer_move*/;
init_game();
board* game_board = new board();
std::cout<<"Kto zaczyna (\"O\"), czlowiek(1), czy Komputer(2): ";
std::cin>>player_one;
system("CLS");
game_board->print();
//Procedura startowa realizujaca pierwszy krok komputera w celu zmniejszenia drzewa przeszukiwan
switch(player_one){
    case 1: //zaczyna czlowiek
        std::cout<<"Twoj ruch: ";
        std::cin>>player_index;
        while(game_board->move(player_index)){//petla wykonuje sie jesli wybrane pole jest juz zajete
            std::cout<<"To pole jest juz zajete, wybierz inne: ";
            std::cin>>player_index;
        }
        system("CLS");
        game_board->print();
        //pierwszy ruch komputera
        if(player_index==(size*size)/2+size/2){
            game_board->move(player_index-size-1);
            system("CLS");
            game_board->print();
            break;
        }
        else{
            game_board->move((size*size)/2+size/2);
            system("CLS");
            game_board->print();
            break;
        }
    case 2: //zaczyna komputer
        game_board->move((size*size)/2+size/2);
        system("CLS");
        game_board->print();
        break;
    default:
        break;
}
//glowna petla gry
while(1){
    //ruch gracza
    std::cout<<"Twoj ruch: ";
    std::cin>>player_index;
    while(game_board->move(player_index)){//petla wykonuje sie jesli wybrane pole jest juz zajete
        std::cout<<"To pole jest juz zajete, wybierz inne: ";
        std::cin>>player_index;
    }
    system("CLS");
    game_board->print();
    if(!game_board->win())
        break;
    else if(!game_board->possible_move())
        break;
    //ruch komputera
    //Funkcja wyznaczajaca ruch
    computer_index=best_move(B);
    game_board->move(computer_index);
    system("CLS");
    game_board->print();

    std::cout<<"Komputer ruszyl na pozycje "<<computer_index<<std::endl;
    if(!game_board->win())
        break;
    else if(!game_board->possible_move())
        break;

}
if(game_board->win())
    std::cout<<"Gracz "<<game_board->get_winner()<<" wygral\n";
return 0;
}

void player_start(){

}

void computer_start(){
    
}