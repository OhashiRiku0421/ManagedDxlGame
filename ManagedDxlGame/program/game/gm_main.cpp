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
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart(){
	srand(time(0));
	cat.cat_ = LoadGraph("graphics/neko.png");

}

//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time) {
	cat.update(delta_time);
	cat.graphicupdate(delta_time);
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {

}
