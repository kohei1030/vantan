//
// ミニゲーム雛形
//

#include "appEnv.hpp"
#include <windows.h>
#include <time.h>

// アプリのウインドウサイズ
enum Window {
	WIDTH = 800,
	HEIGHT = 502
};

int i = 30, HP1 = 100, HP2 = 100, HP3 = 100, HP4 = 100, waiban_HP = 1000, t = 1, w = 0, t1 = 1,
t2 = 2, t3 = 3, t4 = 4, t5 = 5, t6 = 6, t7 = 7, t8 = 8, a = 0, s = 0, b = 0, b1_1 = 0, b1_2 = 0,
b1_3 = 0, b1_4 = 0, b2 = 0, b3 = 0, e = 0, x1 = 0, x2 = 0, x3 = 0, x4 = 0, BOSS = 4, dead = 0;

//こうげき関数
void attack(int& turn_plus1, int& xx, const Texture& texture, int& turn, Vec2f pos, bool left_click, int& BOSS_HP, int damage){
	if (t == turn_plus1 && a == 1){
		if (xx == 50){
			Sleep(500);
			drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
				texture,
				Color(1, 1, 1));
			xx =0;
		}

		a = 0;
		t++;
	}
	if (a == 0){
		if (t == turn){
			if (pos.x() > -400 + 62){
				if (pos.x() < -400 + 173){
					if (pos.y() < -135){
						if (pos.y() > -161){
							if (left_click){
								BOSS_HP -= damage;
								a = 1;
								t++;
								xx = 50;
							}
						}
					}
				}
			}
		}
	}
}
//ぼうぎょ
void defense(int& turn_plus1, int& xx, const Texture& texture, int& turn, Vec2f pos, bool left_click, int& HP, int& b1){
	if (t == turn_plus1 && b1 == 1){
		if (xx == 50){
			Sleep(500);
			drawTextureBox(-400, 250 - 128, 128, 128, 0, 0, 128, 128,
				texture,
				Color(1, 1, 1));
			xx = 0;
		}

		t++;
	}
	if (b == 0){
		if (t == turn){
			if (pos.x() > -400 + 244){
				if (pos.x() < -400 + 360){
					if (pos.y() < -135){
						if (pos.y() > -161){
							if (left_click){
								b3 = 1;
								b1 = 1;
								b = 1;
								t++;
								xx = 50;
							}
						}
					}
				}
			}
		}
	}
	if (b3 == 1){
		b2 = HP;
		b3 = 0;
	}

	if (b1 == 1){
		HP = b2;
	}
	if (t == 1){
		b1 = 0;
		b = 0;
	}
}

//にげる

void escape(const Texture& texture, int& turn, Vec2f pos, bool left_click){
	if (e == 0){
		if (t == turn){
			if (pos.x() > -400 + 244){
				if (pos.x() < -400 + 330){
					if (pos.y() < 250 - 422){
						if (pos.y() > 250 - 450){
							if (left_click){
								e = 1;
							}
						}
					}
				}
			}
		}
	}
	if (e == 1){
		drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
			texture,
			Color(1, 1, 1));
		if (left_click){
			if (pos.x() > -400 + 241){
				if (pos.x() < -400 + 279){
					if (pos.y() < 250 - 317){
						if (pos.y() > 250 - 334){
							e = 2;
						}
					}
				}
			}
		}
		if (left_click){
			if (pos.x() > -400 + 321){
				if (pos.x() < -400 + 379){
					if (pos.y() < 250 - 317){
						if (pos.y() > 250 - 334){
							e = 0;
						}
					}
				}
			}
		}
	}
}

//とくぎ(warrior)
void w_skill(int& turn_plus1, int& xx, const Texture& texture, const Texture& texture2, int& turn, Vec2f pos, bool left_click, int& BOSS_HP, int damage){
	if (t == turn_plus1 && s == 1){
		if (xx == 50){
			Sleep(500);

			drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
				texture,
				Color(1, 1, 1));

			drawTextureBox(10, -100, 256, 256, 0, 0, 256, 256,
				texture2,
				Color(1, 1, 1));
			xx = 0;
		}
		s = 0;
		t++;
	}
	if (s == 0){
		if (t == turn){
			if (pos.x() > -400 + 62){
				if (pos.x() < -400 + 143){
					if (pos.y() < 250 - 422){
						if (pos.y() > 250 - 450){
							if (left_click){
								BOSS_HP -= damage;
								s = 1;
								t++;
								xx = 50;
							}
						}
					}
				}
			}
		}
	}
}

