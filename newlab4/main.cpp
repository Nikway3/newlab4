#include "zxc.h"

int main() {
    auto* tr1 = new Equilateral_Triangle();
    vector<Tmp_figure*> figures;
    cout << tr1->classname() << endl;
    tr1->initFromDialog();
    figures.push_back((Tmp_figure*)tr1);
    cout << "Square: " << figures[0]->square() << endl;
    cout << "Perimeter: " << figures[0]->perimeter() << endl;
    cout << "Size: " << figures[0]->size() << endl;
    figures[0]->draw();
    auto* tr2 = new Ellipse();
    cout << tr2->classname() << endl;
    tr2->initFromDialog();
    figures.push_back((Tmp_figure*)tr2);
    cout << "Square: " << figures[1]->square() << endl;
    cout << "Perimeter: " << figures[1]->perimeter() << endl;
    cout << "Size: " << figures[1]->size() << endl;
    figures[1]->draw();
    return 0;
}