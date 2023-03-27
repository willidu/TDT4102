#include "MinesweeperWindow.h"
#include <iostream>
#include "Tile.h"
#include <random>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines},
	text{{100, 300}, 110, 100, "Play game"}
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}
	std::random_device r;
	std::default_random_engine e(r());
	std::uniform_int_distribution<int> uniform(0, width*height);

	for (int i = 0; i < mines; i++)  // TODO
	{
		int index = uniform(e);
		tiles.at(index)->setIsMine(true);
	}
	add(text);
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	std::shared_ptr<Tile> tile_ptr = this->at(xy);
	
	if (tile_ptr->getState() == Cell::closed)
	{
		tile_ptr->open();

		if (!(tile_ptr->getIsMine()))
		{
			openedCellsWithoutMines++;
			auto otherPoints = adjacentPoints(xy);
			int numMines = countMines(otherPoints);

			// Setter tekst
			if (numMines)
			{
				tile_ptr->setAdjMines(numMines);
			}
			// Åpner felt rundt
			else
			{
				for (Point& p : otherPoints)
				{
					openTile(p);
				}
			}
		}
	}

	if (tile_ptr->getIsMine())
	{
		text.setText("You lost!");
	} 
	else if (openedCellsWithoutMines == width*height - mines)
	{
		text.setText("You won!");
	}
}

void MinesweeperWindow::flagTile(Point xy)
{
	std::shared_ptr<Tile> tile_ptr = this->at(xy);
	if (!(tile_ptr->getState() == Cell::open))
	{
		tile_ptr->flag();
	}
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	
	Point xy{this->get_mouse_coordinates()};
	//std::cout << xy.x << " " << xy.y <<": " << xy.x / (cellSize) + (xy.y / cellSize) * width<<"\n";

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}

int MinesweeperWindow::countMines(std::vector<Point> coords) const
{
	int count {0};

	for (const Point& p : coords)
	{
		std::shared_ptr<Tile> tile_ptr = this->at(p);
		if (tile_ptr->getIsMine())
		{
			count++;
		}
	}

	return count;
}