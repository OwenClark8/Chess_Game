#ifndef DEFSDEF
#define DEFSDEF

#include <set>
#include <utility>
#include <map>
#include <vector>
#include <memory>
#include <list>

enum class Letter{A, B, C, D, E, F, G, H};
enum class Number{One, Two, Three, Four, Five, Six, Seven, Eight};

Letter& operator++(Letter& l);

Letter operator+(const Letter& l, int i);

Letter operator-(const Letter& l, int i);

Letter& operator--(Letter& l);

Number& operator++(Number& l);

Number operator+(const Number& l, int i);

Number operator-(const Number& l, int i);

Number& operator--(Number& l);

//using Number = std::set<int>{1, 2, 3 ,4 ,5 ,6 ,7 ,8};
enum class Piece{Pawn, Knight, Queen,  Bishop, Rook, King, Empty};
enum class Colour{White, Black};

using Location = std::pair<Letter, Number>; 
using PieceType = std::pair<Colour, Piece>;

// template<typename T, typename... Ts>
// std::unique_ptr<T> make_unique(Ts&&... params)
// {
// 	return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
// }

#endif