#include "CUI.h"

int main(int argc, char **argv)
{
  MineTable mt;
  UI &ui = *(new CUI());

  ui.initializing(mt);

  while (!ui.isQuit()) // this is the role of MineTable, so must change this.
  {
    ui.fillBuffer(mt);
    ui.drawBuffer();
  }
}