#ifndef INPUT_MANAGER_H__


// ŒöŠJŠÖ”éŒ¾
void InputMng_Init(void);
void InputMng_Updata(void);
bool GetInputKey(int key);
bool GetInputKeyDown(int key);
bool GetInputMouse(int key);
bool GetInputMouseDown(int key);
int GetMouseX(void);
int GetMouseY(void);

#endif // !INPUT_MANAGER_H__