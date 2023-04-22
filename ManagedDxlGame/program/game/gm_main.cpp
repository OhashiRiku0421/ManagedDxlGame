#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "Cat.h"

Cat cat;

int numx = 100;
int numy = 100;
int speed = 3;
tnl::Vector3 pos = { 0, 0, 0 };


//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart(){
	srand(time(0));
	cat.cat_ = LoadGraph("graphics/neko.png");

}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
	cat.update(delta_time);
	cat.graphicupdate(delta_time);
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {

}