// 
// メインプログラム
// 
int main() {
	// アプリウインドウの準備
	AppEnv app_env(Window::WIDTH, Window::HEIGHT);
	// メインループ
	while (1) {
		// ウィンドウが閉じられたらアプリを終了
		if (!app_env.isOpen()) return 0;

		// 描画準備
		app_env.setupDraw();
		//タイトル
		{
			while (1){
				// ウィンドウが閉じられたらアプリを終了
				if (!app_env.isOpen()) return 0;
				
				//コンティニュー用
				HP1 = 100; HP2 = 100; HP3 = 100; HP4 = 100; waiban_HP = 1000;
				t = 1, dead = 0;
				
				Texture title_image("res/title.png");
				Texture CLICK_TO_START_image("res/CLICK TO START.png");
				//タイトル画面
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					title_image,
					Color(1, 1, 1));
				//ENTER TO START
				i++;
				int ii;
				ii = (i / 6) % 2;
				if (ii){
					drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
						CLICK_TO_START_image,
						Color(1, 1, 1));
				}
				if (app_env.isPushButton(Mouse::LEFT))  break;

				// 画面を更新
				app_env.update();
			}
			//入力のフラッシュ
			app_env.flushInput();
		}
		//ゲーム本編
		//画面
		Texture BG_1("res/BG_1.png");
		Texture BOSS_1("res/waiba-n.png");
		Texture warrior_image("res/warrior.png");
		Texture archer_image("res/archer.png");
		Texture magician_image("res/magician.png");
		Texture healer_image("res/healer.png");
		Texture thief_image("res/thief.png");
		Texture dancer_image("res/dancer.png");
		Texture samurai_image("res/samurai.png");
		Texture coffin_image("res/coffin.png");
		Texture command_image("res/command.png");
		Texture effect_zan_image("res/effect_zan.png");
		Texture effect_zan2_image("res/effect_zan2.png");
		Texture effect_defense_image("res/defense.png");
		Texture escape_image("res/escape.png");
		Texture gameover_image("res/gameover.png");
		{
			{
				while (1){
					// ウィンドウが閉じられたらアプリを終了
					if (!app_env.isOpen()) return 0;

					if (e == 2) break;

					Vec2f pos = app_env.mousePosition();
					bool left_click = app_env.isPushButton(Mouse::LEFT);
					bool right_click = app_env.isPushButton(Mouse::RIGHT);

					//背景
					drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
						BG_1,
						Color(1, 1, 1));
					//コマンド
					drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
						command_image,
						Color(1, 1, 1));


					//テストダメージ
					if (right_click){
						HP1 -= 12;
						HP2-= 20;
						HP3 -= 50;
						HP4 -= 50;
					}

					//敵
					if (waiban_HP > 0){
						drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
							BOSS_1,
							Color(1, 1, 1));
						drawBox(60, 110, 200, 4, 2, Color(0, 0, 0));
						drawFillBox(60, 110, waiban_HP / 5, 4, Color(0.2, 0.8, 0.2));
					}
					//敵の動き
					time_t date;
					srand(time(&date));
					if (t == 9){
						BOSS = rand()%4;
						if (HP1 > 0){
							if (BOSS == 0){
								HP1 -= 60;
								BOSS = 4;
								t = 1;
							}
						}
						if (HP2 > 0){
							if (BOSS == 1){
								HP2 -= 60;
								BOSS = 4;
								t = 1;
							}
						}
						if (HP3 > 0){
							if (BOSS == 2){
								HP3 -= 60;
								BOSS = 4;
								t = 1;
							}
						}
						if (HP4 > 0){
							if (BOSS == 3){
								HP4 -= 60;
								BOSS = 4;
								t = 1;
							}
						}
					}

					//プレイヤー1
					if (HP1 > 0){
						//コマンド系
						attack(t2, x1, effect_zan_image, t1, pos, left_click, waiban_HP, 90);
						w_skill(t2, x1, effect_zan_image, effect_zan2_image, t1, pos, left_click, waiban_HP, 150);
						defense(t2, x1, effect_defense_image, t1, pos, left_click, HP1, b1_1);
						escape(escape_image, t1, pos, left_click);
						//キャラ表示
						drawTextureBox(-400 + 100 * 2 + x1, 250 - 125, 128, 128, 0, 0, 128, 128,
							warrior_image,
							Color(1, 1, 1));
					}
					else{
						drawTextureBox(-400 + 100 * 2, 250 - 125, 128, 128, 0, 0, 128, 128,
							coffin_image,
							Color(1, 1, 1));
						if (t == 1){
							t += 2;
						}
					}
					drawBox(-400 + 100 * 2, 250 - 125, 100, 4, 2, Color(0, 0, 0));
					drawFillBox(-400 + 100 * 2, 250 - 125, HP1, 4, Color(0.2, 0.8, 0.2));


					//プレイヤー2
					if (HP2 > 0){
						
						//コマンド系
						attack(t4, x2, effect_zan_image, t3, pos, left_click, waiban_HP, 90);
						w_skill(t4, x2, effect_zan_image, effect_zan2_image, t3, pos, left_click, waiban_HP, 150);
						defense(t4, x2, effect_defense_image, t3, pos, left_click, HP2, b1_2);
						escape(escape_image, t3, pos, left_click);

						//キャラ表示
						drawTextureBox(-400 + 100 * 2 + x2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
							archer_image,
							Color(1, 1, 1));
					}
					else{
						drawTextureBox(-400 + 100 * 2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
							coffin_image,
							Color(1, 1, 1));
						if (t == 3){
							t += 2;
						}
					}
					drawBox(-400 + 100 * 2, 250 - 125 * 2, 100, 4, 2, Color(0, 0, 0));
					drawFillBox(-400 + 100 * 2, 250 - 125 * 2, HP2, 4, Color(0.2, 0.8, 0.2));

					//プレイヤー3
					if (HP3 > 0){
						
						//コマンド系
						attack(t6, x3, effect_zan_image, t5, pos, left_click, waiban_HP, 90);
						w_skill(t6, x3, effect_zan_image, effect_zan2_image, t5, pos, left_click, waiban_HP, 150);
						defense(t6, x3, effect_defense_image, t5, pos, left_click, HP3, b1_3);
						escape(escape_image, t5, pos, left_click);

						//キャラ表示
						drawTextureBox(-400 + 100 * 1 + x3, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
							magician_image,
							Color(1, 1, 1));
					
					}
					else{
						drawTextureBox(-400 + 100 * 1, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
							coffin_image,
							Color(1, 1, 1));
						if (t == 5){
							t += 2;
						}
					}
					drawBox(-400 + 100 * 1, 250 - 125 * 1 - 50, 100, 4, 2, Color(0, 0, 0));
					drawFillBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP3, 4, Color(0.2, 0.8, 0.2));


					//プレイヤー4
					if (HP4 > 0){
						
						//コマンド系
						attack(t8, x4, effect_zan_image, t7, pos, left_click, waiban_HP, 90);
						w_skill(t8, x4, effect_zan_image, effect_zan2_image, t7, pos, left_click, waiban_HP, 150);
						defense(t8, x4, effect_defense_image, t7, pos, left_click, HP4, b1_4);
						escape(escape_image, t7, pos, left_click);
						
						//キャラ表示
						drawTextureBox(-400 + 100 * 1 + x4, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
							healer_image,
							Color(1, 1, 1));
					
					}
					else{
						drawTextureBox(-400 + 100 * 1, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
							coffin_image,
							Color(1, 1, 1));
						if (t == 7){
							t += 2;
						}
					}
					drawBox(-400 + 100 * 1, 250 - 125 * 2 - 50, 100, 4, 2, Color(0, 0, 0));
					drawFillBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP4, 4, Color(0.2, 0.8, 0.2));

					if (dead == 1){
						Sleep(500);
						drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
							gameover_image,
							Color(1, 1, 1));
						if (left_click){
							break;
						}
					}
						if (HP1 <= 0 && HP2 <= 0 && HP3 <= 0 && HP4 <= 0){
							dead = 1;
						}
					
					// 画面を更新
					app_env.update();
				}
				//入力のフラッシュ
				app_env.flushInput();
			}
		}
	}
	//アプリの終了	
}