#pragma once

#include "AnimationWindow.h"
#include "widgets/Button.h"

enum class Cell {
	closed, open, flagged
}; 

class Tile : public TDT4102::Button
{
public:
	Tile(TDT4102::Point pos, int size);

	void open();
	void flag();

	Cell getState() const { return state; };
	bool getIsMine() const { return m_isMine; };
	void setIsMine(bool state) { m_isMine = state; };
	void setAdjMines(int n);

private:
	Cell state = Cell::closed;
	void set_label(std::string s) { this->setLabel(s);}
	void set_label_color(TDT4102::Color c) {this->setLabelColor(c);}
	bool m_isMine {false};
};
