#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"


int gpc_hdl[4];
int gpc_hdl2[4];
int gpc_hdl_down[4];
int gpc_hdl_up[4];
float count = 0;
int index = 0;
tnl::Vector3 v3 = { 200, 200, 0 };
tnl::Vector3 v32 = { 300, 300, 0 };
int c = 0x0000ff;
int up = 50;
int down = 50;
int upB = 100;
int downB = 100;

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));

	LoadDivGraph("graphics/c1_anim_right.png", 4, 4, 1, 32, 48, gpc_hdl);
	LoadDivGraph("graphics/c1_anim_left.png", 4, 4, 1, 32, 48, gpc_hdl2);
	LoadDivGraph("graphics/c1_anim_down.png", 4, 4, 1, 32, 48, gpc_hdl_down);
	LoadDivGraph("graphics/c1_anim_up.png", 4, 4, 1, 32, 48, gpc_hdl_up);
}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
	tnl::Vector3 prev = v3;
	count += delta_time;
	/*DrawCircle(v3.x, v3.y, 15, 0xffff0000, true);
	DrawCircle(v32.x, v32.y, 30, c, true);*/
	DrawBoxEx(v3, up, down, false, 0xffff0000);
	DrawBoxEx(v32, upB, downB, false, c);

	if (tnl::IsIntersectRectToCorrectPosition(v3, prev, up, down, v32, upB, downB))
	{
		c = 0xffff0000;
	}
	else
	{
		c = 0x0000ff;
	}

	/*if (tnl::IsIntersectSphere(v32, 30, v3, 15))
	{
		c = 0xffff0000;
		tnl::Vector3 a = (v32 + v3) / 2;
		tnl::Vector3 a2 = tnl::Vector3::Normalize(v32 - a);
		tnl::Vector3 a3 = tnl::Vector3::Normalize(v3 - a);
		v3 = a + (a3 * (15 + 30) / 2);
		v32 = a + (a2 * (15 + 30) / 2);
	}
	else
	{
		c = 0x0000ff;
	}*/

	if (tnl::Input::IsKeyDown(eKeys::KB_D))
	{
		v3.x += 2;
		DrawRotaGraph(v3.x, v3.y, 1.0f, 0, gpc_hdl[index], true);
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_A))
	{
		v3.x -= 2;
		DrawRotaGraph(v3.x, v3.y, 1.0f, 0, gpc_hdl2[index], true);
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_S))
	{
		v3.y += 2;
		DrawRotaGraph(v3.x, v3.y, 1.0f, 0, gpc_hdl_down[index], true);
	}
	else if (tnl::Input::IsKeyDown(eKeys::KB_W))
	{
		v3.y -= 2;
		DrawRotaGraph(v3.x, v3.y, 1.0f, 0, gpc_hdl_up[index], true);
	}
	else
	{
		DrawRotaGraph(v3.x, v3.y, 1.0f, 0, gpc_hdl_down[0], true);
	}

	if (count >= 0.18f)
	{
		index++;
		count = 0;
	}

	if (index > 3)
	{
		index = 0;
	}
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {

}
