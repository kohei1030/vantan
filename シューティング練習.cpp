//
// ミニゲーム雛形
//

#include "appEnv.hpp"


// アプリのウインドウサイズ
enum Window {
  WIDTH  = 900,
  HEIGHT = 400
};

void hit_decision(int& x1,int& x2, int& y1, int& y2, int& enemy_hp){
	if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < 50*50){
		enemy_hp -= 1;
	}
}



// 
// メインプログラム
// 
int main() {
  // アプリウインドウの準備
  AppEnv app_env(Window::WIDTH, Window::HEIGHT);
  Texture main_image("res/main.png");
  Texture fire_image("res/fire.png");
  Texture enemy_image("res/enemy.png");
  Texture BG_image("res/BG.png");
  Texture start_image("res/start.png");

  // メインループ
  while (1) {
    // ウィンドウが閉じられたらアプリを終了
    if (!app_env.isOpen()) return 0;

    // 描画準備
    app_env.setupDraw();

	int BG_x = 0;

	int vy = 0, UP = 0, DOWN = 0;

	int enemy_hp = 2, enemy_hp2 = 2, enemy_hp3 = 2, enemy_hp4 = 2, enemy_vx = 0;

	int fire_vx = 0, fire_vy = 0, fire_vx2 = -176, fire_vy2 = 0, fire_vx3 = -176 * 2, fire_vy3 = 0,
		fire_vx4 = -176 * 3, fire_vy4 = 0, fire_vx5 = -176 * 4, fire_vy5 = 0;

	int fire_x, fire_y, fire_x2, fire_y2, fire_x3, fire_y3, fire_x4, fire_y4, fire_x5, fire_y5, enemy_x, enemy_y,
		enemy_x2, enemy_y2, enemy_x3, enemy_y3, enemy_x4, enemy_y4;

	int start = -120, turn = 1, point_turn = 1, point_turn2 = 1, point_turn3 = 1, point_turn4 = 1, point = 0, point_2 = 0;

	while (1) {
		// ウィンドウが閉じられたらアプリを終了
		if (!app_env.isOpen()) return 0;

		// 描画準備
		app_env.setupDraw();

		//背景表示
		drawTextureBox(-WIDTH / 2, -HEIGHT / 2, 900, 400, 0 + BG_x, 0, 900, 400,
			BG_image,
			Color(1, 1, 1));
		BG_x += 10;

		//自機表示
		drawTextureBox(-WIDTH / 2, -128 / 2 + vy, 128, 128, 0, 0, 128, 128,
			main_image,
			Color(1, 1, 1));

		//自機操作
		//上昇
		if (app_env.isPushKey(GLFW_KEY_UP)){
				UP = 1;
		}
		if (app_env.isPullKey(GLFW_KEY_UP)){
			UP = 0;
		}
		if (UP){
			if (vy < HEIGHT / 2 - 128 / 2){
				vy += 3;
			}
		}
		//下降
		if (app_env.isPushKey(GLFW_KEY_DOWN)){
			DOWN = 1;
		}
		if (app_env.isPullKey(GLFW_KEY_DOWN)){
			DOWN = 0;
		}
		if (DOWN){
			if (vy > -HEIGHT / 2 + 128 / 2){
				vy -= 3;
			}
		}

		if (start > 0){
			//火の玉
			drawTextureBox(-WIDTH / 2 + 128 + fire_vx, -128 / 2 + fire_vy + 64 / 2, 64, 64, 0, 0, 64, 64,
				fire_image,
				Color(1, 1, 1));
			if (fire_vx > 900){
				fire_vy = vy;
				fire_vx = 0;
			}
			fire_vx += 8;
			int  hit_firex = -WIDTH / 2 + 128 + fire_vx;

			//火の玉2
			if (fire_vx2 >= 0){
				if (fire_vx2 == 0){
					fire_vy2 = vy;
				}
				drawTextureBox(-WIDTH / 2 + 128 + fire_vx2, -128 / 2 + fire_vy2 + 64 / 2, 64, 64, 0, 0, 64, 64,
					fire_image,
					Color(1, 1, 1));
				if (fire_vx2 > 900){
					fire_vy2 = vy;
					fire_vx2 = 0;
				}
			}
			fire_vx2 += 8;

			//火の玉3
			if (fire_vx3 >= 0){
				if (fire_vx3 == 0){
					fire_vy3 = vy;
				}
				drawTextureBox(-WIDTH / 2 + 128 + fire_vx3, -128 / 2 + fire_vy3 + 64 / 2, 64, 64, 0, 0, 64, 64,
					fire_image,
					Color(1, 1, 1));
				if (fire_vx3 > 900){
					fire_vy3 = vy;
					fire_vx3 = 0;
				}
			}
			fire_vx3 += 8;

			//火の玉4
			if (fire_vx4 >= 0){
				if (fire_vx4 == 0){
					fire_vy4 = vy;
				}
				drawTextureBox(-WIDTH / 2 + 128 + fire_vx4, -128 / 2 + fire_vy4 + 64 / 2, 64, 64, 0, 0, 64, 64,
					fire_image,
					Color(1, 1, 1));
				if (fire_vx4 > 900){
					fire_vy4 = vy;
					fire_vx4 = 0;
				}
			}
			fire_vx4 += 8;

			//火の玉5
			if (fire_vx5 >= 0){
				if (fire_vx5 == 0){
					fire_vy5 = vy;
				}
				drawTextureBox(-WIDTH / 2 + 128 + fire_vx5, -128 / 2 + fire_vy5 + 64 / 2, 64, 64, 0, 0, 64, 64,
					fire_image,
					Color(1, 1, 1));
				if (fire_vx5 > 900){
					fire_vy5 = vy;
					fire_vx5 = 0;
				}
			}
			fire_vx5 += 8;
		}

			//敵表示
			if (enemy_hp > 0){
				drawTextureBox(WIDTH / 2 + enemy_vx, 100, 128, 128, 0, 0, 128, 128,
					enemy_image,
					Color(1, 1, 1));
			}

			//敵表示2
			if (enemy_hp2 > 0){
				drawTextureBox(WIDTH / 2 + enemy_vx, 0, 128, 128, 0, 0, 128, 128,
					enemy_image,
					Color(1, 1, 1));
			}

			//敵表示3
			if (enemy_hp3 > 0){
				drawTextureBox(WIDTH / 2 + enemy_vx, -100, 128, 128, 0, 0, 128, 128,
					enemy_image,
					Color(1, 1, 1));
			}

			//敵表示4
			if (enemy_hp4 > 0){
				drawTextureBox(WIDTH / 2 + enemy_vx, -200, 128, 128, 0, 0, 128, 128,
					enemy_image,
					Color(1, 1, 1));
			}
			if (start > 0){
				enemy_vx -= 3;
			}

			//火と敵のあたり判定

			fire_x = -WIDTH / 2 + 128 + fire_vx;
			fire_x2 = -WIDTH / 2 + 128 + fire_vx2;
			fire_x3 = -WIDTH / 2 + 128 + fire_vx3;
			fire_x4 = -WIDTH / 2 + 128 + fire_vx4;
			fire_x5 = -WIDTH / 2 + 128 + fire_vx5;
			fire_y = -128 / 2 + fire_vy + 64 / 2;
			fire_y2 = -128 / 2 + fire_vy2 + 64 / 2;
			fire_y3 = -128 / 2 + fire_vy3 + 64 / 2;
			fire_y4 = -128 / 2 + fire_vy4 + 64 / 2;
			fire_y5 = -128 / 2 + fire_vy5 + 64 / 2;
			enemy_x = WIDTH / 2 + enemy_vx;
			enemy_x2 = WIDTH / 2 + enemy_vx;
			enemy_x3 = WIDTH / 2 + enemy_vx;
			enemy_x4 = WIDTH / 2 + enemy_vx;
			enemy_y = 100;
			enemy_y2 = 0;
			enemy_y3 = -100;
			enemy_y4 = -200;

			if (start > 0){
				hit_decision(fire_x, enemy_x, fire_y, enemy_y, enemy_hp);
				hit_decision(fire_x2, enemy_x, fire_y2, enemy_y, enemy_hp);
				hit_decision(fire_x3, enemy_x, fire_y3, enemy_y, enemy_hp);
				hit_decision(fire_x4, enemy_x, fire_y4, enemy_y, enemy_hp);
				hit_decision(fire_x5, enemy_x, fire_y5, enemy_y, enemy_hp);

				hit_decision(fire_x, enemy_x2, fire_y, enemy_y2, enemy_hp2);
				hit_decision(fire_x2, enemy_x2, fire_y2, enemy_y2, enemy_hp2);
				hit_decision(fire_x3, enemy_x2, fire_y3, enemy_y2, enemy_hp2);
				hit_decision(fire_x4, enemy_x2, fire_y4, enemy_y2, enemy_hp2);
				hit_decision(fire_x5, enemy_x2, fire_y5, enemy_y2, enemy_hp2);

				hit_decision(fire_x, enemy_x3, fire_y, enemy_y3, enemy_hp3);
				hit_decision(fire_x2, enemy_x3, fire_y2, enemy_y3, enemy_hp3);
				hit_decision(fire_x3, enemy_x3, fire_y3, enemy_y3, enemy_hp3);
				hit_decision(fire_x4, enemy_x3, fire_y4, enemy_y3, enemy_hp3);
				hit_decision(fire_x5, enemy_x3, fire_y5, enemy_y3, enemy_hp3);

				hit_decision(fire_x, enemy_x4, fire_y, enemy_y4, enemy_hp4);
				hit_decision(fire_x2, enemy_x4, fire_y2, enemy_y4, enemy_hp4);
				hit_decision(fire_x3, enemy_x4, fire_y3, enemy_y4, enemy_hp4);
				hit_decision(fire_x4, enemy_x4, fire_y4, enemy_y4, enemy_hp4);
				hit_decision(fire_x5, enemy_x4, fire_y5, enemy_y4, enemy_hp4);
			}

			//スタート画面処理
			start++;
			if (start < 0){
				drawTextureBox(-WIDTH/2, -HEIGHT /2, 800, 900, 0, 0, 800, 900,
					start_image,
					Color(1, 1, 1));
			}

			//point
			if (enemy_hp == 0){
				if (point_turn){
					point_turn = 0;
					point++;
				}
			}

			if (enemy_hp2 == 0){
				if (point_turn2){
					point_turn2 = 0;
					point++;
				}
			}

			if (enemy_hp3 == 0){
				if (point_turn3){
					point_turn3 = 0;
					point++;
				}
			}

			if (enemy_hp4 == 0){
				if (point_turn4){
					point_turn4 = 0;
					point++;
				}
			}

			//point表示
			point_2 = point ;
			for (point_2; point_2 > 0; point_2 -= 1){
				int point_x = point_2 * 21;
				drawFillCircle(-WIDTH / 2 + point_x, -HEIGHT / 2 + 30, 10, 10, 300, 
					Color(1, 1, 0));
				point_x -= 10;
			}

			if (enemy_vx == 3 * 300){
				turn++;
				point_turn = 1;
				point_turn2 = 1;
				point_turn3 = 1;
				point_turn4 = 1;
			}

		// 画面を更新
		app_env.update();
	}
    
    
    // 画面を更新
    app_env.update();
  }

  // アプリ終了
}
