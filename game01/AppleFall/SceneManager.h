#ifndef SCENE_MANAGER_H__
#define	SCENE_MANAGER_H__

enum class E_GAME_MODE {
	OPENING, TITLE, GINIT, RANKING, HELP, GEND, GMAIN, GOVER, INRANK, EXIT = 99
};

int SceneMng_Init(void);
void SceneMng_Updata(void);
E_GAME_MODE Get_SceneMng_Now(void);
void Set_SceneMng_Next(E_GAME_MODE scene);

#endif // !SCENE_MANAGER_H__ 